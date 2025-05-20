//LLAMA2-13B DATASET v1.0 Category: Matrix operations ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 5
#define N 3

int main() {
    int i, j, k;
    int arr[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    int mat[M][N] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    // Example 1: Multiply two matrices
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                mat[i][j] += arr[i][k] * mat[i][k];
            }
        }
    }

    // Example 2: Transpose a matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    // Example 3: Inverse of a matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            mat[i][j] = (arr[i][j] * (M - 1)) / (M * arr[M - 1][j]);
        }
    }

    // Example 4: Determinant of a matrix
    int det = 1;
    for (i = 0; i < M; i++) {
        det *= mat[i][i];
    }

    printf("Matrix operations examples:\n");
    printf("Example 1: Multiply two matrices\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Example 2: Transpose a matrix\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Example 3: Inverse of a matrix\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Example 4: Determinant of a matrix\n");
    printf("%d\n", det);

    return 0;
}