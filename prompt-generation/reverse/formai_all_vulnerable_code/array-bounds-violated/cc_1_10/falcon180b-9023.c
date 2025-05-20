//Falcon-180B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initBoard(char board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        //Check rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= '.'){
            return 1;
        }
        //Check columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i]!= '.'){
            return 1;
        }
    }
    //Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= '.'){
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= '.'){
        return 1;
    }
    return 0;
}

int main(){
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);
    int player = 1;
    while(player!= 3){
        printBoard(board);
        int x, y;
        printf("Player %d's turn\n", player);
        scanf("%d %d", &x, &y);
        if(board[x][y] == '.'){
            board[x][y] = (player == 1)? 'X' : 'O';
            player++;
        }
        else{
            printf("Invalid move\n");
        }
        if(checkWin(board)){
            printf("Player %d wins!\n", player);
            break;
        }
        if(player == 3){
            printf("It's a draw.\n");
        }
    }
    return 0;
}