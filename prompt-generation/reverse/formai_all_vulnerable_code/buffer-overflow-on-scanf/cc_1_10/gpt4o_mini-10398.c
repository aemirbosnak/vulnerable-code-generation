//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrixWithRandomNumbers(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    srand(time(NULL));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100; // Random numbers between 0 and 99
        }
    }
}

void addMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrices(int first[MAX_SIZE][MAX_SIZE], int second[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsFirst, int colsFirst, int colsSecond) {
    for(int i = 0; i < rowsFirst; i++) {
        for(int j = 0; j < colsSecond; j++) {
            result[i][j] = 0; // Initialize
            for(int k = 0; k < colsFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

int main() {
    int firstMatrix[MAX_SIZE][MAX_SIZE], secondMatrix[MAX_SIZE][MAX_SIZE];
    int sumMatrix[MAX_SIZE][MAX_SIZE], mulMatrix[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    // User input for matrix size
    printf("Enter number of rows and columns for matrices (max %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);
    
    if(rows > MAX_SIZE || cols > MAX_SIZE || rows <= 0 || cols <= 0) {
        printf("Invalid matrix size! Please ensure size is between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Fill matrices with random values
    fillMatrixWithRandomNumbers(firstMatrix, rows, cols);
    fillMatrixWithRandomNumbers(secondMatrix, rows, cols);

    // Print the matrices
    printf("\nFirst Matrix:\n");
    printMatrix(firstMatrix, rows, cols);
    
    printf("\nSecond Matrix:\n");
    printMatrix(secondMatrix, rows, cols);

    // Adding matrices
    addMatrices(firstMatrix, secondMatrix, sumMatrix, rows, cols);
    printf("\nSum of the two matrices:\n");
    printMatrix(sumMatrix, rows, cols);

    // For multiplication, ensure valid dimensions
    if (cols <= MAX_SIZE) {
        printf("\nMultiplying the first matrix with its transpose:\n");
        int transpose[MAX_SIZE][MAX_SIZE];
        
        // Transpose second matrix for multiplication
        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < rows; j++) {
                transpose[i][j] = secondMatrix[j][i];
            }
        }

        multiplyMatrices(firstMatrix, transpose, mulMatrix, rows, cols, rows);
        printMatrix(mulMatrix, rows, rows);
    } else {
        printf("Cannot multiply due to dimension restrictions.\n");
    }
    
    return 0;
}