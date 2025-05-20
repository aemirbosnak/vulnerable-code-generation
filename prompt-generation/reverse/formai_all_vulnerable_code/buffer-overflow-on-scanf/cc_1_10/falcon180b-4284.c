//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 'X';
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

    int player = 1;
    int moves = 0;
    int matches = 0;

    while (moves < ROWS * COLS) {
        printBoard(board);

        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col]!= 'X');

        printf("Player %d's turn. Enter row and column: ", player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid input.\n");
            continue;
        }

        if (board[row][col] == 'X') {
            matches++;
            board[row][col] = 'O';
        } else {
            board[row][col] = 'X';
        }

        moves++;

        if (matches == ROWS * COLS / 2) {
            printf("Player %d wins!\n", player);
            break;
        }

        player = (player == 1)? 2 : 1;
    }

    return 0;
}