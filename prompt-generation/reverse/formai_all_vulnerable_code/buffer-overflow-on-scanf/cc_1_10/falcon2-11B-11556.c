//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int board[ROWS][COLS];
int turn = 0;
int player = 0;

void printBoard(int board[][COLS]) {
    for(int r=0; r<ROWS; r++) {
        for(int c=0; c<COLS; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int isFull(int board[][COLS]) {
    for(int r=0; r<ROWS; r++) {
        for(int c=0; c<COLS; c++) {
            if(board[r][c] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void printWinner(int board[][COLS]) {
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0]!= 0) {
        printf("Player %d wins!\n", board[0][0]);
    } else if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0]!= 0) {
        printf("Player %d wins!\n", board[1][0]);
    } else if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0]!= 0) {
        printf("Player %d wins!\n", board[2][0]);
    } else if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0]!= 0) {
        printf("Player %d wins!\n", board[0][0]);
    } else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1]!= 0) {
        printf("Player %d wins!\n", board[0][1]);
    } else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2]!= 0) {
        printf("Player %d wins!\n", board[0][2]);
    } else if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]!= 0) {
        printf("Player %d wins!\n", board[0][0]);
    } else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]!= 0) {
        printf("Player %d wins!\n", board[0][2]);
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 will play as X.\n");
    printf("Player 2 will play as O.\n");
    printf("Player %d will go first.\n", player);
    printBoard(board);

    while(!isFull(board)) {
        if(turn % 2 == 0) {
            printf("Player %d's turn. Select a position (0-2) to place an X:\n", player);
            scanf("%d", &board[0][0]);
            turn++;
            player = (player == 0)? 1 : 0;
            printBoard(board);
        } else {
            printf("Player %d's turn. Select a position (0-2) to place an O:\n", player);
            scanf("%d", &board[0][0]);
            turn++;
            player = (player == 0)? 1 : 0;
            printBoard(board);
        }
    }
    printWinner(board);

    return 0;
}