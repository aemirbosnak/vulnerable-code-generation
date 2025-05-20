//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the given row has the given number
int inRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given column has the given number
int inCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given 3x3 box has the given number
int inBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxStartRow][col+boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it's safe to put the given number in the given row and column
int isSafe(int grid[N][N], int row, int col, int num) {
    return !inRow(grid, row, num) && !inCol(grid, col, num) && !inBox(grid, row - row % 3, col - col % 3, num);
}

// Function to solve the Sudoku grid
int solveSudoku(int grid[N][N]) {
    int row, col;
    int num;
    int isSolved = 0;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid)) {
                            isSolved = 1;
                            break;
                        } else {
                            grid[row][col] = 0;
                        }
                    } 
                }
                return isSolved;
            }
        }
    }
    return 1;
}

// Driver code
int main() {
    int grid[N][N];
    printf("Enter the Sudoku grid (Enter 0 for empty cells):\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    printf("\nEntered Sudoku Grid:\n");
    printGrid(grid);
    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku Grid:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists for the given Sudoku grid\n");
    }
    return 0;
}