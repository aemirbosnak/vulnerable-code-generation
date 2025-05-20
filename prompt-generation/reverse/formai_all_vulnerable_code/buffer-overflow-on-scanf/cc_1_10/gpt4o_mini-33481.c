//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX]; 
    int rows1, cols1, rows2, cols2;

    // Input for the first matrix
    printf("Enter the number of rows and columns for the first matrix (space separated): ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }

    // Input for the second matrix
    printf("Enter the number of rows and columns for the second matrix (space separated): ");
    scanf("%d %d", &rows2, &cols2);
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }

    // Display the matrices
    printf("\nMatrix 1:\n");
    displayMatrix(matrix1, rows1, cols1);
    printf("\nMatrix 2:\n");
    displayMatrix(matrix2, rows2, cols2);

    // Addition of matrices
    printf("\nAdding the matrices:\n");
    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Addition not possible! Matrices must have the same dimensions.\n");
    }

    // Subtraction of matrices
    printf("\nSubtracting the matrices:\n");
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(matrix1, matrix2, result, rows1, cols1);
        displayMatrix(result, rows1, cols1);
    } else {
        printf("Subtraction not possible! Matrices must have the same dimensions.\n");
    }

    // Multiplication of matrices
    printf("\nMultiplying the matrices:\n");
    if (cols1 == rows2) {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        displayMatrix(result, rows1, cols2);
    } else {
        printf("Multiplication not possible! Number of columns in first matrix must equal number of rows in second matrix.\n");
    }

    // Transposing matrix 1
    printf("\nTransposing the first matrix:\n");
    transposeMatrix(matrix1, result, rows1, cols1);
    displayMatrix(result, cols1, rows1);

    // Transposing matrix 2
    printf("\nTransposing the second matrix:\n");
    transposeMatrix(matrix2, result, rows2, cols2);
    displayMatrix(result, cols2, rows2);

    return 0;
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // initialize to 0 first
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}