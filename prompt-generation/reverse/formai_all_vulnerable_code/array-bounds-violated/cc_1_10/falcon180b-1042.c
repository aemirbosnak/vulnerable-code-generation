//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int board[SIZE][SIZE];

void initBoard() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void printBoard() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for(int i=0; i<SIZE; i++) {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return 1;
        }
        if((board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return 1;
        }
    }
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return 1;
    }
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return 1;
    }
    return 0;
}

int checkTie() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int getMove() {
    int move = 0;
    printf("Enter your move (1-9): ");
    scanf("%d", &move);
    if(move < 1 || move > 9) {
        printf("Invalid move\n");
        exit(1);
    }
    return move;
}

int main() {
    initBoard();
    int player = 1;
    int moves = 0;
    while(1) {
        printBoard();
        int move = getMove();
        int row = move/3;
        int col = move%3;
        if(board[row][col]!= 0) {
            printf("Invalid move\n");
            continue;
        }
        board[row][col] = player;
        if(checkWin()) {
            printf("Player %d wins!\n", player);
            break;
        } else if(checkTie()) {
            printf("Tie game.\n");
            break;
        }
        player = 3 - player;
        moves++;
        if(moves == 9) {
            printf("Tie game.\n");
            break;
        }
    }
    return 0;
}