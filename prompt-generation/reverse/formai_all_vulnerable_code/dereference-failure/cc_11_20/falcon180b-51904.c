//Falcon-180B DATASET v1.0 Category: Educational ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n, m, i, j, k, l, count = 0;
    int **a, **b, **c;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &n, &m);

    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        a[i] = (int *)malloc(m * sizeof(int));

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &n, &m);

    if (m!= n)
        printf("Matrices cannot be multiplied.\n");
    else {
        b = (int **)malloc(n * sizeof(int *));
        for (i = 0; i < n; i++)
            b[i] = (int *)malloc(m * sizeof(int));

        printf("Enter the elements of the second matrix:\n");
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &b[i][j]);

        c = (int **)malloc(n * sizeof(int *));
        for (i = 0; i < n; i++)
            c[i] = (int *)malloc(m * sizeof(int));

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                for (k = 0; k < m; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("Product of matrices:\n");
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }

    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);

    for (i = 0; i < n; i++)
        free(b[i]);
    free(b);

    for (i = 0; i < n; i++)
        free(c[i]);
    free(c);

    return 0;
}