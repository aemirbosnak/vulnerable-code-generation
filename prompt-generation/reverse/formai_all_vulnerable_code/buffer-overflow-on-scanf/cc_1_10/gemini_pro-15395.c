//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int board[9][9];
int solved = 0;

void printBoard() {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int findEmptyCell() {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int isValidMove(int row, int col, int num) {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    for (i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    int boxRow = row / 3;
    int boxCol = col / 3;
    for (i = boxRow * 3; i < boxRow * 3 + 3; i++) {
        for (j = boxCol * 3; j < boxCol * 3 + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void solveSudoku() {
    int row, col;
    if (!findEmptyCell()) {
        solved = 1;
        return;
    }
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValidMove(row, col, num)) {
                        board[row][col] = num;
                        solveSudoku();
                        if (solved) {
                            return;
                        }
                        board[row][col] = 0;
                    }
                }
                return;
            }
        }
    }
}

int main() {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%d ", &board[i][j]);
        }
    }
    solveSudoku();
    if (solved) {
        printf("The Sudoku has been solved:");
        printBoard();
    } else {
        printf("The Sudoku cannot be solved");
    }
    return 0;
}