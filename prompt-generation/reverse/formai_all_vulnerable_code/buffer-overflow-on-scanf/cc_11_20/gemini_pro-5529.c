//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: mathematical
// Exercise: Matrix Multiplication

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p, q, i, j, k;
    int **A, **B, **C;

    printf("Enter number of rows in Matrix A: ");
    scanf("%d", &m);
    printf("Enter number of columns in Matrix A: ");
    scanf("%d", &n);
    
    printf("Enter number of rows in Matrix B: ");
    scanf("%d", &p);
    printf("Enter number of columns in Matrix B: ");
    scanf("%d", &q);

    if (n != p) {
        printf("Matrix multiplication not possible!");
        return 1;
    }

    // allocate memory for the matrices
    A = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) {
        A[i] = (int *)malloc(sizeof(int) * n);
    }

    B = (int **)malloc(sizeof(int *) * p);
    for (i = 0; i < p; i++) {
        B[i] = (int *)malloc(sizeof(int) * q);
    }

    C = (int **)malloc(sizeof(int *) * m);
    for (i = 0; i < m; i++) {
        C[i] = (int *)malloc(sizeof(int) * q);
    }

    // read the elements of matrix A
    printf("Enter elements of Matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // read the elements of matrix B
    printf("Enter elements of Matrix B:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // multiply the two matrices
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // print the result matrix
    printf("Matrix Multiplication Result:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // free the memory allocated for the matrices
    for (i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);

    for (i = 0; i < p; i++) {
        free(B[i]);
    }
    free(B);

    for (i = 0; i < m; i++) {
        free(C[i]);
    }
    free(C);

    return 0;
}