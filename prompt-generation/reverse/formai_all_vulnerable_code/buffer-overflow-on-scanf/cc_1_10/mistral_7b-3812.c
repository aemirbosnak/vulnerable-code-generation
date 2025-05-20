//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 100

void print_matrix(double A[][MAX_N], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%.3f ", A[i][j]);
        }
        printf("\n");
    }
}

void swap_rows(double A[][MAX_N], int i, int j, int n) {
    double temp[MAX_N];

    for (int k = 0; k < n; k++) {
        temp[k] = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = temp[k];
    }
}

void gaussian_elimination(double A[][MAX_N], int m, int n, double b[]) {
    int i, j, k, max_row;
    double temp, factor;

    for (i = 0; i < m; i++) {
        max_row = i;
        for (j = i + 1; j < m; j++) {
            if (fabs(A[j][i]) > fabs(A[max_row][i])) {
                max_row = j;
            }
        }

        if (max_row != i) {
            swap_rows(A, i, max_row, n);
            for (k = 0; k < n; k++) {
                temp = b[i];
                b[i] = b[max_row];
                b[max_row] = temp;
            }
        }

        for (j = i + 1; j < m; j++) {
            factor = A[j][i] / A[i][i];
            for (k = 0; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }
}

int main() {
    double A[MAX_N][MAX_N], b[MAX_N];
    int m, n;

    printf("Enter the number of equations and unknowns: ");
    scanf("%d %d", &m, &n);

    printf("Enter the coefficients matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the constant vector b:\n");
    for (int i = 0; i < m; i++) {
        scanf("%lf", &b[i]);
    }

    gaussian_elimination(A, m, n, b);

    printf("\nThe solution vector x is:\n");
    for (int i = 0; i < m; i++) {
        printf("x%d = %.3f\n", i + 1, b[i]);
    }

    print_matrix(A, m, n);

    return 0;
}