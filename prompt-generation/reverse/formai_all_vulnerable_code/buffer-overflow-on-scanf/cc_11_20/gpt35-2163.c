//FormAI DATASET v1.0 Category: Matrix operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

int main() {
    int row1, col1, row2, col2;
    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for matrix 1: ");
    scanf("%d", &col1);
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for matrix 2: ");
    scanf("%d", &col2);

    if (col1 != row2) {
        printf("Invalid matrix dimensions\n");
        return 1;
    }

    // Dynamically allocate memory for the matrices
    int **matrix1, **matrix2, **result;
    matrix1 = (int **) malloc(row1 * sizeof(int *));
    matrix2 = (int **) malloc(row2 * sizeof(int *));
    result = (int **) malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++) {
        matrix1[i] = (int *) malloc(col1 * sizeof(int));
        result[i] = (int *) malloc(col2 * sizeof(int));
    }
    for (int i = 0; i < row2; i++) {
        matrix2[i] = (int *) malloc(col2 * sizeof(int));
    }

    // Initialize matrices with random values
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            matrix1[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            matrix2[i][j] = rand() % 10;
        }
    }

    // Perform matrix multiplication and store result in result matrix
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print the matrices and result
    printf("Matrix1:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix2:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("Result:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < row1; i++) {
        free(matrix1[i]);
        free(result[i]);
    }
    for (int i = 0; i < row2; i++) {
        free(matrix2[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}