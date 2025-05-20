//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 9
#define MAX_COLS 9
#define MAX_NUM 9
#define EMPTY 0

void print_grid(int grid[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void solve_sudoku(int grid[MAX_ROWS][MAX_COLS]) {
    int i, j, row, col;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (grid[i][j] == EMPTY) {
                row = i;
                col = j;
                while (row < MAX_ROWS && grid[row][col]!= EMPTY) {
                    col++;
                }
                if (col == MAX_COLS) {
                    col = 0;
                    row++;
                }
                while (col < MAX_COLS && grid[row][col]!= EMPTY) {
                    col++;
                }
                if (col == MAX_COLS) {
                    col = 0;
                    row++;
                }
                while (row < MAX_ROWS && grid[row][col]!= EMPTY) {
                    row++;
                }
                if (row == MAX_ROWS) {
                    row = 0;
                    col = 0;
                }
                grid[row][col] = 1;
                solve_sudoku(grid);
                grid[row][col] = EMPTY;
            }
        }
    }
}

int main() {
    int grid[MAX_ROWS][MAX_COLS];
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    solve_sudoku(grid);
    print_grid(grid);
    return 0;
}