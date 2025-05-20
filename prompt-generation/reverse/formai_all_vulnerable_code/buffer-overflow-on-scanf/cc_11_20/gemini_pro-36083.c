//GEMINI-pro DATASET v1.0 Category: Matrix operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, l, m, n, o, p, q, r;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);

    int a[m][n];

    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &o, &p);

    int b[o][p];

    printf("Enter the elements of the second matrix:\n");
    for (k = 0; k < o; k++) {
        for (l = 0; l < p; l++) {
            scanf("%d", &b[k][l]);
        }
    }

    int c[m][p];

    printf("The sum of the two matrices is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("The difference of the two matrices is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            c[i][j] = a[i][j] - b[i][j];
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("The product of the two matrices is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}