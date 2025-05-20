//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, m, n, p;
    int **a, **b, **c;

    printf("Enter the number of rows and columns of matrix A: ");
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

    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &p, &n);

    b = (int **)malloc(p * sizeof(int *));
    for (i = 0; i < p; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    c = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        c[i] = (int *)malloc(p * sizeof(int));
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The product of the two matrices is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    for (i = 0; i < p; i++) {
        free(b[i]);
    }
    free(b);

    for (i = 0; i < m; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}