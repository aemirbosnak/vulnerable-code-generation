//Falcon-180B DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define N 9
#define M 9
#define MAX_VALUE 9

// Function to print the given Sudoku matrix
void print_matrix(int matrix[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a given value is valid for a cell
int is_valid(int matrix[N][M], int row, int col, int value) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (matrix[row][i] == value) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < M; i++) {
        if (matrix[i][col] == value) {
            return 0;
        }
    }
    // Check 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (matrix[i][j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku matrix recursively
int solve_sudoku(int matrix[N][M], int row, int col) {
    if (row == N - 1 && col == M - 1) {
        return 1;
    }
    if (row == N - 1) {
        col++;
        row = 0;
    } else if (col == M - 1) {
        row++;
        col = 0;
    }
    if (matrix[row][col] == 0) {
        for (int value = 1; value <= MAX_VALUE; value++) {
            if (is_valid(matrix, row, col, value)) {
                matrix[row][col] = value;
                if (solve_sudoku(matrix, row, col)) {
                    return 1;
                }
                matrix[row][col] = 0;
            }
        }
        return 0;
    }
    return solve_sudoku(matrix, row, col);
}

// Function to read the Sudoku matrix from a file
void read_matrix_from_file(FILE *fp, int matrix[N][M]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
}

int main() {
    int matrix[N][M];
    FILE *fp;
    fp = fopen("sudoku.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    read_matrix_from_file(fp, matrix);
    fclose(fp);
    int result = solve_sudoku(matrix, 0, 0);
    if (result) {
        printf("Sudoku solved successfully!\n");
        print_matrix(matrix);
    } else {
        printf("Sudoku cannot be solved.\n");
    }
    return 0;
}