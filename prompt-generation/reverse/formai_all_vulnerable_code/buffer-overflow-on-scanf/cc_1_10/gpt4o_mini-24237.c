//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
double** allocateMatrix(int rows, int cols) {
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input a matrix from the user
void inputMatrix(double **matrix, int rows, int cols) {
    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(double **matrix, int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
double** addMatrices(double **matrix1, double **matrix2, int rows, int cols) {
    double **result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices
double** multiplyMatrices(double **matrix1, int rows1, int cols1, 
                          double **matrix2, int cols2) {
    double **result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to transpose a matrix
double** transposeMatrix(double **matrix, int rows, int cols) {
    double **transposed = allocateMatrix(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    double **matrix1 = allocateMatrix(rows1, cols1);
    inputMatrix(matrix1, rows1, cols1);
    printMatrix(matrix1, rows1, cols1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (rows2 != rows1 || cols2 != cols1) {
        printf("Matrix addition requires both matrices to be the same size!\n");
        freeMatrix(matrix1, rows1);
        return 1;
    }
    
    double **matrix2 = allocateMatrix(rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);
    printMatrix(matrix2, rows2, cols2);

    double **addedMatrix = addMatrices(matrix1, matrix2, rows1, cols1);
    printMatrix(addedMatrix, rows1, cols1);

    // Note: Multiplication requires appropriate dimensions
    if (cols1 != rows2) {
        printf("Matrix multiplication cannot be performed due to size mismatch!\n");
        freeMatrix(matrix1, rows1);
        freeMatrix(matrix2, rows2);
        freeMatrix(addedMatrix, rows1);
        return 1;
    }

    double **multipliedMatrix = multiplyMatrices(matrix1, rows1, cols1, matrix2, cols2);
    printMatrix(multipliedMatrix, rows1, cols2);

    double **transposedMatrix1 = transposeMatrix(matrix1, rows1, cols1);
    printf("Transposed first matrix:\n");
    printMatrix(transposedMatrix1, cols1, rows1);

    double **transposedMatrix2 = transposeMatrix(matrix2, rows2, cols2);
    printf("Transposed second matrix:\n");
    printMatrix(transposedMatrix2, cols2, rows2);

    // Freeing the allocated memory
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(addedMatrix, rows1);
    freeMatrix(multipliedMatrix, rows1);
    freeMatrix(transposedMatrix1, cols1);
    freeMatrix(transposedMatrix2, cols2);

    return 0;
}