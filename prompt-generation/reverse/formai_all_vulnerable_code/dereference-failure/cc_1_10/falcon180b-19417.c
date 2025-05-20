//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int rows;
    int cols;
    int **matrix;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    int **data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        data[i] = malloc(cols * sizeof(int));
    }
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->matrix = data;
    return matrix;
}

void fill_matrix(Matrix *matrix, int value) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->matrix[i][j] = value;
        }
    }
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 1000;
    int cols = 1000;
    int value = 42;

    Matrix *matrix = create_matrix(rows, cols);
    fill_matrix(matrix, value);

    clock_t start_time = clock();
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            matrix->matrix[i][j] = (matrix->matrix[i][j] + 1) % 100;
        }
    }
    clock_t end_time = clock();

    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Elapsed time: %f seconds\n", elapsed_time);

    print_matrix(matrix);

    free_matrix(matrix);

    return 0;
}