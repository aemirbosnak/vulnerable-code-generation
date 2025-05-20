//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
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
    int player = 0;

    while (numMoves < ROWS * COLS) {
        printBoard(board);
        printf("Player %d's turn\n", player + 1);
        int row, col;
        if (scanf("%d %d", &row, &col)!= 2 || row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= '*') {
            printf("Invalid move\n");
            continue;
        }

        board[row][col] = (player == 0? 'X' : 'O');
        numMoves++;
        player =!player;

        if (numMoves == ROWS * COLS) {
            printf("Game over. Player %d wins!\n", player + 1);
            break;
        }
    }

    return 0;
}