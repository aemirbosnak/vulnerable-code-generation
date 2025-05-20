//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

void create_matrix(Matrix *matrix, int rows, int cols) {
    int i, j;
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix->data[i] = (int *)malloc(cols * sizeof(int));
        for (j = 0; j < cols; j++) {
            matrix->data[i][j] = rand() % 100;
        }
    }
}

void print_matrix(Matrix *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void transpose_matrix(Matrix *matrix) {
    int i, j;
    int temp[MAX_ROWS][MAX_COLS];
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            temp[j][i] = matrix->data[i][j];
        }
    }
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = temp[i][j];
        }
    }
}

void multiply_matrices(Matrix *matrix1, Matrix *matrix2, Matrix *result) {
    int i, j, k;
    if (matrix1->cols!= matrix2->rows) {
        printf("Error: Incompatible dimensions for matrix multiplication.\n");
        return;
    }
    result->rows = matrix1->rows;
    result->cols = matrix2->cols;
    result->data = (int **)malloc(result->rows * sizeof(int *));
    for (i = 0; i < result->rows; i++) {
        result->data[i] = (int *)malloc(result->cols * sizeof(int));
        for (j = 0; j < result->cols; j++) {
            result->data[i][j] = 0;
            for (k = 0; k < matrix2->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
}

void main() {
    int rows1, cols1, rows2, cols2;
    Matrix matrix1, matrix2, result;
    printf("Enter dimensions for first matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter dimensions for second matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);
    create_matrix(&matrix1, rows1, cols1);
    create_matrix(&matrix2, rows2, cols2);
    print_matrix(&matrix1);
    print_matrix(&matrix2);
    multiply_matrices(&matrix1, &matrix2, &result);
    printf("Result:\n");
    print_matrix(&result);
    transpose_matrix(&matrix1);
    printf("Transposed matrix:\n");
    print_matrix(&matrix1);
}