//FormAI DATASET v1.0 Category: Sudoku solver ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 9
#define UNASSIGNED 0

int grid[N][N];

typedef struct {
    int row;
    int col;
} parameters;

int is_row_valid(int row, int num) {
    for (int col = 0; col < N; col++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int is_col_valid(int col, int num) {
    for (int row = 0; row < N; row++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int is_box_valid(int start_row, int start_col, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[start_row + row][start_col + col] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int is_valid(int row, int col, int num) {
    return is_row_valid(row, num) && is_col_valid(col, num) && is_box_valid(row - row % 3, col - col % 3, num);
}

int find_unassigned_cell(int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }
    return 0;
}

void *solve_sudoku(void *data) {
    int row, col;
    parameters *param = (parameters*)data;

    if (!find_unassigned_cell(&row, &col)) {
        return NULL;
    }

    for (int num = 1; num <= 9; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;

            if (solve_sudoku(NULL)) {
                return NULL;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[N];

    // read input from stdin
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    // create threads to solve the sudoku
    for (int i = 0; i < N; i++) {
        parameters *param = malloc(sizeof(parameters));
        param->row = i;
        param->col = 0;
        pthread_create(&threads[i], NULL, solve_sudoku, param);
    }

    // wait for threads to finish
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // print solution to stdout
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }

    return 0;
}