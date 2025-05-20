//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>
#include <stdbool.h>

#define N 9         // The Sudoku board size

bool findEmpty(int grid[N][N], int* row, int* col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {    // Find an empty cell
                return true;
            }
        }
    }
    return false;       // All cells filled
}

bool usedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

void printGrid(int grid[N][N]) {
    printf("┌───────┬───────┬───────┐\n");
    for (int row = 0; row < N; row++) {
        printf("│");
        for (int col = 0; col < N; col++) {
            printf(" %d ", grid[row][col]);
            if ((col + 1) % 3 == 0) printf("│ ");
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row < N - 1) {
            printf("├───────┼───────┼───────┤\n");
        }
    }
    printf("└───────┴───────┴───────┘\n");
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmpty(grid, &row, &col)) {  // No empty cell
        return true;
    }    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {        // Recursively solve
                return true;
            }
            grid[row][col] = 0;             // Backtrack
        }
    }
    return false;
}

int main() {
    int grid[N][N];
    printf("Enter Sudoku puzzle (use 0 for empty cell):\n");
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }
    if (solveSudoku(grid)) {
        printf("\nSolution:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution.\n");
    }
    return 0;
}