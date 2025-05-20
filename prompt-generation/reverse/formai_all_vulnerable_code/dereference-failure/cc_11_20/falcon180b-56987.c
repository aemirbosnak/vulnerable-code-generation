//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100

int main() {
    int i, j, size;
    double **matrix1, **matrix2, **result;
    double sum;

    printf("Enter the size of matrices (1 to %d): ", MAX_SIZE);
    scanf("%d", &size);

    matrix1 = (double **)malloc(size * sizeof(double *));
    matrix2 = (double **)malloc(size * sizeof(double *));
    result = (double **)malloc(size * sizeof(double *));

    for (i = 0; i < size; i++) {
        matrix1[i] = (double *)malloc(size * sizeof(double));
        matrix2[i] = (double *)malloc(size * sizeof(double));
        result[i] = (double *)malloc(size * sizeof(double));
    }

    printf("Enter elements of matrix 1:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix 2:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            sum = 0;
            for (int k = 0; k < size; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }

    printf("Result of matrix multiplication:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < size; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }

    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}