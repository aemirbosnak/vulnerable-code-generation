//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#define N 9

int grid[N][N];

// Function to check if the current cell is safe to fill
int is_safe(int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check square
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    for (i = row_start; i < row_start + 3; i++) {
        for (j = col_start; j < col_start + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to solve the sudoku
int solve() {
    int row, col, num;

    // Find unassigned cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                // Try every number from 1 to 9
                for (num = 1; num <= 9; num++) {
                    if (is_safe(row, col, num)) {
                        // Fill the cell
                        grid[row][col] = num;

                        // Recursively solve rest of the puzzle
                        if (solve()) {
                            return 1;
                        }

                        // Undo the fill if it didn't work
                        grid[row][col] = 0;
                    }
                }

                // No number works for this cell, backtrack
                return 0;
            }
        }
    }

    // Puzzle solved
    return 1;
}

// Function to print the solved puzzle
void print() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    printf("Enter the sudoku puzzle (use 0 for empty cells)\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solve()) {
        printf("\nSolved puzzle:\n");
        print();
    } else {
        printf("\nUnable to solve puzzle.\n");
    }

    return 0;
}