#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

enum Direction{stop =0, left, right, up, down};
Direction dir;
bool game_over; 
const int height = 20;
const int width = 20;
int headx, heady, fruitx, fruity, score;
int tailLength;
int tailx[100], taily[100];

void setup(){
    game_over = false;
    dir = stop;
    headx = width/2;
    heady = height/2;
    fruitx = rand()%width;
    fruity = rand()%height;
    score = 0;
};
void draw(){
    system("cls");
    // Uper Border
    cout << "\t\t";
    for(int i = 0; i < width-8; i++){
        cout << "||";
    }
    cout << endl;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            // left border
            if(j == 0){
                cout << "\t\t||";
            }
            // snake head
            if(i == heady && j == headx){
                cout << "O";
            }
            // fruit
            else if(i == fruity && j == fruitx){
                cout << "*";
            }
            else{
                bool print = false;
                // tail
                for(int k = 0; k < tailLength; k++){
                    if(tailx[k] == j && taily[k] == i){
                        cout << "o";
                        print = true;
                    }
                }
                if(!print){
                    cout << " ";
                }
            } 
            // right border
            if(j == width-1){
                cout << "||";
            }
        }
        cout << endl;
    }
    // Lower Border
    cout << "\t\t";
    for(int i = 0; i < width-8; i++){
        cout << "||";
    }
    cout << endl;
    cout << "\t\t\tScore: " << score << endl;
}

void input();
void logic();

int main(){
    char start;
    cout<< "\t----------------------------"<<endl;
    cout<<"\t\t :Snake Game" <<endl;
    cout<< "\t----------------------------"<<endl;
    cout<< "Press 's' to Start: ";
    cin>> start;
    if(start=='s'){
       setup();
       while(!game_over){
        draw();
        // input();
        // logic();
        Sleep(30);
        // system("cls");
        game_over = true;
       }
    }
    return 0;
}

