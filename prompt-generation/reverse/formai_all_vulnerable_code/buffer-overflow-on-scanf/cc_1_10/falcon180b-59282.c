//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

int grid[ROWS][COLS];

void print_grid(void)
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool is_valid_row(int row, int num)
{
    int i;
    for (i = 0; i < COLS; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool is_valid_col(int col, int num)
{
    int i;
    for (i = 0; i < ROWS; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool is_valid_box(int row, int col, int num)
{
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    int i, j;
    for (i = box_row; i < box_row + 3; i++) {
        for (j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool is_valid_move(int row, int col, int num)
{
    return is_valid_row(row, num) && is_valid_col(col, num) && is_valid_box(row, col, num);
}

void solve_sudoku(void)
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                int num = 1;
                while (num <= 9 &&!is_valid_move(i, j, num)) {
                    num++;
                }
                grid[i][j] = num;
            }
        }
    }
}

void main(void)
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    solve_sudoku();
    print_grid();
}