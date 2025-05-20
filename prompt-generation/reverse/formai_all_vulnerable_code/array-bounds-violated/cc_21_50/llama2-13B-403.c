//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 7
#define P 3

int main() {
    int i, j, k;
    int a[M][N] = { {1, 2, 3, 4, 5},
                     {6, 7, 8, 9, 10},
                     {11, 12, 13, 14, 15} };
    int b[M][P] = { {16, 17, 18},
                     {19, 20, 21},
                     {22, 23, 24} };
    int c[P][N] = { {0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0} };

    // Matrix multiplication
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                c[k][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Matrix addition
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                c[k][j] += a[i][k] + b[k][j];
            }
        }
    }

    // Matrix concatenation
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                c[k][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Matrix transpose
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            for (k = 0; k < N; k++) {
                c[j][k] += a[i][k] * b[j][k];
            }
        }
    }

    // Matrix inversion
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                c[k][j] /= a[i][k];
            }
        }
    }

    // Matrix power
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                c[k][j] = pow(a[i][k], 2) * b[k][j];
            }
        }
    }

    // Print the result
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                printf("%d ", c[k][j]);
            }
            printf("\n");
        }
    }

    return 0;
}