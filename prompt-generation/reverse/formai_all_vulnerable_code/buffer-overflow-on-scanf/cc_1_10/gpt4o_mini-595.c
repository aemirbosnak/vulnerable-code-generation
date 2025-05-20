//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0; // Initialize result
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Matrix Operations Program\n");
    printf("===========================\n");

    printf("Input for Matrix 1:\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows1, &cols1);
    inputMatrix(matrix1, rows1, cols1);
    displayMatrix(matrix1, rows1, cols1);

    printf("\nInput for Matrix 2:\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows2, &cols2);
    inputMatrix(matrix2, rows2, cols2);
    displayMatrix(matrix2, rows2, cols2);

    // Ensure compatibility for addition and subtraction
    if (rows1 == rows2 && cols1 == cols2) {
        int sum[MAX_SIZE][MAX_SIZE];
        int difference[MAX_SIZE][MAX_SIZE];

        addMatrices(matrix1, matrix2, sum, rows1, cols1);
        subtractMatrices(matrix1, matrix2, difference, rows1, cols1);

        printf("\nSum of the matrices:\n");
        displayMatrix(sum, rows1, cols1);
        
        printf("\nDifference of the matrices:\n");
        displayMatrix(difference, rows1, cols1);
    } else {
        printf("\nMatrix addition and subtraction are not possible due to dimension mismatch.\n");
    }
    
    // Ensure compatibility for multiplication
    if (cols1 == rows2) {
        int product[MAX_SIZE][MAX_SIZE];
        multiplyMatrices(matrix1, matrix2, product, rows1, cols1, cols2);

        printf("\nProduct of the matrices:\n");
        displayMatrix(product, rows1, cols2);
    } else {
        printf("\nMatrix multiplication is not possible due to dimension mismatch.\n");
    }

    return 0;
}