//FormAI DATASET v1.0 Category: Matrix operations ; Style: decentralized
/* C Matrix Operations Example Program */

#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printMatrix(int **matrix, int rows, int cols);
void addMatrix(int **matrixA, int **matrixB, int **matrixC, int rows, int cols);
void subtractMatrix(int **matrixA, int **matrixB, int **matrixC, int rows, int cols);
void multiplyMatrix(int **matrixA, int **matrixB, int **matrixC, int rowsA, int colsA, int colsB);
int **createMatrix(int rows, int cols);

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Creating matrices
    int **matrixA = createMatrix(rows, cols);
    int **matrixB = createMatrix(rows, cols);
    int **matrixC = createMatrix(rows, cols);

    printf("Enter values for matrix A:\n");
    // Taking input for matrixA
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter values for matrix B:\n");
    // Taking input for matrixB
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Printing matrices
    printf("Matrix A:\n");
    printMatrix(matrixA, rows, cols);
    printf("\nMatrix B:\n");
    printMatrix(matrixB, rows, cols);

    // Adding matrices
    addMatrix(matrixA, matrixB, matrixC, rows, cols);

    // Printing added matrix
    printf("\nMatrix A + B:\n");
    printMatrix(matrixC, rows, cols);

    // Subtracting matrices
    subtractMatrix(matrixA, matrixB, matrixC, rows, cols);

    // Printing subtracted matrix
    printf("\nMatrix A - B:\n");
    printMatrix(matrixC, rows, cols);

    // Multiplying matrices
    multiplyMatrix(matrixA, matrixB, matrixC, rows, cols, cols);

    // Printing multiplied matrix
    printf("\nMatrix A * B:\n");
    printMatrix(matrixC, rows, cols);

    // Freeing up memory
    for(int i = 0;i < rows;i++) {
        free(matrixA[i]);
        free(matrixB[i]);
        free(matrixC[i]);
    }
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0;
}

// Function for creating a matrix dynamically
int **createMatrix(int rows, int cols) {
    int **matrix = (int **)calloc(rows, sizeof(int *));
    for (int i = 0;i < rows;i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
    }
    return matrix;
}

// Function for printing a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for adding two matrices
void addMatrix(int **matrixA, int **matrixB, int **matrixC, int rows, int cols) {
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// Function for subtracting two matrices
void subtractMatrix(int **matrixA, int **matrixB, int **matrixC, int rows, int cols) {
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < cols;j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

// Function for multiplying two matrices
void multiplyMatrix(int **matrixA, int **matrixB, int **matrixC, int rowsA, int colsA, int colsB) {
    for (int i = 0;i < rowsA;i++) {
        for (int j = 0;j < colsB;j++) {
            for (int k = 0;k < colsA;k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}