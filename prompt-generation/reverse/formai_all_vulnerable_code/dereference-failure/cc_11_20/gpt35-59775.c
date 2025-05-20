//FormAI DATASET v1.0 Category: Matrix operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, columns, i, j, k;
    int **matrix1, **matrix2, **sum, **product;

    // Get number of rows and columns for matrices from user
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    // Create memory for matrices
    matrix1 = (int **)malloc(rows * sizeof(int *));
    matrix2 = (int **)malloc(rows * sizeof(int *));
    sum = (int **)malloc(rows * sizeof(int *));
    product = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (int *)malloc(columns * sizeof(int));
        matrix2[i] = (int *)malloc(columns * sizeof(int));
        sum[i] = (int *)malloc(columns * sizeof(int));
        product[i] = (int *)malloc(columns * sizeof(int));
    }

    // Get matrix1 elements from user
    printf("\nEnter elements of matrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Get matrix2 elements from user
    printf("\nEnter elements of matrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Calculate matrix sum
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Print matrix sum
    printf("\nSum of the two matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    // Calculate matrix product
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            product[i][j] = 0;
            for (k = 0; k < columns; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Print matrix product
    printf("\nProduct of the two matrices:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    // Free memory for matrices
    for (i = 0; i < rows; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(sum[i]);
        free(product[i]);
    }
    free(matrix1);
    free(matrix2);
    free(sum);
    free(product);

    return 0;
}