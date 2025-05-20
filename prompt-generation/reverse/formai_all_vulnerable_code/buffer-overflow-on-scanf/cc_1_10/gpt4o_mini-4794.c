//GPT-4o-mini DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>
#include <stdbool.h>

#define N 9

void printGrid(int grid[N][N]) {
    printf("\nHere is the current Sudoku grid:\n");
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            printf("%d ", grid[r][d]);
        }
        printf("\n");
    }
}

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) return false;
        if (grid[x][col] == num) return false;
        if (grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) return false;
    }
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) break;
    }

    if (isEmpty) return true; // sudoku solved

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) return true;

            grid[row][col] = 0; // backtrack
        }
    }
    return false;
}

void fillGrid(int grid[N][N]) {
    printf("Let’s fill your Sudoku grid! Please enter numbers row by row (0 for empty cells):\n");
    for (int r = 0; r < N; r++) {
        printf("Row %d: ", r + 1);
        for (int d = 0; d < N; d++) {
            scanf("%d", &grid[r][d]);
            while (grid[r][d] < 0 || grid[r][d] > 9) {
                printf("Invalid number! Please enter a number between 0 and 9: ");
                scanf("%d", &grid[r][d]);
            }
        }
    }
}

int main() {
    int grid[N][N] = {0};

    fillGrid(grid);
    printGrid(grid);

    if (solveSudoku(grid))
        printf("\nHooray! The Sudoku puzzle has been solved! 🎉\n\n");
    else
        printf("\nOh no! There seems to be no solution for the current Sudoku. 😢\n");

    printGrid(grid);
    
    return 0;
}