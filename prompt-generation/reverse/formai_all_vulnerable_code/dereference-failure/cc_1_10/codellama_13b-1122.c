//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a matrix
typedef struct {
    int rows;
    int cols;
    int* data;
} Matrix;

// Define a function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int*)malloc(rows * cols * sizeof(int));
    return mat;
}

// Define a function to display a matrix
void displayMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i * mat.cols + j]);
        }
        printf("\n");
    }
}

// Define a function to perform matrix addition
Matrix addMatrix(Matrix mat1, Matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("Matrices cannot be added\n");
        return mat1;
    }
    Matrix mat3 = createMatrix(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            mat3.data[i * mat3.cols + j] = mat1.data[i * mat1.cols + j] + mat2.data[i * mat2.cols + j];
        }
    }
    return mat3;
}

// Define a function to perform matrix multiplication
Matrix multiplyMatrix(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Matrices cannot be multiplied\n");
        return mat1;
    }
    Matrix mat3 = createMatrix(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            int sum = 0;
            for (int k = 0; k < mat1.cols; k++) {
                sum += mat1.data[i * mat1.cols + k] * mat2.data[k * mat2.cols + j];
            }
            mat3.data[i * mat3.cols + j] = sum;
        }
    }
    return mat3;
}

// Define a function to perform matrix transpose
Matrix transposeMatrix(Matrix mat) {
    Matrix mat2 = createMatrix(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            mat2.data[j * mat2.cols + i] = mat.data[i * mat.cols + j];
        }
    }
    return mat2;
}

int main() {
    Matrix mat1 = createMatrix(3, 3);
    Matrix mat2 = createMatrix(3, 3);
    Matrix mat3;
    int i, j;

    // Initialize matrices
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mat1.data[i * mat1.cols + j] = i + j;
            mat2.data[i * mat2.cols + j] = j + i;
        }
    }

    // Display matrices
    displayMatrix(mat1);
    displayMatrix(mat2);

    // Perform matrix addition
    mat3 = addMatrix(mat1, mat2);
    printf("Matrix addition:\n");
    displayMatrix(mat3);

    // Perform matrix multiplication
    mat3 = multiplyMatrix(mat1, mat2);
    printf("Matrix multiplication:\n");
    displayMatrix(mat3);

    // Perform matrix transpose
    mat3 = transposeMatrix(mat1);
    printf("Matrix transpose:\n");
    displayMatrix(mat3);

    return 0;
}