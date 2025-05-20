//Falcon2-11B DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>

#define MAX_SIZE 9

void solve_sudoku(int grid[][MAX_SIZE]) {
    int row, col, num, i, j, k;
    int empty_row, empty_col;

    for (row = 0; row < MAX_SIZE; row++) {
        for (col = 0; col < MAX_SIZE; col++) {
            if (grid[row][col] == 0) {
                empty_row = row;
                empty_col = col;
            }
        }
    }

    for (num = 1; num <= MAX_SIZE; num++) {
        if (is_valid(grid, empty_row, empty_col, num)) {
            grid[empty_row][empty_col] = num;
            solve_sudoku(grid);
            if (is_solved(grid)) {
                break;
            }
            grid[empty_row][empty_col] = 0;
        }
    }
}

int is_valid(int grid[][MAX_SIZE], int row, int col, int num) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    for (j = 0; j < MAX_SIZE; j++) {
        if (grid[row][j] == num) {
            return 0;
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == num && i!= row && j!= col) {
                return 0;
            }
        }
    }

    return 1;
}

int is_solved(int grid[][MAX_SIZE]) {
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int grid[MAX_SIZE][MAX_SIZE];
    int i, j;

    printf("Enter the initial grid:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    solve_sudoku(grid);

    printf("The solved grid is:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}