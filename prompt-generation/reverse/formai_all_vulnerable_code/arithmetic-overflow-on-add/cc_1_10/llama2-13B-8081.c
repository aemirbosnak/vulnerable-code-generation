//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int *data;
} Matrix;

// Function to create a matrix with the given dimensions
Matrix* createMatrix(int rows, int cols) {
    Matrix* mat = (Matrix*) malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int*) malloc(sizeof(int) * rows * cols);
    return mat;
}

// Function to print a matrix
void printMatrix(Matrix* mat) {
    int i, j;
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            printf("%d ", mat->data[i * mat->cols + j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix* addMatrix(Matrix* mat1, Matrix* mat2) {
    int i, j, k;
    Matrix* result = createMatrix(mat1->rows, mat2->cols);
    for (i = 0; i < mat1->rows; i++) {
        for (j = 0; j < mat2->cols; j++) {
            int sum = mat1->data[i * mat1->cols + j] + mat2->data[i * mat2->cols + j];
            result->data[i * result->cols + j] = sum % 10;
        }
    }
    return result;
}

// Function to multiply a matrix by a scalar
Matrix* scaleMatrix(Matrix* mat, int scale) {
    int i, j;
    Matrix* result = createMatrix(mat->rows, mat->cols);
    for (i = 0; i < mat->rows; i++) {
        for (j = 0; j < mat->cols; j++) {
            result->data[i * result->cols + j] = mat->data[i * mat->cols + j] * scale;
        }
    }
    return result;
}

// Function to transpose a matrix
Matrix* transposeMatrix(Matrix* mat) {
    int i, j, k;
    Matrix* result = createMatrix(mat->cols, mat->rows);
    for (i = 0; i < mat->cols; i++) {
        for (j = 0; j < mat->rows; j++) {
            result->data[i * result->rows + j] = mat->data[j * mat->cols + i];
        }
    }
    return result;
}

int main() {
    Matrix* mat1 = createMatrix(3, 4);
    Matrix* mat2 = createMatrix(4, 3);
    Matrix* result = addMatrix(mat1, mat2);
    printMatrix(result);

    result = scaleMatrix(result, 2);
    printMatrix(result);

    result = transposeMatrix(result);
    printMatrix(result);

    return 0;
}