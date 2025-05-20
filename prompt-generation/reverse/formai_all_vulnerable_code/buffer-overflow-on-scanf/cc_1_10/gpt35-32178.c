//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

int grid[SIZE][SIZE];

/**
 * Check if a number can be placed in a cell
 * @param row The row of the cell
 * @param col The column of the cell
 * @param num The number to be placed in the cell
 * @return True if the number can be placed, otherwise false
 */
bool is_valid(int row, int col, int num) {
    // Check row
    for(int i = 0; i < SIZE; i++) {
        if(grid[row][i] == num) {
            return false;
        }
    }
    // Check column
    for(int i = 0; i < SIZE; i++) {
        if(grid[i][col] == num) {
            return false;
        }
    }
    // Check square
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[start_row + i][start_col + j] == num) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Solve the Sudoku puzzle recursively
 * @param row The row to start from
 * @param col The column to start from
 * @return True if a solution is found, otherwise false
 */
bool solve(int row, int col) {
    if(row == SIZE) {
        return true;
    }
    if(col == SIZE) {
        return solve(row + 1, 0);
    }
    if(grid[row][col] != 0) {
        return solve(row, col + 1);
    }
    for(int i = 1; i <= 9; i++) {
        if(is_valid(row, col, i)) {
            grid[row][col] = i;
            if(solve(row, col + 1)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

/**
 * Print the Sudoku grid
 */
void print_grid() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the Sudoku grid (0 for empty cells):\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if(solve(0, 0)) {
        printf("Solution:\n");
        print_grid();
    } else {
        printf("No solution found\n");
    }
    return 0;
}