//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, i, j, k;
    int **a, **b, **c;
    double start, end;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);

    a = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &m, &n);

    b = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    start = clock();
    c = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    end = clock();
    printf("Time taken for matrix multiplication: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    for (i = 0; i < m; i++) {
        free(b[i]);
    }
    free(b);

    for (i = 0; i < m; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}