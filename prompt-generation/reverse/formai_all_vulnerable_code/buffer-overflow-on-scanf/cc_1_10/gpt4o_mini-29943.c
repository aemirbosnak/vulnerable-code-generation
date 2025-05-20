//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols);

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // Input for first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rowsA, &colsA);
    if(rowsA > MAX || colsA > MAX) {
        printf("Matrix size exceeds the maximum allowed (%d x %d).\n", MAX, MAX);
        return -1;
    }
    printf("Enter elements of the first matrix:\n");
    inputMatrix(A, rowsA, colsA);

    // Input for second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rowsB, &colsB);
    if(rowsB > MAX || colsB > MAX) {
        printf("Matrix size exceeds the maximum allowed (%d x %d).\n", MAX, MAX);
        return -1;
    }
    printf("Enter elements of the second matrix:\n");
    inputMatrix(B, rowsB, colsB);

    // Display matrices
    printf("\nFirst Matrix:\n");
    displayMatrix(A, rowsA, colsA);
    printf("\nSecond Matrix:\n");
    displayMatrix(B, rowsB, colsB);

    // Matrix addition
    if(rowsA == rowsB && colsA == colsB) {
        addMatrices(A, B, C, rowsA, colsA);
        printf("\nAddition Result:\n");
        displayMatrix(C, rowsA, colsA);
    } else {
        printf("\nCannot add matrices. Dimensions do not match.\n");
    }

    // Matrix subtraction
    if(rowsA == rowsB && colsA == colsB) {
        subtractMatrices(A, B, C, rowsA, colsA);
        printf("\nSubtraction Result:\n");
        displayMatrix(C, rowsA, colsA);
    } else {
        printf("\nCannot subtract matrices. Dimensions do not match.\n");
    }

    // Matrix multiplication
    if(colsA == rowsB) {
        multiplyMatrices(A, B, C, rowsA, colsA, rowsB, colsB);
        printf("\nMultiplication Result:\n");
        displayMatrix(C, rowsA, colsB);
    } else {
        printf("\nCannot multiply matrices. Inner dimensions do not match.\n");
    }

    // Matrix transpose
    transposeMatrix(A, C, rowsA, colsA);
    printf("\nTranspose of First Matrix:\n");
    displayMatrix(C, colsA, rowsA);

    return 0;
}

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rowsA, int colsA, int rowsB, int colsB) {
    for(int i = 0; i < rowsA; i++) {
        for(int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for(int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            B[j][i] = A[i][j];
        }
    }
}