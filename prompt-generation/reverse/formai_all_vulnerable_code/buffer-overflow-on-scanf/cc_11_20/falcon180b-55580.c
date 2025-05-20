//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i, j;
    double **matrix, **identity;
    double *vector, *result;

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    matrix = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        matrix[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    identity = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++) {
        identity[i] = (double *)malloc(n * sizeof(double));
        for (j = 0; j < n; j++) {
            if (i == j) {
                identity[i][j] = 1.0;
            } else {
                identity[i][j] = 0.0;
            }
        }
    }

    vector = (double *)malloc(n * sizeof(double));
    for (i = 0; i < n; i++) {
        scanf("%lf", &vector[i]);
    }

    result = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i!= j) {
                matrix[i][j] /= matrix[i][i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    printf("Result:\n");
    for (i = 0; i < n; i++) {
        printf("%lf\n", result[i]);
    }

    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (i = 0; i < n; i++) {
        free(identity[i]);
    }
    free(identity);

    free(vector);
    free(result);

    return 0;
}