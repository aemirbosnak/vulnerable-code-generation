//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>

#define MAX_SIZE 10

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("The matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++) {
        for (int j = 0; j < bCols; j++) {
            result[i][j] = 0; // Initialize to zero
            for (int k = 0; k < aCols; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int transposed[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    
    printf("Welcome to the Matrix Operation Playground!\n");
    printf("Let's get started with matrix size:\n");
    
    printf("Enter number of rows and columns for Matrix A: ");
    scanf("%d%d", &rowsA, &colsA);
    inputMatrix(a, rowsA, colsA);
    
    printf("Now, enter number of rows and columns for Matrix B: ");
    scanf("%d%d", &rowsB, &colsB);
    inputMatrix(b, rowsB, colsB);
    
    // Operations are only valid if matrix dimensions allow
    int choice;
    
    do {
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose Matrix A\n");
        printf("5. Transpose Matrix B\n");
        printf("6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(a, b, result, rowsA, colsA);
                    printf("Result of A + B:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices must have the same dimensions for addition!\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(a, b, result, rowsA, colsA);
                    printf("Result of A - B:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("Matrices must have the same dimensions for subtraction!\n");
                }
                break;
            case 3:
                if (colsA == rowsB) {
                    multiplyMatrices(a, b, result, rowsA, colsA, colsB);
                    printf("Result of A * B:\n");
                    printMatrix(result, rowsA, colsB);
                } else {
                    printf("For multiplication, columns of A must equal rows of B!\n");
                }
                break;
            case 4:
                transposeMatrix(a, transposed, rowsA, colsA);
                printf("Result of Transpose Matrix A:\n");
                printMatrix(transposed, colsA, rowsA);
                break;
            case 5:
                transposeMatrix(b, transposed, rowsB, colsB);
                printf("Result of Transpose Matrix B:\n");
                printMatrix(transposed, colsB, rowsB);
                break;
            case 6:
                printf("Exiting program... Happy Matrix Computing!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}