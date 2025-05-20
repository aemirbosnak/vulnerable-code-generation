//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to check if a number is safe to place in a cell
bool is_safe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if the number already exists in the same row or column
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    // Check if the number already exists in the same 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[box_row + i][box_col + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to find the next empty cell in the grid
bool find_empty_cell(int grid[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle
bool solve_sudoku(int grid[SIZE][SIZE]) {
    int row, col;
    // Find the next empty cell
    if (!find_empty_cell(grid, &row, &col)) {
        return true; // If all cells are filled, the puzzle is solved
    }
    // Try every possible number in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num; // Assign the number to the cell
            // Recursively solve the puzzle
            if (solve_sudoku(grid)) {
                return true; // If the puzzle is solved, exit recursion
            }
            grid[row][col] = 0; // Else, backtrack and try another number
        }
    }
    return false; // If none of the numbers work, the puzzle is unsolvable
}

// Function to print the Sudoku solution
void print_solution(int grid[SIZE][SIZE]) {
    printf("The solution is:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE];
    printf("Enter the Sudoku puzzle (use 0 to represent empty cells):\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    if (solve_sudoku(grid)) {
        print_solution(grid);
    } else {
        printf("The puzzle is unsolvable.\n");
    }
    return 0;
}