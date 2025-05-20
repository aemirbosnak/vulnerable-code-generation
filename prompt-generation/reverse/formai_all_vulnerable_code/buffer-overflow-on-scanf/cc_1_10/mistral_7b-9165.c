//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

void matrix_multiply(float a[][N], float b[][N], float result[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    float a[N][N], b[N][N], result[N][N], x[N], y[N];

    printf("Enter the elements of first matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter the elements of second matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &b[i][j]);
        }
    }

    matrix_multiply(a, b, result);

    printf("The product of matrices A and B is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    printf("Enter the values of x:\n");
    for (int i = 0; i < N; i++) {
        scanf("%f", &x[i]);
    }

    float coefficients[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%f", &coefficients[i][j]);
        }
    }

    float constants[N];

    for (int i = 0; i < N; i++) {
        scanf("%f", &constants[i]);
    }

    float y_values[N];

    for (int i = 0; i < N; i++) {
        y[i] = 0;
        for (int j = 0; j < N; j++) {
            y[i] += coefficients[i][j] * x[j];
        }
        y_values[i] = y[i] - constants[i];
    }

    printf("The values of y are:\n");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", y_values[i]);
    }

    return 0;
}