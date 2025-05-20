//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, j, k;
    int n, m;
    int a[10][10];
    int b[10][10];
    int c[10][10];

    // Input n and m
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &n, &m);

    // Input matrix A
    printf("Enter the elements of matrix A: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input matrix B
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &n, &m);
    printf("Enter the elements of matrix B: ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Multiply matrices A and B
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            c[i][j] = 0;
            for (k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Print matrix C
    printf("The product of matrix A and matrix B is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}