//FormAI DATASET v1.0 Category: Matrix operations ; Style: thoughtful
// This program is an example of matrix operations in C programming language
// Written by a thoughtful developer!

#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void displayMatrix(int matrix[][MAX_COLS], int rows, int cols);
void addMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int result[][MAX_COLS], int rows, int cols);
void subtractMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int result[][MAX_COLS], int rows, int cols);
void multiplyMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int result[][MAX_COLS], int rowsA, int colsA, int colsB);
void transposeMatrix(int matrix[][MAX_COLS], int result[][MAX_ROWS], int rows, int cols);

int main() {
    int matrixA[MAX_ROWS][MAX_COLS], matrixB[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS], transposeResult[MAX_COLS][MAX_ROWS];
    int rows, cols, choice;

    printf("Enter number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    printf("Enter matrix A:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("Matrix A:\n");
    displayMatrix(matrixA, rows, cols);
    printf("Matrix B:\n");
    displayMatrix(matrixB, rows, cols);

    printf("\nMatrix operations:\n1. Add matrices\n2. Subtract matrices\n3. Multiply Matrices\n4. Transpose matrix A\n5. Transpose matrix B\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addMatrices(matrixA, matrixB, result, rows, cols);
            printf("Result of A + B:\n");
            displayMatrix(result, rows, cols);
            break;
        case 2:
            subtractMatrices(matrixA, matrixB, result, rows, cols);
            printf("Result of A - B:\n");
            displayMatrix(result, rows, cols);
            break;
        case 3:
            multiplyMatrices(matrixA, matrixB, result, rows, cols, cols);
            printf("Result of A * B:\n");
            displayMatrix(result, rows, cols);
            break;
        case 4:
            transposeMatrix(matrixA, transposeResult, rows, cols);
            printf("Transpose of A:\n");
            displayMatrix(transposeResult, cols, rows);
            break;
        case 5:
            transposeMatrix(matrixB, transposeResult, rows, cols);
            printf("Transpose of B:\n");
            displayMatrix(transposeResult, cols, rows);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}

void displayMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int result[][MAX_COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void subtractMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int result[][MAX_COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int result[][MAX_COLS], int rowsA, int colsA, int colsB) {
    for(int i=0; i<rowsA; i++) {
        for(int j=0; j<colsB; j++) {
            result[i][j] = 0;
            for(int k=0; k<colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][MAX_COLS], int result[][MAX_ROWS], int rows, int cols) {
    for(int i=0; i<cols; i++) {
        for(int j=0; j<rows; j++) {
            result[i][j] = matrix[j][i];
        }
    }
}