//FormAI DATASET v1.0 Category: Matrix operations ; Style: energetic
#include <stdio.h>

// Declare function to display the matrix
void displayMatrix(int rows, int columns, int matrix[][columns]) {
    printf("The Matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to Matrix Operations Program!\n");
    printf("Enter number of rows for Matrix A:\n");
    int rowsA;
    scanf("%d", &rowsA);
    
    printf("Enter number of columns for Matrix A:\n");
    int columnsA;
    scanf("%d", &columnsA);
    
    int matrixA[rowsA][columnsA];
    printf("Enter the elements of Matrix A:\n");
    
    // Get the input for Matrix A
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }
    
    displayMatrix(rowsA, columnsA, matrixA);
    
    printf("Enter number of rows for Matrix B:\n");
    int rowsB;
    scanf("%d", &rowsB);
    
    printf("Enter number of columns for Matrix B:\n");
    int columnsB;
    scanf("%d", &columnsB);
    
    // Check if number of columns in Matrix A is equal to rows in Matrix B
    if (columnsA != rowsB) {
        printf("Error: Matrix Multiplication cannot be performed.\n");
        return 0;
    }
    
    int matrixB[rowsB][columnsB];
    printf("Enter the elements of Matrix B:\n");
    
    // Get the input for Matrix B
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < columnsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }
    
    displayMatrix(rowsB, columnsB, matrixB);
    
    // Perform Matrix Multiplication of A and B
    int productMatrix[rowsA][columnsB];
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            productMatrix[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    displayMatrix(rowsA, columnsB, productMatrix);
    
    return 0;
}