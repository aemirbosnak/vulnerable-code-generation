//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Here is your matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    printf("Adding two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    printf("Subtracting two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    printf("Multiplying two matrices:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], D[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    printf("Welcome to Matrix Operations! Let's explore the wonders of matrices together!\n\n");

    printf("Enter the number of rows and columns for Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Now, enter the elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    printMatrix(A, rowsA, colsA);

    printf("Enter the number of rows and columns for Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (rowsA != rowsB || colsA != colsB) {
        printf("For addition and subtraction, matrices must be the same size.\n");
        return 1;
    }

    printf("Now, enter the elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Enter element B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }
    printMatrix(B, rowsB, colsB);

    addMatrices(A, B, C, rowsA, colsA);
    printMatrix(C, rowsA, colsA);

    subtractMatrices(A, B, D, rowsA, colsA);
    printMatrix(D, rowsA, colsA);

    if (colsA != rowsB) {
        printf("For multiplication, the number of columns of Matrix A must equal the number of rows of Matrix B.\n");
        return 1;
    }

    int result[MAX][MAX];
    multiplyMatrices(A, B, result, rowsA, colsA, colsB);
    printMatrix(result, rowsA, colsB);

    printf("Thank you for using Matrix Operations! Let's keep exploring the universe of mathematics together!\n");

    return 0;
}