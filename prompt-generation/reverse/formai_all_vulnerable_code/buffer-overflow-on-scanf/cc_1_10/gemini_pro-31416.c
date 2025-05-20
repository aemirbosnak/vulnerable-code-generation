//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 9

int grid[SIZE][SIZE];

int is_safe(int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) return 0;
        if (grid[i][col] == num) return 0;
    }

    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = box_row * 3; i < box_row * 3 + 3; i++) {
        for (int j = box_col * 3; j < box_col * 3 + 3; j++) {
            if (grid[i][j] == num) return 0;
        }
    }

    return 1;
}

int solve_sudoku() {
    int row, col;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (is_safe(row, col, num)) {
                        grid[row][col] = num;

                        if (solve_sudoku()) {
                            return 1;
                        } else {
                            grid[row][col] = 0;
                        }
                    }
                }

                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int i, j;

    printf("Enter the sudoku puzzle:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    if (solve_sudoku()) {
        printf("The solution is:\n");
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}