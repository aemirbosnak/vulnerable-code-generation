//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int rows, cols;
    double **matrix1, **matrix2, **result;
    double det;
    int i, j, k;

    printf("Enter the number of rows and columns for the matrices (max %d): ", MAX_ROWS * MAX_COLS);
    scanf("%d %d", &rows, &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Matrix dimensions are too large.\n");
        return 1;
    }

    matrix1 = (double **)malloc(rows * sizeof(double *));
    for (i = 0; i < rows; i++) {
        matrix1[i] = (double *)malloc(cols * sizeof(double));
    }

    matrix2 = (double **)malloc(rows * sizeof(double *));
    for (i = 0; i < rows; i++) {
        matrix2[i] = (double *)malloc(cols * sizeof(double));
    }

    result = (double **)malloc(rows * sizeof(double *));
    for (i = 0; i < rows; i++) {
        result[i] = (double *)malloc(cols * sizeof(double));
    }

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    clock_t start, end;
    start = clock();

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The sum of the two matrices is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    printf("CPU time used: %lf seconds\n", cpu_time_used);

    return 0;
}