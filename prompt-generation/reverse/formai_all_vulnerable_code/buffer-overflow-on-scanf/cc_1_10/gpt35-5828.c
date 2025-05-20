//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>

#define GRID_SIZE 9

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("   1 2 3  4 5 6  7 8 9\n");
    printf("  -------------------\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (j == 2 || j == 5) {
                printf(" %d |", grid[i][j]);
            } else {
                printf(" %d ", grid[i][j]);
            }
        }
        printf("|\n");
        if (i == 2 || i == 5) {
            printf("  |-----------------|\n");
        }
    }
    printf("  -------------------\n");
}

void getInput(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("Enter the unsolved Sudoku puzzle (use 0 to represent empty cells):\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

void findNextEmptyCell(int grid[GRID_SIZE][GRID_SIZE], int *row, int *col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return;
            }
        }
    }
}

int canPlaceNum(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    // Check row and column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    
    // Check same 3x3 subgrid
    int subgridStartRow = row - row % 3;
    int subgridStartCol = col - col % 3;
    for (int i = subgridStartRow; i < subgridStartRow+3; i++) {
        for (int j = subgridStartCol; j < subgridStartCol+3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

int solveSudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    findNextEmptyCell(grid, &row, &col);
    
    // If all cells have been filled
    if (row == GRID_SIZE) {
        return 1;
    }
    
    for (int num = 1; num <= GRID_SIZE; num++) {
        if (canPlaceNum(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    
    return 0;
}

int main() {
    printf("Welcome to the Sudoku solver program!\n\n");

    int grid[GRID_SIZE][GRID_SIZE];
    getInput(grid);
    printf("\nEntered Sudoku puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku puzzle:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}