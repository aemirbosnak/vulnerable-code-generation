//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void main() {
    int **a = NULL, **b = NULL, **c = NULL, i, j, k, l, m, n;
    printf("Enter the number of rows and columns for the matrices:");
    scanf("%d %d", &n, &m);
    a = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
    }
    b = (int **)malloc(l * sizeof(int *));
    for(i = 0; i < l; i++) {
        b[i] = (int *)malloc(m * sizeof(int));
    }
    c = (int **)malloc(k * sizeof(int *));
    for(i = 0; i < k; i++) {
        c[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the elements of the first matrix:");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:");
    for(i = 0; i < l; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d ", &b[i][j]);
        }
    }
    printf("The product of the two matrices is:");
    for(i = 0; i < k; i++) {
        for(j = 0; j < n; j++) {
            for(l = 0; l < m; l++) {
                c[i][j] = 0;
                for(m = 0; m < l; m++) {
                    c[i][j] += a[i][m] * b[m][j];
                }
            }
        }
    }
    for(i = 0; i < k; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    free(a);
    free(b);
    free(c);
}