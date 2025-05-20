//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int rows, cols;
    int **matrix1, **matrix2, **result;

    // Get dimensions of matrices from user
    printf("Enter number of rows for matrices: ");
    scanf("%d", &rows);
    printf("Enter number of columns for matrices: ");
    scanf("%d", &cols);

    // Allocate memory for matrices
    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(rows * sizeof(int *));
    result = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill matrices with random values
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Perform matrix addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print matrices
    printf("Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Result:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}