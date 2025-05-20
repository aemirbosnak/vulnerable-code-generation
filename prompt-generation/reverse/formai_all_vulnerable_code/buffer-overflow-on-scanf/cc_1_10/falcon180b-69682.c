//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9
#define MAX_VAL 9

// Function to check if a value is valid in a given row, column or box
int is_valid(int board[MAX_SIZE][MAX_SIZE], int row, int col, int val) {
    int i, j;

    // Check row
    for (i = 0; i < MAX_SIZE; i++) {
        if (board[row][i] == val) {
            return 0;
        }
    }

    // Check column
    for (i = 0; i < MAX_SIZE; i++) {
        if (board[i][col] == val) {
            return 0;
        }
    }

    // Check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
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

// Function to get user input for a Sudoku puzzle
void get_input(int board[MAX_SIZE][MAX_SIZE]) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

int main() {
    int board[MAX_SIZE][MAX_SIZE];

    // Get user input for the Sudoku puzzle
    get_input(board);

    // Solve the Sudoku puzzle
    if (solve_sudoku(board)) {
        printf("Solution:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}