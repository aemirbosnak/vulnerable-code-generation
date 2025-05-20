//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void displayMatrix(int matrix[MAX][MAX], int rows, int cols, const char* name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
}

int main() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Welcome to the Happy Matrix Operations Program!\n");
    printf("Let's create your first matrix!\n");

    printf("Enter number of rows for Matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter number of columns for Matrix A: ");
    scanf("%d", &colsA);
    
    printf("Now, let's fill Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    displayMatrix(a, rowsA, colsA, "Matrix A");

    printf("Fantastic! Now, let's create your second matrix!\n");
    printf("Enter number of rows for Matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter number of columns for Matrix B: ");
    scanf("%d", &colsB);
    
    if (rowsA != rowsB || colsA != colsB) {
        printf("Caution! Matrices A and B must have the same dimensions for addition and subtraction.\n");
    } else {
        printf("Let's fill Matrix B:\n");
        for (int i = 0; i < rowsB; i++) {
            for (int j = 0; j < colsB; j++) {
                printf("Enter element [%d][%d]: ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
        }
        
        displayMatrix(b, rowsB, colsB, "Matrix B");
        
        addMatrices(a, b, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA, "Result of A + B");

        subtractMatrices(a, b, result, rowsA, colsA);
        displayMatrix(result, rowsA, colsA, "Result of A - B");
    }

    printf("Wonderful! Now let's perform multiplication.\n");
    printf("Please make sure the number of columns of Matrix A equals the number of rows of Matrix B.\n");
    if (colsA != rowsB) {
        printf("Oops! The matrices cannot be multiplied.\n");
    } else {
        multiplyMatrices(a, b, result, rowsA, colsA, colsB);
        displayMatrix(result, rowsA, colsB, "Result of A * B");
    }

    printf("Thank you for using the Happy Matrix Operations Program! Have a bright day ahead! 😊\n");
    return 0;
}