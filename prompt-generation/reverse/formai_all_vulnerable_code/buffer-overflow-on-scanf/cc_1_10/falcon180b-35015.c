//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid in a row
int isValidRow(int board[SIZE][SIZE], int row, int num) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a column
int isValidCol(int board[SIZE][SIZE], int col, int num) {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is valid in a 3x3 box
int isValidBox(int board[SIZE][SIZE], int row, int col, int num) {
    int i, j;
    for (i = row - row % 3; i < row + (3 - (row % 3)); i++) {
        for (j = col - col % 3; j < col + (3 - (col % 3)); j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the board is complete
int isComplete(int board[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku puzzle
void solveSudoku(int board[SIZE][SIZE]) {
    int i, j, num;

    // Fill in the easy numbers
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                for (num = 1; num <= SIZE; num++) {
                    if (isValidRow(board, i, num) && isValidCol(board, j, num) && isValidBox(board, i - i % 3, j - j % 3, num)) {
                        board[i][j] = num;
                        if (isComplete(board)) {
                            printBoard(board);
                            exit(0);
                        } else {
                            solveSudoku(board);
                            board[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}

// Main function
int main() {
    int board[SIZE][SIZE];

    // Read in the Sudoku puzzle
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve the Sudoku puzzle
    solveSudoku(board);

    return 0;
}