//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int main() {
    int rows, cols, i, j, k;
    double **matrix1, **matrix2, **result, *row, *col;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter number of rows and columns for matrices: ");
    scanf("%d%d", &rows, &cols);

    matrix1 = (double **)malloc(rows * sizeof(double *));
    matrix2 = (double **)malloc(rows * sizeof(double *));
    result = (double **)malloc(rows * sizeof(double *));

    for (i = 0; i < rows; i++) {
        matrix1[i] = (double *)malloc(cols * sizeof(double));
        matrix2[i] = (double *)malloc(cols * sizeof(double));
        result[i] = (double *)malloc(cols * sizeof(double));
    }

    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    start = clock();
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nThe sum of the two matrices is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

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