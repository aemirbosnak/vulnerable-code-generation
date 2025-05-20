//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols);
void displayMenu();
void clearConsole();

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB, choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of rows and columns for matrix A: ");
                scanf("%d %d", &rowsA, &colsA);
                printf("Enter elements of matrix A:\n");
                inputMatrix(A, rowsA, colsA);
                break;
            case 2:
                printf("Enter number of rows and columns for matrix B: ");
                scanf("%d %d", &rowsB, &colsB);
                printf("Enter elements of matrix B:\n");
                inputMatrix(B, rowsB, colsB);
                break;
            case 3:
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrix dimensions must agree for addition.\n");
                } else {
                    addMatrices(A, B, result, rowsA, colsA);
                    printf("Result of A + B:\n");
                    printMatrix(result, rowsA, colsA);
                }
                break;
            case 4:
                if (rowsA != rowsB || colsA != colsB) {
                    printf("Matrix dimensions must agree for subtraction.\n");
                } else {
                    subtractMatrices(A, B, result, rowsA, colsA);
                    printf("Result of A - B:\n");
                    printMatrix(result, rowsA, colsA);
                }
                break;
            case 5:
                if (colsA != rowsB) {
                    printf("Invalid dimensions for multiplication.\n");
                } else {
                    multiplyMatrices(A, B, result, rowsA, colsA, rowsB, colsB);
                    printf("Result of A * B:\n");
                    printMatrix(result, rowsA, colsB);
                }
                break;
            case 6:
                if (rowsA == 0 || colsA == 0) {
                    printf("Matrix A is not defined.\n");
                } else {
                    int transposed[MAX_SIZE][MAX_SIZE];
                    transposeMatrix(A, transposed, rowsA, colsA);
                    printf("Transposed Matrix of A:\n");
                    printMatrix(transposed, colsA, rowsA);
                }
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        clearConsole();
    }
    return 0;
}

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
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

void addMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void displayMenu() {
    printf("Matrix Operations Menu:\n");
    printf("1. Input Matrix A\n");
    printf("2. Input Matrix B\n");
    printf("3. Add Matrices A + B\n");
    printf("4. Subtract Matrices A - B\n");
    printf("5. Multiply Matrices A * B\n");
    printf("6. Transpose Matrix A\n");
    printf("7. Exit\n");
}

void clearConsole() {
    // Clear the console - works for Linux
    printf("\033[H\033[J");
}