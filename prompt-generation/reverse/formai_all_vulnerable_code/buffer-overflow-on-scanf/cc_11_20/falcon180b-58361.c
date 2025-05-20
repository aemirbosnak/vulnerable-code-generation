//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main() {
    int i, j, n;
    int **a, **b, **c;
    int sum = 0;
    int count = 0;
    srand(time(0));
    printf("Enter the number of rows and columns for the matrices\n");
    scanf("%d%d", &n, &n);

    a = (int **)malloc(n * sizeof(int *));
    b = (int **)malloc(n * sizeof(int *));
    c = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements of matrix A\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
            sum += a[i][j];
        }
    }

    printf("Enter the elements of matrix B\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = rand() % 10;
        }
    }

    printf("Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Product of matrices A and B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}