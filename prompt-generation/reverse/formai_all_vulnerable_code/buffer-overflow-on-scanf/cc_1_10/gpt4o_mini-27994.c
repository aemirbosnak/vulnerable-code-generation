//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("🎉 Please enter the elements of the matrix (%dx%d): 🎉\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("🟢 Here is your matrix (%dx%d): 🟢\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("✨ Adding the two matrices! ✨\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("✨ Subtracting the second matrix from the first! ✨\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    printf("✨ Multiplying the two matrices! ✨\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int rowsA, colsA;
    int rowsB, colsB;

    printf("🌟 Welcome to the Matrix Operations Program! 🌟\n");
    
    // Input for first matrix
    printf("Please enter the number of rows for the first matrix: ");
    scanf("%d", &rowsA);
    printf("Please enter the number of columns for the first matrix: ");
    scanf("%d", &colsA);

    int matrixA[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrixA, rowsA, colsA);
    displayMatrix(matrixA, rowsA, colsA);

    // Input for second matrix
    printf("Please enter the number of rows for the second matrix: ");
    scanf("%d", &rowsB);
    printf("Please enter the number of columns for the second matrix: ");
    scanf("%d", &colsB);

    if (rowsA != rowsB || colsA != colsB) {
        printf("❌ Matrix addition and subtraction requires both matrices to be of the same dimensions! ❌\n");
        return 1;
    }

    int matrixB[MAX_SIZE][MAX_SIZE];
    inputMatrix(matrixB, rowsB, colsB);
    displayMatrix(matrixB, rowsB, colsB);

    // Perform addition
    int additionResult[MAX_SIZE][MAX_SIZE];
    addMatrices(matrixA, matrixB, additionResult, rowsA, colsA);
    displayMatrix(additionResult, rowsA, colsA);

    // Perform subtraction
    int subtractionResult[MAX_SIZE][MAX_SIZE];
    subtractMatrices(matrixA, matrixB, subtractionResult, rowsA, colsA);
    displayMatrix(subtractionResult, rowsA, colsA);

    // For multiplication, we need the number of columns of A to equal the number of rows of B
    if (colsA != rowsB) {
        printf("❌ Matrix multiplication requires the number of columns of the first matrix to match the number of rows of the second! ❌\n");
        return 1;
    }

    int multiplicationResult[MAX_SIZE][MAX_SIZE];
    multiplyMatrices(matrixA, matrixB, multiplicationResult, rowsA, colsA, colsB);
    displayMatrix(multiplicationResult, rowsA, colsB);

    printf("🎉 Thank you for using the Matrix Operations Program! 🎉\n");
    return 0;
}