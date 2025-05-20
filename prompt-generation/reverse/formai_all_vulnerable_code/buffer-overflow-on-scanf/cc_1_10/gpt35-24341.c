//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

#define N 9   // Size of the Sudoku grid

bool solveSudoku(int grid[][N], int row, int col);
bool isSafe(int grid[][N], int row, int col, int num);
void printGrid(int grid[][N]);

int main() {

    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    printf("Enter the Sudoku grid:\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solveSudoku(grid, 0, 0)) {
        printf("\nThe solution to the Sudoku grid is:\n");
        printGrid(grid);

    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}

bool solveSudoku(int grid[][N], int row, int col) {

    if (row == N - 1 && col == N) {
        return true;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    for (int num = 1; num <= N; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
        }

        grid[row][col] = 0;
    }

    return false;
}

bool isSafe(int grid[][N], int row, int col, int num) {

    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

void printGrid(int grid[][N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}