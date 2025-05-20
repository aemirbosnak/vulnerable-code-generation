//FormAI DATASET v1.0 Category: Sudoku solver ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

// Function to print the Sudoku grid
void print_grid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a given cell
bool can_place(int grid[9][9], int row, int col, int num) {
    // Check if the number already appears in row or column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number already appears in the 3x3 subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subgrid_row+i][subgrid_col+j] == num) {
                return false;
            }
        }
    }

    // If the number can be placed in the cell, return true
    return true;
}

// Function to solve the Sudoku grid using backtracking
bool solve_sudoku(int grid[9][9], int row, int col) {
    // If we have reached the last cell of the grid, then we have found a solution
    if (row == 8 && col == 9) {
        return true;
    }

    // If we have reached the end of a row, move to next row
    if (col == 9) {
        row++;
        col = 0;
    }

    // If the cell is already filled, move to next cell
    if (grid[row][col] != 0) {
        return solve_sudoku(grid, row, col+1);
    }

    // Try all possible numbers from 1-9 in the cell
    for (int num = 1; num <= 9; num++) {
        if (can_place(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the next cell
            if (solve_sudoku(grid, row, col+1)) {
                return true;
            }

            // If no number can be placed in the cell, backtrack
            grid[row][col] = 0;
        }
    }

    // If no solution was found, backtrack to previous cell
    return false;
}

// Main function
int main() {
    int grid[9][9] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // Initialize the grid
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solve the Sudoku grid
    bool solvable = solve_sudoku(grid, 0, 0);
    if (solvable) {
        printf("Sudoku solved:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}