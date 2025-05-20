//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter dimensions for Matrix 1 (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(matrix1, rows1, cols1);

    printf("Enter dimensions for Matrix 2 (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(matrix2, rows2, cols2);

    // Matrix Addition
    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);
    
    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);

    if (rows1 == rows2 && cols1 == cols2) {
        addMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("Sum of Matrix 1 and Matrix 2:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Matrices cannot be added due to dimension mismatch.\n");
    }

    // Matrix Subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        subtractMatrices(matrix1, matrix2, result, rows1, cols1);
        printf("Difference of Matrix 1 and Matrix 2:\n");
        printMatrix(result, rows1, cols1);
    } else {
        printf("Matrices cannot be subtracted due to dimension mismatch.\n");
    }

    // Matrix Multiplication
    if (cols1 == rows2) {
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
        printf("Product of Matrix 1 and Matrix 2:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Matrices cannot be multiplied due to dimension mismatch.\n");
    }

    // Matrix Transposition
    transposeMatrix(matrix1, transposed, rows1, cols1);
    printf("Transpose of Matrix 1:\n");
    printMatrix(transposed, cols1, rows1);

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] + mat2[i][j];
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = mat1[i][j] - mat2[i][j];
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < cols1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            transposed[j][i] = matrix[i][j];
}