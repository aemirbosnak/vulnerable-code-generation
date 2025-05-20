//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>
#define N 9 // Sudoku grid size

int grid[N][N]; // 2D array to represent the Sudoku grid

// Function to print the Sudoku grid
void printGrid() {
    printf("\nSudoku grid:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is already present in a row
int checkRow(int row, int num) {
    for(int j=0; j<N; j++) {
        if(grid[row][j] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a column
int checkCol(int col, int num) {
    for(int i=0; i<N; i++) {
        if(grid[i][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a 3x3 subgrid
int checkSubgrid(int row, int col, int num) {
    int subrow = row - row%3;
    int subcol = col - col%3;
    for(int i=subrow; i<subrow+3; i++) {
        for(int j=subcol; j<subcol+3; j++) {
            if(grid[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a number can be placed in a cell
int isSafe(int row, int col, int num) {
    if(!checkRow(row, num) && !checkCol(col, num) && !checkSubgrid(row, col, num)) {
        return 1;
    }
    return 0;
}

// Recursive function to solve the Sudoku grid
int solveSudoku(int row, int col) {
    if(row == N-1 && col == N) {
        return 1;
    }
    if(col == N) {
        row++;
        col = 0;
    }
    if(grid[row][col] > 0) {
        return solveSudoku(row, col+1);
    }
    for(int num=1; num<=N; num++) {
        if(isSafe(row, col, num)) {
            grid[row][col] = num;
            if(solveSudoku(row, col+1)) {
                return 1;
            }
        }
        grid[row][col] = 0;
    }
    return 0;
}

// Main function to read the Sudoku grid and solve it
int main() {
    printf("Enter the Sudoku grid (0 for unknown cells):\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if(solveSudoku(0, 0)) {
        printGrid();
    } else {
        printf("\nNo solution found.\n");
    }
    return 0;
}