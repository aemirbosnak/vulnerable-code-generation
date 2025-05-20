//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** createMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void addMatrices(int **a, int **b, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int **a, int **b, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int **a, int **b, int **result, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int **a, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = a[i][j];
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows for the matrices: ");
    scanf("%d", &rows);
    printf("Enter the number of columns for the matrices: ");
    scanf("%d", &cols);

    // Create matrices
    int **matrixA = createMatrix(rows, cols);
    int **matrixB = createMatrix(rows, cols);
    int **resultAdd = createMatrix(rows, cols);
    int **resultSubtract = createMatrix(rows, cols);
    int **resultMultiply = createMatrix(rows, cols);
    int **transposeA = createMatrix(cols, rows);
    
    // Input matrices
    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Perform operations
    addMatrices(matrixA, matrixB, resultAdd, rows, cols);
    subtractMatrices(matrixA, matrixB, resultSubtract, rows, cols);
    multiplyMatrices(matrixA, matrixB, resultMultiply, rows, cols, cols);
    transposeMatrix(matrixA, transposeA, rows, cols);

    // Display results
    printf("\nMatrix A:\n");
    printMatrix(matrixA, rows, cols);

    printf("\nMatrix B:\n");
    printMatrix(matrixB, rows, cols);

    printf("\nAddition Result:\n");
    printMatrix(resultAdd, rows, cols);

    printf("\nSubtraction Result:\n");
    printMatrix(resultSubtract, rows, cols);

    printf("\nMultiplication Result:\n");
    printMatrix(resultMultiply, rows, cols);

    printf("\nTranspose of Matrix A:\n");
    printMatrix(transposeA, cols, rows);

    // Free allocated memory
    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(resultAdd, rows);
    freeMatrix(resultSubtract, rows);
    freeMatrix(resultMultiply, rows);
    freeMatrix(transposeA, cols);

    return 0;
}