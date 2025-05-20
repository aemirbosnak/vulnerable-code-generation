//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
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

    int matches = 0;
    int turns = 0;

    while (matches < ROWS * COLS / 2) {
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (board[row][col]!= '-');

        board[row][col] = '*';
        printf("Turn %d: * placed at (%d,%d)\n", turns + 1, row, col);
        printBoard(board);

        int choice;
        do {
            printf("Enter your choice (row and column): ");
            scanf("%d%d", &row, &col);
        } while (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col]!= '*');

        if (board[row][col] == '*') {
            matches++;
            board[row][col] = '-';
        } else {
            board[row][col] = 'X';
        }

        turns++;
        printf("Turn %d: %c placed at (%d,%d)\n", turns, board[row][col], row, col);
        printBoard(board);
    }

    printf("Congratulations! You won in %d turns.\n", turns);

    return 0;
}