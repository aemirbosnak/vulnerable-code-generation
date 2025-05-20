//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void allocateMatrix(int ***matrix, int rows, int cols) {
    *matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = (int *)malloc(cols * sizeof(int));
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrix(int **matrix, int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void outputMatrix(int **matrix, int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int **matrix1, int **matrix2, int ***result, int rows1, int cols1, int cols2) {
    allocateMatrix(result, rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            (*result)[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                (*result)[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int **matrix, int ***result, int rows, int cols) {
    allocateMatrix(result, cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            (*result)[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input for first matrix
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    int **matrix1;
    allocateMatrix(&matrix1, rows1, cols1);
    inputMatrix(matrix1, rows1, cols1);
    outputMatrix(matrix1, rows1, cols1);
    
    // Input for second matrix
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrix addition/subtraction not possible! Dimensions must match.\n");
        freeMatrix(matrix1, rows1);
        return 1;
    }
    
    int **matrix2;
    allocateMatrix(&matrix2, rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);
    outputMatrix(matrix2, rows2, cols2);

    // Adding matrices
    int **sum;
    allocateMatrix(&sum, rows1, cols1);
    addMatrices(matrix1, matrix2, sum, rows1, cols1);
    printf("Sum of the matrices:\n");
    outputMatrix(sum, rows1, cols1);
    
    // Subtracting matrices
    int **difference;
    allocateMatrix(&difference, rows1, cols1);
    subtractMatrices(matrix1, matrix2, difference, rows1, cols1);
    printf("Difference of the matrices:\n");
    outputMatrix(difference, rows1, cols1);
    
    // Multiplying matrices
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible! Columns of first must match rows of second.\n");
    } else {
        int **product;
        multiplyMatrices(matrix1, matrix2, &product, rows1, cols1, cols2);
        printf("Product of the matrices:\n");
        outputMatrix(product, rows1, cols2);
        freeMatrix(product, rows1);
    }

    // Transpose of the first matrix
    int **transpose;
    transposeMatrix(matrix1, &transpose, rows1, cols1);
    printf("Transpose of the first matrix:\n");
    outputMatrix(transpose, cols1, rows1);

    // Cleanup
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(sum, rows1);
    freeMatrix(difference, rows1);
    freeMatrix(transpose, cols1);

    return 0;
}