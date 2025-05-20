//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    int **matrix1, **matrix2, **result;
    int i, j, k;

    // Get dimensions of first matrix
    printf("Enter number of rows for first matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns for first matrix: ");
    scanf("%d", &cols);

    // Allocate memory for first matrix
    matrix1 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(cols * sizeof(int));
    }

    // Get elements of first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get dimensions of second matrix
    printf("Enter number of rows for second matrix: ");
    scanf("%d", &rows);
    printf("Enter number of columns for second matrix: ");
    scanf("%d", &cols);

    // Allocate memory for second matrix
    matrix2 = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix2[i] = (int *)malloc(cols * sizeof(int));
    }

    // Get elements of second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Allocate memory for result matrix
    result = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        result[i] = (int *)malloc(cols * sizeof(int));
    }

    // Perform matrix addition
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print result matrix
    printf("Result matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}