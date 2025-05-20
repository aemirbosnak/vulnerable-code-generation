//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function declarations
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);

int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    
    // Input for first matrix
    printf("Enter the number of rows and columns for Matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter elements of Matrix 1:\n");
    inputMatrix(mat1, rows1, cols1);
    
    // Input for second matrix
    printf("Enter the number of rows and columns for Matrix 2: ");
    scanf("%d %d", &rows2, &cols2);
    
    printf("Enter elements of Matrix 2:\n");
    inputMatrix(mat2, rows2, cols2);
    
    // Check if addition and subtraction are possible
    if (rows1 == rows2 && cols1 == cols2) {
        printf("\nSum of matrices:\n");
        addMatrices(mat1, mat2, result, rows1, cols1);
        printMatrix(result, rows1, cols1);
        
        printf("\nDifference of matrices:\n");
        subtractMatrices(mat1, mat2, result, rows1, cols1);
        printMatrix(result, rows1, cols1);
    } else {
        printf("Addition and subtraction are not possible for the given matrices.\n");
    }
    
    // Check if multiplication is possible
    if (cols1 == rows2) {
        printf("\nProduct of matrices:\n");
        multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
        printMatrix(result, rows1, cols2);
    } else {
        printf("Multiplication is not possible for the given matrices.\n");
    }
    
    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}