//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = '-';
        }
    }
}

void printBoard(const char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
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
    while (matches < ROWS * COLS / 2) {
        int row1, col1, row2, col2;
        do {
            row1 = rand() % ROWS;
            col1 = rand() % COLS;
            row2 = rand() % ROWS;
            col2 = rand() % COLS;
        } while (row1 == row2 && col1 == col2);

        board[row1][col1] = '*';
        board[row2][col2] = '*';

        printBoard(board);

        int choice;
        printf("Enter your choice (row, col): ");
        scanf("%d, %d", &choice, &choice);

        if (board[choice][choice] == '*') {
            ++matches;
        } else {
            board[choice][choice] = '-';
        }
    }

    printf("Congratulations! You won the game with %d matches!\n", matches);

    return 0;
}