//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

int main() {
    int A[N][M], B[N][M], C[N][M], i, j, k;

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            C[i][j] = 0;
            for (k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatrix A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nResult of matrix multiplication (C):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}