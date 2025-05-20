//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_SIZE 100

void displayMenu();
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    printf("Enter dimensions for Matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions for Matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);
    
    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Addition:\n");
                for (int i = 0; i < rowsA; i++) {
                    for (int j = 0; j < colsA; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 2:
                subtractMatrices(matrixA, matrixB, result, rowsA, colsA);
                printf("Result of Subtraction:\n");
                for (int i = 0; i < rowsA; i++) {
                    for (int j = 0; j < colsA; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, rowsB, colsB);
                printf("Result of Multiplication:\n");
                for (int i = 0; i < rowsA; i++) {
                    for (int j = 0; j < colsB; j++) {
                        printf("%d ", result[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\nChoose an operation:\n");
    printf("1. Add Matrices\n");
    printf("2. Subtract Matrices\n");
    printf("3. Multiply Matrices\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
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

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize the result cell
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}