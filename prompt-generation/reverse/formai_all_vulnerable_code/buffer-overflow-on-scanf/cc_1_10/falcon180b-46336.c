//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void initBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isMatch(char a, char b) {
    return a == b;
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int matches = 0;

    int selectedRow, selectedCol;
    selectedRow = rand() % ROWS;
    selectedCol = rand() % COLS;

    board[selectedRow][selectedCol] = '*';
    printBoard(board);

    char input;
    while ((scanf("%c", &input))!= EOF) {
        int row = (input - '0') / COLS;
        int col = (input - '0') % COLS;

        if (board[row][col] == '*') {
            matches++;
        } else if (board[row][col]!= '-') {
            printf("Invalid move!\n");
        }

        board[row][col] = '-';
        printBoard(board);

        if (matches == (ROWS * COLS) / 2) {
            printf("Congratulations! You won!\n");
            break;
        }

        selectedRow = rand() % ROWS;
        selectedCol = rand() % COLS;

        while (board[selectedRow][selectedCol]!= '-') {
            selectedRow = rand() % ROWS;
            selectedCol = rand() % COLS;
        }

        board[selectedRow][selectedCol] = '*';
        printBoard(board);
    }

    return 0;
}