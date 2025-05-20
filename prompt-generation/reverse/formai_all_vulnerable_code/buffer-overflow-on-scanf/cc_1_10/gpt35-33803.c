//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 9
#define COLS 9

int sudokuGrid[ROWS][COLS];

/* Function to check if it is safe to put a value in the given cell */
int isSafe(int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (sudokuGrid[row][i] == val || sudokuGrid[i][col] == val) {
            return 0;
        }
    }
    int start_row = row - (row % 3);
    int start_col = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudokuGrid[start_row + i][start_col + j] == val) {
                return 0;
            }
        }
    }
    return 1;
}

/* Function to solve the Sudoku using backtracking */
void* solveSudoku(void *arg) {
    int id = *((int*)arg);
    int start_row = (id / 3) * 3;
    int start_col = (id % 3) * 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (sudokuGrid[i][j] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(i, j, val)) {
                        sudokuGrid[i][j] = val;
                        if (solveSudoku(arg)) {
                            return 1;
                        }
                        sudokuGrid[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

/* Function to print the Sudoku grid */
void printSudoku() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", sudokuGrid[i][j]);
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    pthread_t threads[9];
    int tid[9];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d ", &sudokuGrid[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        tid[i] = i;
        pthread_create(&threads[i], NULL, solveSudoku, &tid[i]);
    }
    for (int i = 0; i < 9; i++) {
        pthread_join(threads[i], NULL);
    }
    printSudoku();
    return 0;
}