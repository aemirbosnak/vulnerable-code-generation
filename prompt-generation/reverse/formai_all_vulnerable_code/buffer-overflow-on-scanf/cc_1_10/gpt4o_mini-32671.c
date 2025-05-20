//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void getMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the matrix elements:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for(int i = 0; i < rows1; i++) {
        for(int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    int choice;

    printf("Welcome to the Multiplayer Matrix Operations Program!\n");

    printf("Player 1, enter the dimensions for Matrix 1 (rows and columns): ");
    scanf("%d %d", &rows1, &cols1);
    getMatrix(matrix1, rows1, cols1);
    printMatrix(matrix1, rows1, cols1);

    printf("Player 2, enter the dimensions for Matrix 2 (rows and columns): ");
    scanf("%d %d", &rows2, &cols2);
    getMatrix(matrix2, rows2, cols2);
    printMatrix(matrix2, rows2, cols2);

    if (rows1 == rows2 && cols1 == cols2) {
        printf("\nChoose operation:\n1. Addition\n2. Subtraction\n");
        scanf("%d", &choice);
        if (choice == 1) {
            addMatrices(matrix1, matrix2, result, rows1, cols1);
            printf("Result of Addition:\n");
            printMatrix(result, rows1, cols1);
        } else if (choice == 2) {
            subtractMatrices(matrix1, matrix2, result, rows1, cols1);
            printf("Result of Subtraction:\n");
            printMatrix(result, rows1, cols1);
        } else {
            printf("Invalid choice!\n");
        }
    } else if (cols1 == rows2) {
        printf("\nMatrix multiplication is possible.\n");
        multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
        printf("Result of Multiplication:\n");
        printMatrix(result, rows1, cols2);
    } else {
        printf("Matrix operations cannot be performed due to incompatible dimensions.\n");
    }

    return 0;
}