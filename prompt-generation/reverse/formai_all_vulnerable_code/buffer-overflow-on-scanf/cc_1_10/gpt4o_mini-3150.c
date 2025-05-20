//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

void printGrid(int grid[N][N]) {
    printf("\n-------------------------\n");
    for (int r = 0; r < N; r++) {
        printf("| ");
        for (int d = 0; d < N; d++) {
            printf("%d ", grid[r][d]);
            if ((d + 1) % 3 == 0) printf("| ");
        }
        printf("\n");
        if ((r + 1) % 3 == 0) printf("-------------------------\n");
    }
}

bool unassignedLocation(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true; // Found an unassigned location
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Check the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;

    if (!unassignedLocation(grid, &row, &col)) 
        return true; // Puzzle solved

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) 
                return true;

            grid[row][col] = 0; // Reset on backtrack
        }
    }
    return false;
}

void inputGrid(int grid[N][N]) {
    printf("Enter your Sudoku puzzle (0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
}

int main() {
    int grid[N][N];
    inputGrid(grid);
    printf("\nYour Sudoku puzzle:\n");
    printGrid(grid);
  
    if (solveSudoku(grid)) {
        printf("\nSolved Sudoku puzzle:\n");
        printGrid(grid);
    } else {
        printf("No solution exists for the given Sudoku puzzle!\n");
    }

    return 0;
}