//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main() {
    int m, n, c, d, **A, **B, **C, i, j, k;
    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &m, &n);
    A = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        printf("Enter row %d of first matrix: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &c, &d);
    B = (int **)malloc(c * sizeof(int *));
    for (i = 0; i < c; i++) {
        B[i] = (int *)malloc(d * sizeof(int));
        printf("Enter row %d of second matrix: ", i + 1);
        for (j = 0; j < d; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    C = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        C[i] = (int *)malloc(d * sizeof(int));
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < d; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Product of matrices:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < d; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
    for (i = 0; i < c; i++) {
        free(B[i]);
    }
    free(B);
    for (i = 0; i < m; i++) {
        free(C[i]);
    }
    free(C);
    return 0;
}