//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
int isEqual(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int rows, int cols);

int main() {
    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE], resultMatrix[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    
    printf("Enter the first matrix:\n");
    inputMatrix(firstMatrix, rowsA, colsA);
    
    printf("Enter the number of rows and columns for second matrix: ");
    scanf("%d %d", &rowsB, &colsB);
    
    printf("Enter the second matrix:\n");
    inputMatrix(secondMatrix, rowsB, colsB);
    
    if (rowsA == rowsB && colsA == colsB) {
        printf("Sum of matrices:\n");
        addMatrices(firstMatrix, secondMatrix, resultMatrix, rowsA, colsA);
        printMatrix(resultMatrix, rowsA, colsA);
    } else {
        printf("Matrices cannot be added as they are of different dimensions.\n");
    }

    if (colsA == rowsB) {
        printf("Product of matrices:\n");
        multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rowsA, colsA, rowsB, colsB);
        printMatrix(resultMatrix, rowsA, colsB);
    } else {
        printf("Matrices cannot be multiplied as columns of the first matrix do not match rows of the second matrix.\n");
    }

    // Check if matrices are equal
    if (isEqual(firstMatrix, secondMatrix, rowsA, colsA)) {
        printf("The two matrices are equal.\n");
    } else {
        printf("The two matrices are not equal.\n");
    }

    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int isEqual(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (first[i][j] != second[i][j]) {
                return 0; // Matrices are not equal
            }
        }
    }
    return 1; // Matrices are equal
}