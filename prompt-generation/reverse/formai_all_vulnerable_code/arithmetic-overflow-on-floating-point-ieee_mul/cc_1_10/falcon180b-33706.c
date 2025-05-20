//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int i, j, k;
    int n, m;
    double x, y, z;
    double a[100][100], b[100][100], c[100][100];
    double sum = 0;
    char ch;

    printf("Welcome to the Medieval Kingdom of Mathematics!\n");
    printf("Here, thou shalt solve mathematical problems using the power of C.\n");
    printf("Press any key to continue...\n");
    ch = getchar();

    srand(time(NULL));
    n = rand() % 100 + 1;
    m = rand() % 100 + 1;

    printf("Thou art tasked with multiplying two matrices:\n");
    printf("Matrix A (%d x %d):\n", n, m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand() % 100;
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B (%d x %d):\n", m, n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = rand() % 100;
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The product of matrices A and B is:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Press any key to exit...\n");
    ch = getchar();

    return 0;
}