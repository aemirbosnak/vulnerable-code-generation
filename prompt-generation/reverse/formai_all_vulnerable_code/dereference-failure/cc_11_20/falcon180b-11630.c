//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000
#define PI 3.14159265358979323846

int main() {
    int i, j, n;
    double x, y, sum = 0;
    double **matrix, **result;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    matrix = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    result = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            x = matrix[i][j];
            y = sin(x);
            result[i][j] = y;
            sum += y;
        }
    }

    printf("The sum of the elements in the resulting matrix is: %lf\n", sum);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}