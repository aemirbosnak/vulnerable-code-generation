//Falcon-180B DATASET v1.0 Category: Table Game ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 3
#define NUM_ROWS 3
#define NUM_COLS 3
#define NUM_PLAYERS 2
#define NUM_ROUNDS 5

int board[NUM_ROWS][NUM_COLS];
int player = 1;
int flag = 0;
int count = 0;

void initBoard(){
    int i, j;
    for(i=0; i<NUM_ROWS; i++){
        for(j=0; j<NUM_COLS; j++){
            board[i][j] = 0;
        }
    }
}

void drawBoard(){
    int i, j;
    for(i=0; i<NUM_ROWS; i++){
        for(j=0; j<NUM_COLS; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(){
    int i, j;
    for(i=0; i<NUM_ROWS; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0]!= 0){
            return 1;
        }
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j]!= 0){
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0){
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0){
        return 1;
    }
    return 0;
}

int checkTie(){
    int i, j;
    for(i=0; i<NUM_ROWS; i++){
        for(j=0; j<NUM_COLS; j++){
            if(board[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void playRound(){
    int x, y;
    printf("Player %d's turn\n", player);
    printf("Enter your move (row and column): ");
    scanf("%d%d", &x, &y);
    if(x < 1 || x > NUM_ROWS || y < 1 || y > NUM_COLS || board[x-1][y-1]!= 0){
        printf("Invalid move\n");
        return;
    }
    board[x-1][y-1] = player;
    drawBoard();
    if(checkWin()){
        printf("Player %d wins!\n", player);
        flag = 1;
    }
    else if(checkTie()){
        printf("Tie game.\n");
        flag = 1;
    }
    else{
        player = (player == 1)? 2 : 1;
    }
    count++;
    if(count == NUM_ROUNDS){
        flag = 1;
    }
}

int main(){
    srand(time(NULL));
    initBoard();
    while(!flag){
        playRound();
    }
    return 0;
}