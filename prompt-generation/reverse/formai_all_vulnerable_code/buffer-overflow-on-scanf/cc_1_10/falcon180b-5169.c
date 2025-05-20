//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3

char board[SIZE][SIZE]; //the game board
char player = 'X'; //player 1 starts
int moves = 0; //number of moves made
int full = 0; //flag to check if game is full

void initBoard(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board[i][j] = '-';
        }
    }
}

void drawBoard(){
    printf("\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(){
    for(int i=0;i<SIZE;i++){
        if(board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return 1;
        }
    }
    for(int i=0;i<SIZE;i++){
        if(board[0][i]!= '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return 1;
        }
    }
    if(board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return 1;
    }
    if(board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return 1;
    }
    return 0;
}

int checkFull(){
    int count = 0;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(board[i][j] == '-'){
                count++;
            }
        }
    }
    if(count == 0){
        full = 1;
        return 1;
    }
    return 0;
}

int getMove(){
    int x,y;
    printf("Player %c, enter your move (row,column): ",player);
    scanf("%d%d",&x,&y);
    if(x < 1 || x > SIZE || y < 1 || y > SIZE){
        printf("Invalid move\n");
        return -1;
    }
    if(board[x-1][y-1]!= '-'){
        printf("Spot already taken\n");
        return -1;
    }
    board[x-1][y-1] = player;
    if(checkWin()){
        printf("Player %c wins!\n",player);
        return 1;
    }
    if(checkFull()){
        printf("Game full. No winner.\n");
        return 2;
    }
    player = (player == 'X')? 'O' : 'X';
    moves++;
    return 0;
}

int main(){
    srand(time(NULL));
    player = (rand() % 2)? 'X' : 'O';
    initBoard();
    while(1){
        drawBoard();
        int result = getMove();
        if(result == 1 || result == 2){
            break;
        }
    }
    return 0;
}