//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Resulting Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX], transposed[MAX][MAX];
    int rows1, cols1, rows2, cols2;
    
    // Input the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(mat1, rows1, cols1);
    
    // Input the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    
    // Check for valid matrix operations
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Matrices must be of the same dimension for addition and subtraction.\n");
        return -1;
    }
    
    inputMatrix(mat2, rows2, cols2);
    
    // Matrix Addition
    addMatrices(mat1, mat2, result, rows1, cols1);
    printMatrix(result, rows1, cols1);

    // Matrix Subtraction
    subtractMatrices(mat1, mat2, result, rows1, cols1);
    printMatrix(result, rows1, cols1);

    // Matrix Multiplication
    printf("Matrix multiplication requires second matrix columns to match first matrix rows.\n");
    printf("Enter the number of columns for the second matrix: ");
    int newCols2;
    scanf("%d", &newCols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return -1;
    }
    // Get new matrix for multiplication
    inputMatrix(mat2, rows2, newCols2);
    
    multiplyMatrices(mat1, mat2, result, rows1, cols1, newCols2);
    printMatrix(result, rows1, newCols2);

    // Transpose of First Matrix
    transposeMatrix(mat1, transposed, rows1, cols1);
    printMatrix(transposed, cols1, rows1);

    return 0;
}