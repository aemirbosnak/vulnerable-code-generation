//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>

#define MAX_SIZE 10

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void subtractMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB);

int main() {
    int choice, a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rowsA, colsA, rowsB, colsB;

    printf("🎉 Welcome to the Happy Matrix Operations Program! 🎉\n");
    
    printf("Enter the number of rows and columns for Matrix A:\n");
    scanf("%d %d", &rowsA, &colsA);
    printf("Now, let's fill Matrix A!\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("🎊 Matrix A is ready! 🎊\n");
    printMatrix(a, rowsA, colsA);

    printf("Enter the number of rows and columns for Matrix B:\n");
    scanf("%d %d", &rowsB, &colsB);
    printf("Now, let's fill Matrix B!\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    printf("🎊 Matrix B is ready! 🎊\n");
    printMatrix(b, rowsB, colsB);

    // Menu for matrix operations
    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    addMatrices(a, b, result, rowsA, colsA);
                    printf("🎉 Result of Addition:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("⚠️ Matrices must have the same dimensions for addition!\n");
                }
                break;
            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    subtractMatrices(a, b, result, rowsA, colsA);
                    printf("🎉 Result of Subtraction:\n");
                    printMatrix(result, rowsA, colsA);
                } else {
                    printf("⚠️ Matrices must have the same dimensions for subtraction!\n");
                }
                break;
            case 3:
                if (colsA == rowsB) {
                    multiplyMatrices(a, b, result, rowsA, colsA, rowsB, colsB);
                    printf("🎉 Result of Multiplication:\n");
                    printMatrix(result, rowsA, colsB);
                } else {
                    printf("⚠️ Number of columns in Matrix A must equal the number of rows in Matrix B for multiplication!\n");
                }
                break;
            case 4:
                printf("🚪 Exiting the program. Have a wonderful day! 🚪\n");
                return 0;
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
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

void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int rowsB, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}