//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a matrix with specified dimensions
Matrix *createMatrix(int rows, int cols) {
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int *)malloc(rows * cols * sizeof(int));
    return matrix;
}

// Function to print a matrix
void printMatrix(Matrix *matrix) {
    int i, j;
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i * matrix->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix *addMatrix(Matrix *matrix1, Matrix *matrix2) {
    int i, j, k;
    Matrix *result = createMatrix(matrix1->rows, matrix2->cols);
    for (i = 0; i < matrix1->rows; i++) {
        for (j = 0; j < matrix2->cols; j++) {
            for (k = 0; k < matrix1->cols; k++) {
                result->data[i * result->cols + j] += matrix1->data[i * matrix1->cols + k] + matrix2->data[k * matrix2->cols + j];
            }
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix *scalarMultiply(Matrix *matrix, int scalar) {
    int i, j;
    Matrix *result = createMatrix(matrix->rows, matrix->cols);
    for (i = 0; i < matrix->rows; i++) {
        for (j = 0; j < matrix->cols; j++) {
            result->data[i * result->cols + j] = matrix->data[i * matrix->cols + j] * scalar;
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix *transpose(Matrix *matrix) {
    int i, j, k;
    Matrix *result = createMatrix(matrix->cols, matrix->rows);
    for (i = 0; i < matrix->cols; i++) {
        for (j = 0; j < matrix->rows; j++) {
            result->data[i * result->rows + j] = matrix->data[j * matrix->cols + i];
        }
    }
    return result;
}

int main() {
    Matrix *matrix1 = createMatrix(5, 4);
    Matrix *matrix2 = createMatrix(4, 5);
    Matrix *result1 = addMatrix(matrix1, matrix2);
    Matrix *result2 = scalarMultiply(matrix1, 2);
    Matrix *result3 = transpose(matrix1);

    printMatrix(matrix1);
    printMatrix(matrix2);
    printMatrix(result1);
    printMatrix(result2);
    printMatrix(result3);

    return 0;
}