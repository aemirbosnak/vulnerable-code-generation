//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int rows;
    int cols;
    double data[MAX_ROWS][MAX_COLS];
} Matrix;

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix dimensions exceed maximum limit.\n");
        exit(EXIT_FAILURE);
    }
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    return mat;
}

// Function to fill a matrix
void fillMatrix(Matrix *mat) {
    printf("Enter elements of the matrix (%d x %d):\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%lf", &mat->data[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(const Matrix *mat) {
    printf("Matrix (%d x %d):\n", mat->rows, mat->cols);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%6.2lf ", mat->data[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
Matrix addMatrices(const Matrix *a, const Matrix *b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Error: Matrices dimensions do not match for addition.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->rows, a->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
Matrix multiplyMatrices(const Matrix *a, const Matrix *b) {
    if (a->cols != b->rows) {
        printf("Error: Matrices dimensions do not match for multiplication.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->rows, b->cols);
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

// Function to calculate the transpose of a matrix
Matrix transposeMatrix(const Matrix *mat) {
    Matrix result = createMatrix(mat->cols, mat->rows);
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            result.data[j][i] = mat->data[i][j];
        }
    }
    return result;
}

// Main function for demonstration
int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input for first matrix
    printf("Enter dimensions for matrix A (rows and columns): ");
    scanf("%d %d", &rowsA, &colsA);
    Matrix matrixA = createMatrix(rowsA, colsA);
    fillMatrix(&matrixA);

    // Input for second matrix
    printf("Enter dimensions for matrix B (rows and columns): ");
    scanf("%d %d", &rowsB, &colsB);
    Matrix matrixB = createMatrix(rowsB, colsB);
    fillMatrix(&matrixB);
    
    // Perform addition if dimensions match
    if (rowsA == rowsB && colsA == colsB) {
        Matrix sum = addMatrices(&matrixA, &matrixB);
        printf("Sum of A and B:\n");
        printMatrix(&sum);
    } else {
        printf("Matrices A and B cannot be added due to dimension mismatch.\n");
    }

    // Perform multiplication if dimensions match
    if (colsA == rowsB) {
        Matrix product = multiplyMatrices(&matrixA, &matrixB);
        printf("Product of A and B:\n");
        printMatrix(&product);
    } else {
        printf("Matrices A and B cannot be multiplied due to dimension mismatch.\n");
    }

    // Transpose of first matrix
    Matrix transposeA = transposeMatrix(&matrixA);
    printf("Transpose of Matrix A:\n");
    printMatrix(&transposeA);

    // Clean up (In a larger program, you might want to manage memory better)
    return 0;
}