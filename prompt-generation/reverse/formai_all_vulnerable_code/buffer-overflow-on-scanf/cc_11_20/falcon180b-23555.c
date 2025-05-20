//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, n, m;
    int **a, **b, **c;
    int sum = 0;

    // Get dimensions from user
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &n, &m);

    // Allocate memory for matrices
    a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
    }
    b = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        b[i] = (int *)malloc(m * sizeof(int));
    }
    c = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        c[i] = (int *)malloc(m * sizeof(int));
    }

    // Populate matrices with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }

    // Perform matrix addition
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print matrices and result
    printf("Matrix A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("Result:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}