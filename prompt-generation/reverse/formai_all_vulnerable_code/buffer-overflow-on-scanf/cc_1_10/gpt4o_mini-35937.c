//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void printMatrix(double matrix[MAX_ROWS][MAX_COLS], int rows, int cols);
void addMatrices(double first[MAX_ROWS][MAX_COLS], double second[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int rows, int cols);
void subtractMatrices(double first[MAX_ROWS][MAX_COLS], double second[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int rows, int cols);
void multiplyMatrices(double first[MAX_ROWS][MAX_COLS], double second[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int firstRows, int firstCols, int secondCols);
void transposeMatrix(double matrix[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int rows, int cols);
void fillMatrixWithRandomValues(double matrix[MAX_ROWS][MAX_COLS], int rows, int cols);

int main() {
    double firstMatrix[MAX_ROWS][MAX_COLS];
    double secondMatrix[MAX_ROWS][MAX_COLS];
    double resultMatrix[MAX_ROWS][MAX_COLS];
    int rows, cols, i;

    srand(time(NULL));

    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &cols);

    fillMatrixWithRandomValues(firstMatrix, rows, cols);
    fillMatrixWithRandomValues(secondMatrix, rows, cols);

    printf("\nFirst Matrix:\n");
    printMatrix(firstMatrix, rows, cols);
    
    printf("\nSecond Matrix:\n");
    printMatrix(secondMatrix, rows, cols);

    // Matrix Addition
    addMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);
    printf("\nResult of Addition:\n");
    printMatrix(resultMatrix, rows, cols);

    // Matrix Subtraction
    subtractMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols);
    printf("\nResult of Subtraction:\n");
    printMatrix(resultMatrix, rows, cols);

    // Matrix Multiplication
    if (rows <= MAX_COLS) {
        multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, rows, cols, cols);
        printf("\nResult of Multiplication:\n");
        printMatrix(resultMatrix, rows, cols);
    } else {
        printf("\nMatrix multiplication not possible with these dimensions!\n");
    }

    // Matrix Transposition
    transposeMatrix(firstMatrix, resultMatrix, rows, cols);
    printf("\nTranspose of First Matrix:\n");
    printMatrix(resultMatrix, cols, rows);

    return 0;
}

void printMatrix(double matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(double first[MAX_ROWS][MAX_COLS], double second[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void subtractMatrices(double first[MAX_ROWS][MAX_COLS], double second[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

void multiplyMatrices(double first[MAX_ROWS][MAX_COLS], double second[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int firstRows, int firstCols, int secondCols) {
    for (int i = 0; i < firstRows; i++) {
        for (int j = 0; j < secondCols; j++) {
            result[i][j] = 0;
            for (int k = 0; k < firstCols; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeMatrix(double matrix[MAX_ROWS][MAX_COLS], double result[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void fillMatrixWithRandomValues(double matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (double)(rand() % 100) / 10.0;  // Generate a random float value from 0.0 to 10.0
        }
    }
}