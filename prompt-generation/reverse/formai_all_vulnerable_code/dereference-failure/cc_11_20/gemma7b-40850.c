//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k, l, m;
    scanf("Enter the number of operations:", &n);

    for (k = 0; k < n; k++) {
        scanf("Enter the dimensions of the matrix:", &l, &m);
        int **a = (int **)malloc(l * sizeof(int *));
        for (i = 0; i < l; i++) {
            a[i] = (int *)malloc(m * sizeof(int));
            for (j = 0; j < m; j++) {
                scanf("Enter the elements of the matrix:", &a[i][j]);
            }
        }

        int **b = (int **)malloc(l * sizeof(int *));
        for (i = 0; i < l; i++) {
            b[i] = (int *)malloc(m * sizeof(int));
            for (j = 0; j < m; j++) {
                b[i][j] = 0;
            }
        }

        for (i = 0; i < l; i++) {
            for (j = 0; j < m; j++) {
                for (l = 0; l < l; l++) {
                    for (m = 0; m < m; m++) {
                        b[l][m] += a[i][j] * a[i][j];
                    }
                }
            }
        }

        for (i = 0; i < l; i++) {
            for (j = 0; j < m; j++) {
                printf("The elements of the product matrix are:");
                printf("\n");
                for (k = 0; k < l; k++) {
                    for (l = 0; l < m; l++) {
                        printf("%d ", b[k][l]);
                    }
                    printf("\n");
                }
            }
        }

        free(a);
        free(b);
    }

    return 0;
}