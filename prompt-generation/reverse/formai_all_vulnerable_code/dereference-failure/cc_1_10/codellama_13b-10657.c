//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: excited
// Matrix Operations Example Program
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a matrix
typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

// Define a function to create a new matrix
Matrix* createMatrix(int rows, int cols) {
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = malloc(cols * sizeof(double));
    }
    return matrix;
}

// Define a function to print a matrix
void printMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%.2f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

// Define a function to add two matrices
Matrix* addMatrices(Matrix* matrix1, Matrix* matrix2) {
    Matrix* result = createMatrix(matrix1->rows, matrix1->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            result->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }
    return result;
}

// Define a function to multiply two matrices
Matrix* multiplyMatrices(Matrix* matrix1, Matrix* matrix2) {
    Matrix* result = createMatrix(matrix1->rows, matrix2->cols);
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            result->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++) {
                result->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }
    return result;
}

// Define a function to transpose a matrix
Matrix* transposeMatrix(Matrix* matrix) {
    Matrix* result = createMatrix(matrix->cols, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }
    return result;
}

int main() {
    // Create two matrices
    Matrix* matrix1 = createMatrix(3, 2);
    Matrix* matrix2 = createMatrix(2, 3);

    // Fill the matrices with random data
    for (int i = 0; i < matrix1->rows; i++) {
        for (int j = 0; j < matrix1->cols; j++) {
            matrix1->data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < matrix2->rows; i++) {
        for (int j = 0; j < matrix2->cols; j++) {
            matrix2->data[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    printf("Matrix 2:\n");
    printMatrix(matrix2);

    // Perform matrix operations
    Matrix* result1 = addMatrices(matrix1, matrix2);
    Matrix* result2 = multiplyMatrices(matrix1, matrix2);
    Matrix* result3 = transposeMatrix(matrix1);

    // Print the results
    printf("Matrix 1 + Matrix 2:\n");
    printMatrix(result1);
    printf("Matrix 1 * Matrix 2:\n");
    printMatrix(result2);
    printf("Matrix 1 Transpose:\n");
    printMatrix(result3);

    // Free the matrices
    free(matrix1->data);
    free(matrix1);
    free(matrix2->data);
    free(matrix2);
    free(result1->data);
    free(result1);
    free(result2->data);
    free(result2);
    free(result3->data);
    free(result3);

    return 0;
}