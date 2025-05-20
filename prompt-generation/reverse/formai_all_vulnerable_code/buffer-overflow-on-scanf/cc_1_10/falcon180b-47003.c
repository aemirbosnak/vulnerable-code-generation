//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9
#define MAX_VALUE 9

// Function to check if a given number is valid for a given row, column and subgrid
int is_valid(int board[MAX_SIZE][MAX_SIZE], int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < MAX_SIZE; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (i = 0; i < MAX_SIZE; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // Check subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (i = subgrid_row; i < subgrid_row + 3; i++) {
        for (j = subgrid_col; j < subgrid_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle
int solve_sudoku(int board[MAX_SIZE][MAX_SIZE]) {
    int i, j;

    // Check if the board is already solved
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to print the Sudoku board
void print_board(int board[MAX_SIZE][MAX_SIZE]) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[MAX_SIZE][MAX_SIZE];
    int i, j;

    // Read the Sudoku puzzle from the user
    printf("Enter the Sudoku puzzle:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // Solve the Sudoku puzzle
    if (solve_sudoku(board)) {
        printf("Solved Sudoku puzzle:\n");
        print_board(board);
    } else {
        printf("Invalid Sudoku puzzle.\n");
    }

    return 0;
}