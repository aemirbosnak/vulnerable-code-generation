//FormAI DATASET v1.0 Category: Matrix operations ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i, j;
    int **a, **b, **c;

    printf("Enter the size of the matrix: ");
    scanf("%d %d", &m, &n);

    // Allocate memory for matrices a, b, and c
    a = (int **) malloc(m * sizeof(int *));
    b = (int **) malloc(m * sizeof(int *));
    c = (int **) malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        a[i] = (int *) malloc(n * sizeof(int));
        b[i] = (int *) malloc(n * sizeof(int));
        c[i] = (int *) malloc(n * sizeof(int));
    }

    // Initialize matrix a with random values
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
        }
    }

    // Initialize matrix b with random values
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = rand() % 10;
        }
    }

    // Perform matrix addition
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    // Print matrices a, b, and c
    printf("Matrix a:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix b:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("Matrix c:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for matrices a, b, and c
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