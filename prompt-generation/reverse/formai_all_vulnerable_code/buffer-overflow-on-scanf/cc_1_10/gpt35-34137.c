//FormAI DATASET v1.0 Category: Matrix operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

/* Function to allocate memory for matrix */
int** createMatrix(int rows, int columns) {
    int** matrix = (int**)malloc(rows * sizeof(int*));

    for(int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(columns * sizeof(int));
    }

    return matrix;
}

/* Function to populate matrix element values */
void populateMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter value for element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/* Function to display matrix */
void displayMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Function for addition of two matrices */
int** addMatrix(int** matrix1, int** matrix2, int rows, int columns) {
    int** matrixSum = createMatrix(rows, columns);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrixSum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return matrixSum;
}

/* Function for multiplication of two matrices */
int** multiplyMatrix(int** matrix1, int** matrix2, int rows1, int columns1, int columns2) {
    int** matrixProduct = createMatrix(rows1, columns2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            matrixProduct[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                matrixProduct[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return matrixProduct;
}

int main() {
    int rows1, columns1, rows2, columns2;

    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &columns1);

    int** matrix1 = createMatrix(rows1, columns1);

    /* Populate matrix1 */
    printf("Enter values for matrix 1:\n");
    populateMatrix(matrix1, rows1, columns1);

    /* Display matrix1 */
    printf("Matrix 1:\n");
    displayMatrix(matrix1, rows1, columns1);

    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &columns2);

    int** matrix2 = createMatrix(rows2, columns2);

    /* Populate matrix2 */
    printf("Enter values for matrix 2:\n");
    populateMatrix(matrix2, rows2, columns2);

    /* Display matrix2 */
    printf("Matrix 2:\n");
    displayMatrix(matrix2, rows2, columns2);

    /* Add matrices */
    if (rows1 == rows2 && columns1 == columns2) {
        int** matrixSum = addMatrix(matrix1, matrix2, rows1, columns1);
        printf("Sum of matrices:\n");
        displayMatrix(matrixSum, rows1, columns1);
        free(matrixSum);
    }
    else {
        printf("The matrices cannot be added.\n");
    }

    /* Multiply matrices */
    if (columns1 == rows2) {
        int** matrixProduct = multiplyMatrix(matrix1, matrix2, rows1, columns1, columns2);
        printf("Product of matrices:\n");
        displayMatrix(matrixProduct, rows1, columns2);
        free(matrixProduct);
    }
    else {
        printf("The matrices cannot be multiplied.\n");
    }

    /* Free memory for matrices */
    for (int i = 0; i < rows1; i++) {
        free(matrix1[i]);
    }
    free(matrix1);

    for (int i = 0; i < rows2; i++) {
        free(matrix2[i]);
    }
    free(matrix2);

    return 0;
}