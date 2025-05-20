//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include <stdio.h>

#define GRID_SIZE 9

// Function to print the solved sudoku grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("-------------------------\n");
    for(int i=0; i < GRID_SIZE; i++) {
        for(int j=0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
            if ((j+1)%3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i+1)%3 == 0) {
            printf("-------------------------\n");
        }
    }
}

// Function to check if all cells are filled or not
int isFilled(int grid[GRID_SIZE][GRID_SIZE], int *row, int *col) {
    for (*row=0; *row < GRID_SIZE; (*row)++) {
        for (*col=0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if the given value is valid for the cell or not
int isValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int val) {
    // Check if the same value exists in the same row
    for(int i=0; i < GRID_SIZE; i++) {
        if (grid[row][i] == val) {
            return 0;
        }
    }
    // Check if the same value exists in the same column
    for(int i=0; i < GRID_SIZE; i++) {
        if (grid[i][col] == val) {
            return 0;
        }
    }
    // Check if the same value exists in the 3x3 sub-grid
    int subgridRow = row - (row % 3);
    int subgridCol = col - (col % 3);
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if (grid[subgridRow+i][subgridCol+j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the sudoku grid
int solveSudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    if (isFilled(grid, &row, &col) == 1) {
        return 1;
    }
    // Try each value (1-9) for the unfilled cell
    for(int i=1; i <= GRID_SIZE; i++) {
        if (isValid(grid, row, col, i) == 1) {
            grid[row][col] = i;
            if (solveSudoku(grid) == 1) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };
    printf("Enter the initial Sudoku grid (0 for empty cells):\n");
    for(int i=0; i < GRID_SIZE; i++) {
        for(int j=0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solveSudoku(grid) == 1) {
        printf("Sudoku solved successfully!\n");
        printGrid(grid);
    } else {
        printf("Error: Could not solve Sudoku!\n");
    }
    return 0;
}