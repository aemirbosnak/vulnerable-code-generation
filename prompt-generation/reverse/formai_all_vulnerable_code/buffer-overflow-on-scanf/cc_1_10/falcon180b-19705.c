//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

Matrix *create_matrix(int rows, int cols) {
    Matrix *matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(Matrix *matrix, int value) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            matrix->data[i][j] = value;
        }
    }
}

void transpose_matrix(Matrix *matrix) {
    int temp;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            temp = matrix->data[i][j];
            matrix->data[i][j] = matrix->data[j][i];
            matrix->data[j][i] = temp;
        }
    }
}

void multiply_matrices(Matrix *matrix1, Matrix *matrix2, Matrix *result) {
    if (matrix1->cols!= matrix2->rows) {
        printf("Error: Incompatible dimensions for matrix multiplication.\n");
        exit(1);
    }
    result->rows = matrix1->rows;
    result->cols = matrix2->cols;
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int rows1, cols1, rows2, cols2;
    printf("Enter the dimensions of the first matrix (rows cols): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the dimensions of the second matrix (rows cols): ");
    scanf("%d %d", &rows2, &cols2);
    if (cols1!= rows2) {
        printf("Error: Incompatible dimensions for matrix multiplication.\n");
        return 1;
    }
    Matrix *matrix1 = create_matrix(rows1, cols1);
    Matrix *matrix2 = create_matrix(rows2, cols2);
    Matrix *result = create_matrix(rows1, cols2);
    fill_matrix(matrix1, rand() % 10);
    fill_matrix(matrix2, rand() % 10);
    printf("Matrix 1:\n");
    print_matrix(matrix1);
    printf("Matrix 2:\n");
    print_matrix(matrix2);
    multiply_matrices(matrix1, matrix2, result);
    printf("Result:\n");
    print_matrix(result);
    free_matrix(matrix1);
    free_matrix(matrix2);
    free_matrix(result);
    return 0;
}