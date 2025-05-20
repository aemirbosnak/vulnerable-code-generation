//Falcon-180B DATASET v1.0 Category: Table Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 3
#define COLS 3

void drawBoard(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

int checkForWin(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    for(int j = 0; j < COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    int player = 1;
    while(1) {
        system("clear");
        drawBoard(board);
        printf("Player %d's turn\n", player);
        int row, col;
        scanf("%d %d", &row, &col);
        if(row < 0 || row > 2 || col < 0 || col > 2) {
            printf("Invalid move\n");
            continue;
        }
        if(board[row][col]!= 0 && board[row][col]!= player) {
            printf("Invalid move\n");
            continue;
        }
        board[row][col] = player;
        if(checkForWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = (player == 1)? 2 : 1;
    }
    return 0;
}