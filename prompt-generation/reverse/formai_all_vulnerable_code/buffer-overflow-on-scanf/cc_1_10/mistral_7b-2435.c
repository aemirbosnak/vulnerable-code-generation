//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to print Sudoku grid
void print_grid(int grid[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
            if (j < 8)
                printf("|");
        }
        printf("\n");
        if (i < 8) {
            for (j = 0; j < 9; j++) {
                printf("-");
                if (j < 8)
                    printf("---");
                else
                    printf("---\n");
            }
        }
    }
}

// Function to check if a number can be placed at given position in given row, column and box
bool is_valid(int grid[9][9], int row, int col, int num) {
    int box_row = row - row % 3, box_col = col - col % 3;

    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    }

    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

// Function to solve Sudoku using recursion
bool solve_sudoku(int grid[9][9], int row, int col) {
    if (row > 8 || col > 8)
        return true; // base condition, means all cells have been filled

    if (grid[row][col] != 0) { // cell already has a value
        if (solve_sudoku(grid, row, col + 1))
            return true; // move to next cell
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) { // check if number can be placed at given position
            grid[row][col] = num; // place the number in cell
            if (solve_sudoku(grid, row, col + 1)) // move to next cell
                return true;
            grid[row][col] = 0; // backtrack, remove the number from cell
        }
    }

    return false; // if no number can be placed at given position, return false
}

int main() {
    int grid[9][9];
    int i, j;

    // Input Sudoku grid from user
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            scanf("%d", &grid[i][j]);

    // Check if Sudoku is valid
    if (solve_sudoku(grid, 0, 0)) {
        printf("Sudoku is valid and solved:\n");
        print_grid(grid);
    } else {
        printf("Error: Sudoku is not valid.\n");
    }

    return 0;
}