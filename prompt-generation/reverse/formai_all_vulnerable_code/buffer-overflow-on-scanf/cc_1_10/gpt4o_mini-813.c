//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int rows;
    int cols;
    int data[MAX_SIZE][MAX_SIZE];
} Matrix;

void inputMatrix(Matrix* matrix) {
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &matrix->rows, &matrix->cols);
    
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < matrix->rows; i++) {
        for(int j = 0; j < matrix->cols; j++) {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

void displayMatrix(const Matrix* matrix) {
    printf("Matrix (%dx%d):\n", matrix->rows, matrix->cols);
    for(int i = 0; i < matrix->rows; i++) {
        for(int j = 0; j < matrix->cols; j++) {
            printf("%d ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix addMatrices(const Matrix* a, const Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Matrix dimensions do not match for addition!\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = { .rows = a->rows, .cols = a->cols };

    for(int i = 0; i < result.rows; i++) {
        for(int j = 0; j < result.cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix multiplyMatrices(const Matrix* a, const Matrix* b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Matrix dimensions do not allow multiplication!\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = { .rows = a->rows, .cols = b->cols };

    for(int i = 0; i < result.rows; i++) {
        for(int j = 0; j < result.cols; j++) {
            result.data[i][j] = 0;
            for(int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

Matrix transposeMatrix(const Matrix* matrix) {
    Matrix result = { .rows = matrix->cols, .cols = matrix->rows };

    for(int i = 0; i < matrix->rows; i++) {
        for(int j = 0; j < matrix->cols; j++) {
            result.data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}

int main() {
    Matrix matrixA, matrixB, sum, product, transposed;

    printf("Input for Matrix A:\n");
    inputMatrix(&matrixA);
    displayMatrix(&matrixA);

    printf("Input for Matrix B:\n");
    inputMatrix(&matrixB);
    displayMatrix(&matrixB);

    sum = addMatrices(&matrixA, &matrixB);
    printf("Sum of Matrix A and Matrix B:\n");
    displayMatrix(&sum);
    
    product = multiplyMatrices(&matrixA, &matrixB);
    printf("Product of Matrix A and Matrix B:\n");
    displayMatrix(&product);

    transposed = transposeMatrix(&matrixA);
    printf("Transpose of Matrix A:\n");
    displayMatrix(&transposed);

    return 0;
}