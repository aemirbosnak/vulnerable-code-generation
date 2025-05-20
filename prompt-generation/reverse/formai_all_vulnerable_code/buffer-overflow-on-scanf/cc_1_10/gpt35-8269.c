//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>

// Function to print matrix
void printMatrix(int matrix[][100], int rows, int cols) {
    printf("The matrix is: \n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add matrices
void addMatrices(int A[][100], int B[][100], int C[][100], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract matrices
void subMatrices(int A[][100], int B[][100], int C[][100], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply matrices
void multiplyMatrices(int A[][100], int B[][100], int C[][100], int rowsA, int colsA, int colsB) {
    for(int i=0; i<rowsA; i++) {
        for(int j=0; j<colsB; j++) {
            for(int k=0; k<colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int matrix[][100], int transMatrix[][100], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            transMatrix[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrixA[100][100], matrixB[100][100], matrixC[100][100], matrixT[100][100];

    // Taking input for matrix A
    printf("Enter elements of matrix A: \n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Taking input for matrix B
    printf("Enter elements of matrix B: \n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Printing matrices A and B
    printMatrix(matrixA, rows, cols);
    printMatrix(matrixB, rows, cols);

    // Adding matrices A and B
    addMatrices(matrixA, matrixB, matrixC, rows, cols);
    printf("The sum of matrices A and B is: \n");
    printMatrix(matrixC, rows, cols);

    // Subtracting matrices A and B
    subMatrices(matrixA, matrixB, matrixC, rows, cols);
    printf("The difference of matrices A and B is: \n");
    printMatrix(matrixC, rows, cols);

    // Multiplying matrices A and B
    multiplyMatrices(matrixA, matrixB, matrixC, rows, cols, cols);
    printf("The product of matrices A and B is: \n");
    printMatrix(matrixC, rows, cols);

    // Finding transpose of matrix A
    transposeMatrix(matrixA, matrixT, rows, cols);
    printf("The transpose of matrix A is: \n");
    printMatrix(matrixT, cols, rows);

    return 0;
}