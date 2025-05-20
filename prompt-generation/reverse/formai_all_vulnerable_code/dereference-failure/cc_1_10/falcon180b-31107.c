//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    int **matrix1, **matrix2, **result_matrix;
    int i, j, k;

    printf("Enter number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for matrices
    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(rows * sizeof(int *));
    result_matrix = (int **)malloc(rows * sizeof(int *));

    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
        matrix2[i] = (int *)malloc(cols * sizeof(int));
        result_matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Fill matrices with random values
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            matrix1[i][j] = rand() % 100;
            matrix2[i][j] = rand() % 100;
        }
    }

    // Perform matrix addition
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result matrix
    printf("\nResult matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result_matrix[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result_matrix);

    return 0;
}