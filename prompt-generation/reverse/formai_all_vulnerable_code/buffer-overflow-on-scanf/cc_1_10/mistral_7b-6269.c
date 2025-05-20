//MISTRAL-7B DATASET v1.0 Category: Sudoku solver ; Style: ultraprecise
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 9
#define WIDTH 9
#define HEIGHT 9

typedef struct {
    int grid[SIZE][SIZE];
    int given[SIZE][SIZE];
} Sudoku;

bool isValid(int row, int col, Sudoku *sudoku, int value) {
    for (int i = 0; i < SIZE; i++) {
        if (sudoku->given[row][i] == value || sudoku->given[i][col] == value) {
            return false;
        }
    }

    int box_start_row = row - row % 3;
    int box_start_col = col - col % 3;

    for (int i = box_start_row; i < box_start_row + 3; i++) {
        for (int j = box_start_col; j < box_start_col + 3; j++) {
            if (sudoku->given[i][j] == value) {
                return false;
            }
        }
    }

    return true;
}

bool solve(Sudoku *sudoku, int row, int col) {
    if (row >= SIZE) {
        return true;
    }

    if (col >= SIZE) {
        return solve(sudoku, row + 1, 0);
    }

    if (sudoku->given[row][col] != 0) {
        return solve(sudoku, row, col + 1);
    }

    for (int i = 1; i <= SIZE; i++) {
        if (isValid(row, col, sudoku, i)) {
            sudoku->grid[row][col] = i;
            sudoku->given[row][col] = i;

            if (solve(sudoku, row, col + 1)) {
                return true;
            }

            sudoku->given[row][col] = 0;
            sudoku->grid[row][col] = 0;
        }
    }

    return false;
}

void printSudoku(Sudoku *sudoku) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Sudoku sudoku;
    memset(&sudoku, 0, sizeof(Sudoku));

    int row = 0;
    int col = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (scanf("%d", &sudoku.given[i][j]) != 1) {
                if (feof(stdin)) {
                    goto done;
                }

                if (sudoku.given[i][j] < 1 || sudoku.given[i][j] > SIZE) {
                    printf("Invalid input: %d\n", sudoku.given[i][j]);
                    return 1;
                }

                sudoku.grid[i][j] = sudoku.given[i][j];
            }

            if (sudoku.given[i][j] == 0) {
                row = i;
                col = j;
            }
        }
    }

    if (solve(&sudoku, row, col)) {
        printSudoku(&sudoku);
    } else {
        printf("No solution exists.\n");
    }

done:
    return 0;
}