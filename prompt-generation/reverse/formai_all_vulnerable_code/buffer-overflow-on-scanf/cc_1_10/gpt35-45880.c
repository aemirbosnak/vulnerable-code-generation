//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>

// define N as the size of Sudoku and UNASSIGNED as unused cell
#define N 9
#define UNASSIGNED 0

// function to print the solved Sudoku
void printSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// function to check if the given number is already present in row, column, or box
int isSafe(int grid[N][N], int row, int col, int num) {
    // check in row
    for (int c = 0; c < N; c++) {
        if (grid[row][c] == num) {
            return 0;
        }
    }

    // check in column
    for (int r = 0; r < N; r++) {
        if (grid[r][col] == num) {
            return 0;
        }
    }

    // check in box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[r + boxRow][c + boxCol] == num) {
                return 0;
            }
        }
    }

    // if it passes all checks, it's safe
    return 1;
}

// recursive function to solve the Sudoku
int solveSudoku(int grid[N][N], int row, int col) {
    // if solved all rows, move to the next column
    if (row == N - 1 && col == N) {
        return 1;
    }
    // if column end is reached, move to next row
    if (col == N) {
        row++;
        col = 0;
    }
    // if current cell is already filled, skip to next
    if (grid[row][col] != UNASSIGNED) {
        return solveSudoku(grid, row, col + 1);
    }
    // try to fill the current cell with numbers 1-9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            // unset the value for backtracking
            grid[row][col] = UNASSIGNED;
        }
    }
    // if none of the numbers worked, reset and backtrack
    return 0;
}

int main() {
    // create and initialize Sudoku grid
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    // read the input puzzle as a comma-separated string of digits
    printf("Enter the Sudoku puzzle:\n");
    char input[N*N];
    scanf("%s", input);

    // fill grid with input digits
    int digit = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            digit = input[col + row*N] - '0';
            if (digit >= 1 && digit <= 9) {
                grid[row][col] = digit;
            }
        }
    }

    // solve the Sudoku
    if (solveSudoku(grid, 0, 0)) {
        printf("\nSolution:\n");
        printSudoku(grid);
    } else {
        printf("\nNo solution found!\n");
    }

    return 0;
}