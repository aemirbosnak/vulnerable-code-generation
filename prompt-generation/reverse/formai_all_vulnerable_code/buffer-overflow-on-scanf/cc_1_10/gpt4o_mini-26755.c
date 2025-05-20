//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void printMatrix(int **matrix, int rows, int cols);
int **createMatrix(int rows, int cols);
void freeMatrix(int **matrix, int rows);
int **addMatrices(int **matrixA, int **matrixB, int rows, int cols);
int **multiplyMatrices(int **matrixA, int **matrixB, int m, int n, int p);

int main() {
    int rowsA, colsA;
    int rowsB, colsB;

    // Welcome message
    printf("Welcome to the Matrix Operations Program!\n");
    printf("Let's create and perform operations on two matrices.\n");
    
    // Getting dimensions for the first matrix
    printf("Enter the number of rows and columns for Matrix A (e.g., 2 3): ");
    scanf("%d %d", &rowsA, &colsA);

    // Creating the first matrix
    int **matrixA = createMatrix(rowsA, colsA);
    printf("Enter the elements for Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Getting dimensions for the second matrix
    printf("Enter the number of rows and columns for Matrix B (e.g., 3 2): ");
    scanf("%d %d", &rowsB, &colsB);

    // Check for matrix addition compatibility
    if (rowsA != rowsB || colsA != colsB) {
        printf("Matrices A and B must have the same dimensions for addition!\n");
        freeMatrix(matrixA, rowsA);
        return -1;
    }

    // Creating the second matrix
    int **matrixB = createMatrix(rowsB, colsB);
    printf("Enter the elements for Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Printing the matrices
    printf("\nMatrix A:\n");
    printMatrix(matrixA, rowsA, colsA);
    printf("\nMatrix B:\n");
    printMatrix(matrixB, rowsB, colsB);

    // Adding the matrices
    int **sumMatrix = addMatrices(matrixA, matrixB, rowsA, colsA);
    printf("\nResult of Matrix A + Matrix B:\n");
    printMatrix(sumMatrix, rowsA, colsA);

    // Check for matrix multiplication compatibility
    if (colsA != rowsB) {
        printf("Error: Columns of Matrix A must match rows of Matrix B for multiplication!\n");
        freeMatrix(matrixA, rowsA);
        freeMatrix(matrixB, rowsB);
        freeMatrix(sumMatrix, rowsA);
        return -1;
    }

    // Multiplying the matrices
    int **productMatrix = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
    printf("\nResult of Matrix A * Matrix B:\n");
    printMatrix(productMatrix, rowsA, colsB);

    // Free allocated memory
    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    freeMatrix(sumMatrix, rowsA);
    freeMatrix(productMatrix, rowsA);

    // End of program
    printf("\nThank you for using the Matrix Operations Program! Goodbye!\n");
    return 0;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int **createMatrix(int rows, int cols) {
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

int **addMatrices(int **matrixA, int **matrixB, int rows, int cols) {
    int **sum = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return sum;
}

int **multiplyMatrices(int **matrixA, int **matrixB, int m, int n, int p) {
    int **product = createMatrix(m, p);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            product[i][j] = 0;
            for (int k = 0; k < n; k++) {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    return product;
}