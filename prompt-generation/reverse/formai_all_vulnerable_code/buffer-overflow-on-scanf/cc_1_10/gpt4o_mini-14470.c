//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function prototypes
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB, choice;

    printf("Welcome to the Artistic Matrix Operations Program!\n");
    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Now please enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Now please enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    do {
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Multiply Matrices\n");
        printf("3. Transpose Matrix A\n");
        printf("4. Transpose Matrix B\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(matrixA, matrixB, result, rowsA, colsA);
                    printf("Resultant Matrix after Addition:\n");
                    displayMatrix(result, rowsA, colsA);
                } else {
                    printf("Error: Matrices cannot be added due to mismatched dimensions.\n");
                }
                break;
            case 2:
                if (colsA == rowsB) {
                    multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB);
                    printf("Resultant Matrix after Multiplication:\n");
                    displayMatrix(result, rowsA, colsB);
                } else {
                    printf("Error: Matrices cannot be multiplied due to incompatible dimensions.\n");
                }
                break;
            case 3:
                transposeMatrix(matrixA, result, rowsA, colsA);
                printf("Transpose of Matrix A:\n");
                displayMatrix(result, colsA, rowsA);
                break;
            case 4:
                transposeMatrix(matrixB, result, rowsB, colsB);
                printf("Transpose of Matrix B:\n");
                displayMatrix(result, colsB, rowsB);
                break;
            case 5:
                printf("Thank you for using the Artistic Matrix Operations Program! Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add two matrices
void addMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], 
                 int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], 
                      int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], 
                     int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}