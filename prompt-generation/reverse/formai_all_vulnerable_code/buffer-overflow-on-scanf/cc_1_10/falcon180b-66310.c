//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MINES 10

void initBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
void revealCell(int row, int col, char board[ROWS][COLS]);
void playGame(char board[ROWS][COLS]);

int main() {
    char board[ROWS][COLS];
    initBoard(board);
    printBoard(board);
    playGame(board);

    return 0;
}

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

void revealCell(int row, int col, char board[ROWS][COLS]) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        if (board[row][col] == '*') {
            printf("You revealed an empty cell.\n");
        }
        else if (board[row][col] == 'M') {
            printf("You hit a mine! Game over.\n");
            exit(0);
        }
        else {
            printf("You revealed a %d.\n", board[row][col] - '0');
        }
    }
    else {
        printf("Invalid cell coordinates.\n");
    }
}

void playGame(char board[ROWS][COLS]) {
    int row, col;
    printf("Enter row and column to reveal a cell: ");
    scanf("%d %d", &row, &col);
    revealCell(row, col, board);

    if (row == -1 && col == -1) {
        printf("You won the game!\n");
    }
    else if (row == -1) {
        printf("You lost the game.\n");
    }
}