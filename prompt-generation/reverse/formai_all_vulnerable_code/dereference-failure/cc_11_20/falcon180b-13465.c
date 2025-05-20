//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    int rows1, cols1, rows2, cols2, i, j, k, sum = 0;
    int **matrix1, **matrix2, **result;

    // Allocate memory for matrices
    matrix1 = (int **)malloc(MAX_ROWS * sizeof(int *));
    matrix2 = (int **)malloc(MAX_ROWS * sizeof(int *));
    result = (int **)malloc(MAX_ROWS * sizeof(int *));

    for (i = 0; i < MAX_ROWS; i++) {
        matrix1[i] = (int *)malloc(MAX_COLS * sizeof(int));
        matrix2[i] = (int *)malloc(MAX_COLS * sizeof(int));
        result[i] = (int *)malloc(MAX_COLS * sizeof(int));
    }

    // Get dimensions of matrices
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Get elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix addition
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result matrix
    printf("\nResult matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < MAX_ROWS; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}