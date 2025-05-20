//FormAI DATASET v1.0 Category: Matrix operations ; Style: configurable
#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void displayMatrix(int matrix[][MAX_COLS], int rows, int cols) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void scalarMultiplication(int matrix[][MAX_COLS], int scalar, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = scalar * matrix[i][j];
        }
    }
}

void matrixAddition(int matrixA[][MAX_COLS], int matrixB[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixA[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

int main() {

    int matrixA[MAX_ROWS][MAX_COLS], matrixB[MAX_ROWS][MAX_COLS];
    int rows, cols, scalar;
    char operation;

    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of matrix A: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of matrix B: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    printf("Select the operation you want to perform:\n");
    printf("a: Scalar Multiplication\nb: Matrix Addition\n");
    scanf(" %c", &operation);

    switch (operation) {
        case 'a':
            printf("Enter the scalar: ");
            scanf("%d", &scalar);
            scalarMultiplication(matrixA, scalar, rows, cols);
            printf("\nMatrix after scalar multiplication:\n");
            displayMatrix(matrixA, rows, cols);
            break;
        
        case 'b':
            matrixAddition(matrixA, matrixB, rows, cols);
            printf("\nMatrix after addition:\n");
            displayMatrix(matrixA, rows, cols);
            break;
        
        default:
            printf("\nInvalid operation selected!\n");
            break;
    }

    return 0;
}