//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void printMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows1, int cols1, int cols2);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int rows1, cols1, rows2, cols2;

    // The entrance to Matrix Wonderland
    printf("Welcome to the Matrix Wonderland!\n");
    printf("Enter dimensions for the first matrix:\n");
    printf("Rows: ");
    scanf("%d", &rows1);
    printf("Columns: ");
    scanf("%d", &cols1);
    
    printf("How delightful! Now, enter the elements of the first matrix:\n");
    inputMatrix(mat1, rows1, cols1);

    printf("Now, let's enter dimensions for the second matrix:\n");
    printf("Rows: ");
    scanf("%d", &rows2);
    printf("Columns: ");
    scanf("%d", &cols2);
    
    printf("Splendid! Please fill the second matrix:\n");
    inputMatrix(mat2, rows2, cols2);

    // Only perform operations if dimensions match
    if (rows1 != rows2 || cols1 != cols2) {
        printf("Alas! The matrices are not of the same dimensions for addition and subtraction.\n");
    } else {
        printf("\nFirst Matrix:\n");
        printMatrix(mat1, rows1, cols1);
        
        printf("\nSecond Matrix:\n");
        printMatrix(mat2, rows2, cols2);
        
        // Sum of matrices
        addMatrices(mat1, mat2, result, rows1, cols1);
        printf("\nThe sum of the matrices:\n");
        printMatrix(result, rows1, cols1);
        
        // Difference of matrices
        subtractMatrices(mat1, mat2, result, rows1, cols1);
        printf("\nThe difference of the matrices:\n");
        printMatrix(result, rows1, cols1);
    }

    // Multiplication if valid dimensions
    if (cols1 == rows2) {
        multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
        printf("\nThe product of the matrices:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Unfortunately! These matrices cannot be multiplied together.\n");
    }

    // Transpose of the first matrix
    transposeMatrix(mat1, result, rows1, cols1);
    printf("\nThe transpose of the first matrix:\n");
    printMatrix(result, cols1, rows1);

    // Transpose of the second matrix
    transposeMatrix(mat2, result, rows2, cols2);
    printf("\nThe transpose of the second matrix:\n");
    printMatrix(result, cols2, rows2);

    // Departing from Matrix Wonderland
    printf("Thank you for visiting Matrix Wonderland! Come again!\n");
    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
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

void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}