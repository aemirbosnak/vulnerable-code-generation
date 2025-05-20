//FormAI DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i, j, k;
    printf("Enter dimensions of the two matrices (m n): ");
    scanf("%d %d", &m, &n);

    /* Allocate memory for matrices */
    int **a = (int **) malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        a[i] = (int *) malloc(n * sizeof(int));
    }

    int **b = (int **) malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        b[i] = (int *) malloc(n * sizeof(int));
    }

    int **c = (int **) malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        c[i] = (int *) malloc(n * sizeof(int));
    }

    /* Initialize matrices */
    printf("Enter elements of matrix A (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B (%d x %d):\n", m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    /* Perform matrix operations */
    /* Addition */
    printf("Matrix A + B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    /* Multiplication */
    printf("Matrix A * B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    /* Transposition */
    printf("Transpose of matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }

    /* Deallocate memory */
    for (i = 0; i < m; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}