//Code Llama-13B DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
// Ada Lovelace Matrix Operations Program
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

// Function to perform matrix multiplication
void multiply(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int m, int n, int p) {
    int i, j, k;
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to perform matrix addition
void add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to perform matrix subtraction
void subtract(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to perform matrix transpose
void transpose(int a[][MAX_SIZE], int b[][MAX_SIZE], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            b[j][i] = a[i][j];
        }
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
    int m, n, p, i, j, k;

    // Input the dimensions of the matrices
    printf("Enter the dimensions of matrix A: ");
    scanf("%d%d", &m, &n);
    printf("Enter the dimensions of matrix B: ");
    scanf("%d%d", &p, &n);

    // Input the matrices
    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Perform matrix multiplication
    multiply(a, b, c, m, n, p);
    printf("The result of matrix multiplication is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Perform matrix addition
    add(a, b, c, m, n);
    printf("The result of matrix addition is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Perform matrix subtraction
    subtract(a, b, c, m, n);
    printf("The result of matrix subtraction is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Perform matrix transpose
    transpose(a, b, m, n);
    printf("The transpose of matrix A is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}