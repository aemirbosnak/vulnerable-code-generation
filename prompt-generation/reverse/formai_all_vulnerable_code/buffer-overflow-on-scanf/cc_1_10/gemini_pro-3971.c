//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct {
    int val;
    int possibilities[SIZE];
} cell;

int grid[SIZE][SIZE];
cell cells[SIZE][SIZE];

void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int val) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == val || grid[i][col] == val) {
            return 0;
        }
    }

    int box_row = row / 3;
    int box_col = col / 3;
    for (int i = 3 * box_row; i < 3 * (box_row + 1); i++) {
        for (int j = 3 * box_col; j < 3 * (box_col + 1); j++) {
            if (grid[i][j] == val) {
                return 0;
            }
        }
    }

    return 1;
}

void set_possibilities() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                for (int k = 0; k < SIZE; k++) {
                    cells[i][j].possibilities[k] = 1;
                }

                for (int k = 0; k < SIZE; k++) {
                    if (!is_valid(i, j, k + 1)) {
                        cells[i][j].possibilities[k] = 0;
                    }
                }
            }
        }
    }
}

int solve() {
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                for (int k = 0; k < SIZE; k++) {
                    if (cells[i][j].possibilities[k]) {
                        grid[i][j] = k + 1;
                        if (solve()) {
                            return 1;
                        }
                        grid[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    printf("Welcome to our romantic Sudoku solver!\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    set_possibilities();

    printf("Your grid:\n");
    print_grid();

    if (solve()) {
        printf("Your solved grid:\n");
        print_grid();
    } else {
        printf("No solution found.\n");
    }

    return 0;
}