//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int** allocateMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
void inputMatrix(int** matrix, int rows, int cols);
void outputMatrix(int** matrix, int rows, int cols);
void multiplyMatrices(int** a, int** b, int** result, int aRows, int aCols, int bCols);
int validateMatrixSize(int size);

int main() {
    int aRows, aCols, bRows, bCols;

    printf("Enter the number of rows and columns for Matrix A: ");
    if (scanf("%d %d", &aRows, &aCols) != 2 || !validateMatrixSize(aRows) || !validateMatrixSize(aCols)) {
        fprintf(stderr, "Invalid input for Matrix A size. Please enter positive integers.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the number of rows and columns for Matrix B: ");
    if (scanf("%d %d", &bRows, &bCols) != 2 || !validateMatrixSize(bRows) || !validateMatrixSize(bCols) || aCols != bRows) {
        fprintf(stderr, "Invalid input for Matrix B size or dimensions do not match for multiplication.\n");
        return EXIT_FAILURE;
    }

    // Allocate memory for matrices
    int** matrixA = allocateMatrix(aRows, aCols);
    int** matrixB = allocateMatrix(bRows, bCols);
    int** matrixC = allocateMatrix(aRows, bCols);

    // Input data for matrices
    printf("Input elements for Matrix A:\n");
    inputMatrix(matrixA, aRows, aCols);

    printf("Input elements for Matrix B:\n");
    inputMatrix(matrixB, bRows, bCols);

    // Perform matrix multiplication
    multiplyMatrices(matrixA, matrixB, matrixC, aRows, aCols, bCols);

    // Output resultant matrix
    printf("Resultant Matrix C (A * B):\n");
    outputMatrix(matrixC, aRows, bCols);

    // Free allocated memory
    freeMatrix(matrixA, aRows);
    freeMatrix(matrixB, bRows);
    freeMatrix(matrixC, aRows);

    return EXIT_SUCCESS;
}

// Allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed for matrix rows.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for matrix columns.\n");
            freeMatrix(matrix, i); // Free previously allocated rows
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

// Free allocated matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Input elements into a matrix
void inputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input. Please enter integers only.\n");
                freeMatrix(matrix, rows);
                exit(EXIT_FAILURE);
            }
        }
    }
}

// Output elements of a matrix
void outputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Multiply two matrices
void multiplyMatrices(int** a, int** b, int** result, int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Validate matrix size
int validateMatrixSize(int size) {
    return size > 0;
}