//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void print_matrix(int **matrix, int rows, int cols);
void transpose_matrix(int **matrix, int rows, int cols);

int main() {
    int i, j, rows, cols;
    int **matrix;

    srand(time(NULL));

    rows = rand() % MAX_ROWS + 1;
    cols = rand() % MAX_COLS + 1;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    print_matrix(matrix, rows, cols);

    transpose_matrix(matrix, rows, cols);

    print_matrix(matrix, rows, cols);

    return 0;
}

void print_matrix(int **matrix, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(int **matrix, int rows, int cols) {
    int i, j, temp;

    for (i = 0; i < rows; i++) {
        for (j = i + 1; j < cols; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}