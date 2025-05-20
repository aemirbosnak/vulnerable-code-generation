//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num_rows, num_cols, i, j, k, m, n, sum, diff, prod, div;
    float **matrix1, **matrix2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &num_rows, &num_cols);

    matrix1 = (float**)malloc(num_rows * sizeof(float*));
    for (i = 0; i < num_rows; i++) {
        matrix1[i] = (float*)malloc(num_cols * sizeof(float));
        for (j = 0; j < num_cols; j++) {
            printf("Enter the value of matrix1[%d][%d]: ", i, j);
            scanf("%f", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &m, &n);

    matrix2 = (float**)malloc(m * sizeof(float*));
    for (k = 0; k < m; k++) {
        matrix2[k] = (float*)malloc(n * sizeof(float));
        for (j = 0; j < n; j++) {
            printf("Enter the value of matrix2[%d][%d]: ", k, j);
            scanf("%f", &matrix2[k][j]);
        }
    }

    printf("Matrix 1:\n");
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf(" %f", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2:\n");
    for (k = 0; k < m; k++) {
        for (j = 0; j < n; j++) {
            printf(" %f", matrix2[k][j]);
        }
        printf("\n");
    }

    sum = 0;
    diff = 0;
    prod = 1;
    div = 1;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            sum += matrix1[i][j] + matrix2[i][j];
            diff += matrix1[i][j] - matrix2[i][j];
            prod *= matrix1[i][j] * matrix2[i][j];
            div /= matrix1[i][j] / matrix2[i][j];
        }
    }

    printf("Sum of matrix1 and matrix2: %f\n", sum);
    printf("Difference of matrix1 and matrix2: %f\n", diff);
    printf("Product of matrix1 and matrix2: %f\n", prod);
    printf("Division of matrix1 and matrix2: %f\n", div);

    printf("Done.");
    return 0;
}