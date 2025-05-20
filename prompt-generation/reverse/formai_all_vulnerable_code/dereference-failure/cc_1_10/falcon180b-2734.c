//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

typedef struct {
    int rows;
    int cols;
    double **matrix;
} Matrix;

void create_matrix(Matrix *matrix) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            matrix->matrix[i][j] = rand() % 100;
        }
    }
}

void print_matrix(Matrix matrix) {
    int i, j;
    for (i = 0; i < matrix.rows; i++) {
        for (j = 0; j < matrix.cols; j++) {
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(Matrix matrix1, Matrix matrix2, Matrix *result) {
    int i, j;
    for (i = 0; i < matrix1.rows; i++) {
        for (j = 0; j < matrix1.cols; j++) {
            result->matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
        }
    }
}

void subtract_matrices(Matrix matrix1, Matrix matrix2, Matrix *result) {
    int i, j;
    for (i = 0; i < matrix1.rows; i++) {
        for (j = 0; j < matrix1.cols; j++) {
            result->matrix[i][j] = matrix1.matrix[i][j] - matrix2.matrix[i][j];
        }
    }
}

void multiply_matrices(Matrix matrix1, Matrix matrix2, Matrix *result) {
    int i, j, k;
    for (i = 0; i < matrix1.rows; i++) {
        for (j = 0; j < matrix2.cols; j++) {
            result->matrix[i][j] = 0;
            for (k = 0; k < matrix1.cols; k++) {
                result->matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
            }
        }
    }
}

void transpose_matrix(Matrix matrix, Matrix *result) {
    int i, j;
    for (i = 0; i < matrix.cols; i++) {
        for (j = 0; j < matrix.rows; j++) {
            result->matrix[i][j] = matrix.matrix[j][i];
        }
    }
}

int main() {
    Matrix matrix1, matrix2, result;
    create_matrix(&matrix1);
    create_matrix(&matrix2);
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    add_matrices(matrix1, matrix2, &result);
    printf("Sum:\n");
    print_matrix(result);
    subtract_matrices(matrix1, matrix2, &result);
    printf("Difference:\n");
    print_matrix(result);
    multiply_matrices(matrix1, matrix2, &result);
    printf("Product:\n");
    print_matrix(result);
    transpose_matrix(matrix1, &result);
    printf("Transpose of Matrix 1:\n");
    print_matrix(result);
    return 0;
}