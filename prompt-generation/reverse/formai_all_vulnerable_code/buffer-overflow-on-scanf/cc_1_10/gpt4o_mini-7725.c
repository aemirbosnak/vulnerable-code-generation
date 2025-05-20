//GPT-4o-mini DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int matrix[][10], int rows, int cols) {
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[][10], int rows, int cols) {
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int a[][10], int b[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtractMatrices(int a[][10], int b[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiplyMatrices(int a[][10], int b[][10], int result[][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols, choice;
    int matrix1[10][10], matrix2[10][10], result[10][10];

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    inputMatrix(matrix1, rows, cols);
    inputMatrix(matrix2, rows, cols);

    printf("Select the operation to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication (matrix 1 x matrix 2)\n");
    printf("4. Transpose (matrix 1)\n");
    printf("5. Transpose (matrix 2)\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMatrices(matrix1, matrix2, result, rows, cols);
            printf("Result of Matrix Addition:\n");
            printMatrix(result, rows, cols);
            break;
        case 2:
            subtractMatrices(matrix1, matrix2, result, rows, cols);
            printf("Result of Matrix Subtraction:\n");
            printMatrix(result, rows, cols);
            break;
        case 3:
            if (cols != rows) {
                printf("Matrix multiplication is not possible with given dimensions.\n");
                break;
            }
            multiplyMatrices(matrix1, matrix2, result, rows, cols, cols);
            printf("Result of Matrix Multiplication:\n");
            printMatrix(result, rows, cols);
            break;
        case 4:
            transposeMatrix(matrix1, result, rows, cols);
            printf("Transpose of Matrix 1:\n");
            printMatrix(result, cols, rows);
            break;
        case 5:
            transposeMatrix(matrix2, result, rows, cols);
            printf("Transpose of Matrix 2:\n");
            printMatrix(result, cols, rows);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}