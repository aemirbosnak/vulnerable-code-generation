//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UNASSIGNED 0
#define N 9

void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool findUnassignedLocation(int grid[N][N], int* row, int* col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED)
                return true;
        }
    }
    return false;

}

bool usedInRow(int grid[N][N], int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInCol(int grid[N][N], int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3, col - col % 3, num);
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findUnassignedLocation(grid, &row, &col))
        return true;

    for (int num = 1; num <= 9; num++){
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if(solveSudoku(grid)) 
                return true;

            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

int main() {
    int grid[N][N];

    printf("Enter the Sudoku grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Solving Sudoku:\n");
    if (solveSudoku(grid) == true) 
        printGrid(grid);
  
    else 
        printf("No solution exists");

    return 0;
}