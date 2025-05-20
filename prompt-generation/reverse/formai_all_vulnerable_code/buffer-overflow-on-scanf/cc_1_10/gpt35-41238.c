//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 9

int grid[GRID_SIZE][GRID_SIZE];

int find_unassigned(int *row, int *col) {
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0; 
}

int is_valid(int row, int col, int num) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == num) { // check row
            return 0;
        }
        if (grid[i][col] == num) { // check column
            return 0;
        }
    }

    // check 3x3 box
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[start_row + i][start_col + j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve() {
    int row, col;
    if (!find_unassigned(&row, &col)) {
        return 1;
    }
    for (int num = 1; num <= GRID_SIZE; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            if (solve()) {
                return 1;
            }
            grid[row][col] = 0; // backtrack
        }
    }
    return 0;
}

void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Please enter the Sudoku puzzle to solve, with '0' representing an empty cell:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    if (solve()) {
        printf("\nSolution:\n");
        print_grid();
    }
    else {
        printf("\nNo solution exists.\n");
    }
    return 0;
}