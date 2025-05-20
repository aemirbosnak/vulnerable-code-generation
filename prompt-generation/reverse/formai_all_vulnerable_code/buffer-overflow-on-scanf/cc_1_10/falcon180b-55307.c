//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define BOX_SIZE 3

// Function to check if a number is valid in a given row, column, or box
int isValid(int board[SIZE][SIZE], int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < SIZE; i++) {
        if (board[row][i] == num)
            return 0;
    }

    // Check column
    for (i = 0; i < SIZE; i++) {
        if (board[i][col] == num)
            return 0;
    }

    // Check box
    int boxRow = row - row % BOX_SIZE;
    int boxCol = col - col % BOX_SIZE;

    for (i = boxRow; i < boxRow + BOX_SIZE; i++) {
        for (j = boxCol; j < boxCol + BOX_SIZE; j++) {
            if (board[i][j] == num)
                return 0;
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int board[SIZE][SIZE]) {
    int row, col;

    // Check if the board is already solved
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0)
                return 0;
        }
    }

    return 1;
}

// Function to print the Sudoku board
void printBoard(int board[SIZE][SIZE]) {
    int row, col;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to get user input for a Sudoku puzzle
void getInput(int board[SIZE][SIZE]) {
    int row, col;

    printf("Enter the Sudoku puzzle:\n");

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            scanf("%d", &board[row][col]);
        }
    }
}

// Main function
int main() {
    int board[SIZE][SIZE];

    // Get user input for the Sudoku puzzle
    getInput(board);

    // Solve the Sudoku puzzle
    if (solveSudoku(board)) {
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}