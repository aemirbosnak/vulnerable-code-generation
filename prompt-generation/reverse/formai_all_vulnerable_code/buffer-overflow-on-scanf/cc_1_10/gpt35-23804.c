//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// size of the Sudoku grid
#define SIZE 9

// thread argument struct
struct arg_struct {
    int row;
    int col;
};

// Sudoku grid
int grid[SIZE][SIZE];

// check if the given value is already present in the row
bool check_row(int row, int val) {
    for (int i = 0; i < SIZE; ++i) {
        if (grid[row][i] == val) {
            return false;
        }
    }
    return true;
}

// check if the given value is already present in the column
bool check_col(int col, int val) {
    for (int i = 0; i < SIZE; ++i) {
        if (grid[i][col] == val) {
            return false;
        }
    }
    return true;
}

// check if the given value is already present in the 3x3 box
bool check_box(int row, int col, int val) {
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; ++i) {
        for (int j = box_col; j < box_col + 3; ++j) {
            if (grid[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

// check if the given value is valid for the cell
bool is_valid(int row, int col, int val) {
    return check_row(row, val) && check_col(col, val) && check_box(row, col, val);
}

// solve the Sudoku recursively using backtracking
bool solve_sudoku(int row, int col) {
    // if we have reached the end, return true
    if (row == SIZE) {
        return true;
    }
    // determine the next row and column
    int next_row, next_col;
    if (col == SIZE - 1) {
        next_row = row + 1;
        next_col = 0;
    } else {
        next_row = row;
        next_col = col + 1;
    }
    // if the cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solve_sudoku(next_row, next_col);
    }
    // try all possible values for the cell
    for (int i = 1; i <= SIZE; ++i) {
        if (is_valid(row, col, i)) {
            // set the cell to the current value
            grid[row][col] = i;
            // if the Sudoku can be solved recursively, return true
            if (solve_sudoku(next_row, next_col)) {
                return true;
            }
            // otherwise, reset the cell and try the next value
            grid[row][col] = 0;
        }
    }
    // if no possible value works, backtrack
    return false;
}

// print the Sudoku grid
void print_grid() {
    printf("+-------+-------+-------+\n");
    for (int i = 0; i < SIZE; ++i) {
        printf("|");
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == 0) {
                printf(" . ");
            } else {
                printf(" %d ", grid[i][j]);
            }
            if (j == 2 || j == 5 || j == 8) {
                printf("|");
            }
        }
        printf("\n");
        if (i == 2 || i == 5 || i == 8) {
            printf("+-------+-------+-------+\n");
        }
    }
}

// solve a single cell of the Sudoku grid using a separate thread
void * solve_cell(void * arg) {
    struct arg_struct * args = (struct arg_struct *) arg;
    int row = args->row;
    int col = args->col;
    // if the cell is already filled, return
    if (grid[row][col] != 0) {
        return NULL;
    }
    // try all possible values for the cell
    for (int i = 1; i <= SIZE; ++i) {
        if (is_valid(row, col, i)) {
            // set the cell to the current value
            grid[row][col] = i;
            // if the Sudoku can be solved recursively, return
            if (solve_sudoku(0, 0)) {
                return NULL;
            }
            // otherwise, reset the cell and try the next value
            grid[row][col] = 0;
        }
    }
    return NULL;
}

int main() {
    // initialize the Sudoku grid
    printf("Enter the Sudoku grid:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }
    // solve the Sudoku using a single thread
    printf("Solving using a single thread...\n");
    if (solve_sudoku(0, 0)) {
        printf("Solved!\n");
    } else {
        printf("Unable to solve.\n");
    }
    print_grid();
    // solve the Sudoku using multiple threads
    printf("Solving using multiple threads...\n");
    pthread_t threads[SIZE*SIZE];
    int num_threads = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            struct arg_struct * args = malloc(sizeof(struct arg_struct));
            args->row = i;
            args->col = j;
            if (pthread_create(&threads[num_threads], NULL, solve_cell, args)) {
                fprintf(stderr, "Error creating thread\n");
                return 1;
            }
            num_threads++;
        }
    }
    // wait for all threads to finish
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }
    print_grid();
    return 0;
}