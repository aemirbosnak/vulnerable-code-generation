//FormAI DATASET v1.0 Category: Matrix operations ; Style: content
#include <stdio.h>

void add(int a[][10], int b[][10], int c[][10], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int a[][10], int b[][10], int c[][10], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void multiply(int a[][10], int b[][10], int c[][10], int m, int n, int p) {
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

void divide(int a[][10], int b[][10], int c[][10], int m, int n) {
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] / b[i][j];
        }
    }
}

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m, n, p, q;
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of matrix A: ");
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &p, &q);
    if (n != p) {
        printf("The matrices can't be multiplied!\n");
        return 0;
    }
    printf("Enter the elements of matrix B: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrix A is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B is:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    add(a, b, c, m, n);
    printf("Addition of A and B is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    subtract(a, b, c, m, n);
    printf("Subtraction of A and B is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    multiply(a, b, c, m, n, q);
    printf("Multiplication of A and B is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    divide(a, b, c, m, n);
    printf("Division of A and B is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}