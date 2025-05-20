//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

#define SIZE 9

int puzzle[SIZE][SIZE];

// function to check whether a number can be placed in a given cell
int can_place(int row, int col, int num) {
    // check row and column for conflicts
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num || puzzle[i][col] == num) {
            return 0; // conflict found
        }
    }
    // check 3x3 sub-grid for conflicts
    int sub_row = row - row % 3;
    int sub_col = col - col % 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0; // conflict found
            }
        }
    }
    return 1; // no conflicts found
}

// function to solve the puzzle using backtracking
int solve(int row, int col) {
    if (row == SIZE) {
        return 1; // puzzle is solved
    }
    if (col == SIZE) {
        return solve(row + 1, 0); // move to next row
    }
    if (puzzle[row][col] != 0) {
        return solve(row, col + 1); // non-empty cell, move to next column
    }
    for (int i = 1; i <= SIZE; i++) {
        if (can_place(row, col, i)) {
            puzzle[row][col] = i;
            if (solve(row, col + 1)) {
                return 1; // success, puzzle is solved
            }
            puzzle[row][col] = 0; // backtrack
        }
    }
    return 0; // puzzle cannot be solved
}

int main() {
    printf("Enter the Sudoku puzzle as a 9x9 grid of integers, with 0 representing an empty cell:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &puzzle[i][j]);
        }
    }
    if (solve(0, 0)) {
        printf("Solution:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", puzzle[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("This Sudoku puzzle cannot be solved.\n");
    }
    return 0;
}