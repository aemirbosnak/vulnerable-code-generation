//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define N 9

int grid[N][N];

int is_safe(int row, int col, int num) {
    int i, j;

    // Check row
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (j = 0; j < N; j++) {
        if (grid[j][col] == num) {
            return 0;
        }
    }

    // Check subgrid
    int subgrid_row = row / 3;
    int subgrid_col = col / 3;

    for (i = 3 * subgrid_row; i < 3 * subgrid_row + 3; i++) {
        for (j = 3 * subgrid_col; j < 3 * subgrid_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku(int row, int col) {
    // If we have reached the end of the grid, the sudoku is solved
    if (row == N - 1 && col == N) {
        return 1;
    }

    // If we have reached the end of a row, move to the next row
    if (col == N) {
        row++;
        col = 0;
    }

    // If the current cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solve_sudoku(row, col + 1);
    }

    // Try all possible numbers for the current cell
    for (int num = 1; num <= N; num++) {
        // If the number is safe, place it in the cell and move to the next cell
        if (is_safe(row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(row, col + 1)) {
                return 1;
            }
        }
    }

    // If no number is safe, reset the cell to 0 and return false
    grid[row][col] = 0;
    return 0;
}

int main() {
    // Read the sudoku grid from the user
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve the sudoku grid
    if (solve_sudoku(0, 0)) {
        // Print the solved sudoku grid
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution\n");
    }

    return 0;
}