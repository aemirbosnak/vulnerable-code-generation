//FormAI DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>

int grid[9][9];

// Function to check if the given value is valid at the position (x,y)
int isValid(int x, int y, int val) {
    for (int i = 0; i < 9; i++) {
        if (grid[x][i] == val || grid[i][y] == val) {
            return 0;
        }
    }
    int row = x - (x%3);
    int col = y - (y%3);
    for (int i = row; i < row+3; i++) {
        for (int j = col; j < col+3; j++) {
            if (grid[i][j] == val) {
                return 0;
            }
        }
    }
    return 1;
}
// Function to solve Sudoku puzzle
int solveSudoku(int x, int y) {
    if (x == 9) {
        return 1;
    }
    if (grid[x][y] != 0) {
        if (y == 8) {
            return solveSudoku(x+1, 0);
        }
        return solveSudoku(x, y+1);
    }
    for (int i = 1; i <= 9; i++) {
        if (isValid(x, y, i)) {
            grid[x][y] = i;
            if (y == 8) {
                if (solveSudoku(x+1, 0)) {
                    return 1;
                }
            } else {
                if (solveSudoku(x, y+1)) {
                    return 1;
                }
            }
            grid[x][y] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the Sudoku puzzle (0 for blank cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    printf("\nSudoku puzzle before solving:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    if (solveSudoku(0, 0)) {
        printf("\nSudoku puzzle after solving:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nNo solution found for the given Sudoku puzzle.\n");
    }
    return 0;
}