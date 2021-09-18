#include <iostream>
#include<cmath>
#include <cstdlib>
#include<ctime>
using namespace std;

const int N = 5;
int grid[N][N];
int counter=0;
int arr[N];

//This function prints the grid of Tic-Tac-Toe Game as the game progresses
void print_grid() {

    cout << " __";
    for (int i = 0; i < N; cout << "_", i++);
    cout << "   \n";
    cout << "   \n";
    for (int i = 0; i < N; i++) {
        cout << "|  ";
        for (int j = 0; j < N; j++)
            if(grid[i][j]){
                if(grid[i][j]>=10){
                cout << grid[i][j] << " ";}
                else{
                    cout << grid[i][j] << "  ";
                }}
            else{
                cout << "  " << "  ";
            }
        cout << "|";
        cout << "  ";
        for (int i = 0; i < N; cout << "  ", i++);
        cout << "  \n";}
     cout << " __";
     for (int i = 0; i < N; cout << "_", i++);
     cout << "   \n";

}

bool search(int f){
    for (int i =0 ; i<N; i++){
        for (int j =0 ; j<N; j++){
            if(grid[i][j]==f){
                return true;
            }
    }}
    return false;
}

void generate_cell() {
    srand( (unsigned)time( NULL ) );
    int f=pow(N,2);
    int a = rand() % f +1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            while (search(a)){
                a = rand() % f +1;}
            grid[i][j]=a;
        }   
    }     
}

bool check_lose(time_t s1 ,time_t s2) {
    if ( s2-s1 >= 600 )
        {return true;}
    else 
       {return false ;} 
}

void Counter(int h){
    if(h==1){cout<<"B";}
    if(h==2){cout<<"B I";}
    if(h==3){cout<<"B I N";}
    if(h==4){cout<<"B I N G";}
    if(h==5){cout<<"B I N G O"<<endl;}
}

bool check_win() {
    counter=0;
    for (int i=0; i<N; i++){
            int count1=0;  int count2=0; int count3=0;

        for (int j=0; j<N; j++){
            if (grid[i][j] == 0){
                count1 += 1;
                if (count1 == N){
                    counter++;        
            }}
            if (grid[j][i] == 0){
                count3 += 1;
                if (count3 == N){
                    counter++;        
                }}
            if (grid[j][j] == 0){
                count2 += 1;
                if (count2 == N){
                    counter++;        
                    }
                }
            /*if (grid[0][N-1] == 0 && grid[N-1][0]== 0 && grid[N/2][N/2]== 0 ){
                    counter++;        
            }*/
        }
    }
    if(counter>=5){
        return true;
    }
    else{
        return false;
    }
}

bool search_arr(int f){
    for (int i =0 ; i<N; i++){
        if(arr[i]==f){
            return true;
        }
    }
    return false;
}
//This function generates pac man
void generate_arr() {
    srand( (unsigned)time( NULL ) );
    int f=pow(N,2);
    int a = rand() % f +1;
    for (int i = 0; i < N; i++)
    {
        while (search_arr(a)){
            a = rand() % f +1;}
        arr[i]=a;
    }
}

//This function checks if given position is valid or not
bool check_valid_position(int i, int j , int k ) {
    bool valid= 0<i && i<=N && 0<j && j<=N && 0<k && k<=N;
    return valid;

}

void set_sell(int i ,int j ,int k){
    if(grid[i-1][j-1]==arr[k-1]){
        grid[i-1][j-1]=0;
    }
}

//This function clears the game structures
void grid_clear() {
    for (int i =0 ; i<N; i++){
        for (int j =0 ; j<N; j++){
           grid[i][j]=0;
        }
    }
    for (int j =0 ; j<N; j++){
        arr[j]=0;
    }
    counter =0;
}

//This function reads a valid position input
void read_input(int &i, int &j , int &k ) {
    cout<<"\n";
	cout << "Enter the row index and column index: ";
	cin >> i >> j >> k;
    while (!check_valid_position(i,j,k) ) {
		cout << "Enter a valid row index and a valid column index: ";
		cin >> i >> j>> k;
	}
}
//MAIN FUNCTION
void play_game(time_t si) {
    cout << "Bingo Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";

    while (true) {
        //Prints the grid
        generate_arr();
        for(int i=0 ; i<N ; cout<<arr[i]<<" " , i++);
        cout<<"\n";
        print_grid();
        cout<<"You are in : " ;
        Counter(counter);
        time_t s2 = time(NULL);
        //Read an input position from the player
        int i , j , k;
		read_input(i , j , k);
        set_sell(i , j , k);
		if (check_lose(si,s2)){
            print_grid();
			//Announcement of the final statement
            cout << "Game over !\n";
            break;
		}
        //Check if the grid has a win state
        if (check_win()) {
            //Prints the grid
            print_grid();
			//Announcement of the final statement
            cout << "Congrats, YOU WON\n";
            cout<<"You are in : " ;
                Counter(counter);
            break;
        }

    }
}
int main() {
    while (true) {
        time_t s1 = time(NULL);
    	grid_clear();
        generate_cell();
    	play_game(s1);
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}
