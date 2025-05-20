//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int numMoves = 0;
    int player = 1;
    while (numMoves < ROWS * COLS - 1) {
        printBoard(board);
        int row, col;
        printf("Player %d, enter your move (row, col): ", player);
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == '*') {
            board[row][col] = (player == 1)? 'X' : 'O';
            numMoves++;
            player = (player == 1)? 2 : 1;
        } else {
            printf("Invalid move.\n");
        }
    }

    if (player == 1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Player 1 wins!\n");
    }

    return 0;
}