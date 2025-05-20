//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

typedef struct {
    float a[N][M];
    float b[N][M];
    float c[N][M];
} matrix;

matrix add(matrix a, matrix b) {
    matrix result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            result.a[i][j] = a.a[i][j] + b.a[i][j];
            result.b[i][j] = a.b[i][j] + b.b[i][j];
            result.c[i][j] = a.c[i][j] + b.c[i][j];
        }
    }

    return result;
}

void print_matrix(matrix m) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.2f ", m.a[i][j]);
        }
        printf("\n");

        for (int j = 0; j < M; j++) {
            printf("%.2f ", m.b[i][j]);
        }
        printf("\n");

        for (int j = 0; j < M; j++) {
            printf("%.2f ", m.c[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    matrix a, b, c, result;

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%f", &a.a[i][j]);
            scanf("%f", &a.b[i][j]);
            scanf("%f", &a.c[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%f", &b.a[i][j]);
            scanf("%f", &b.b[i][j]);
            scanf("%f", &b.c[i][j]);
        }
    }

    result = add(a, b);
    printf("Matrix A:\n");
    print_matrix(a);

    printf("Matrix B:\n");
    print_matrix(b);

    printf("Sum of Matrix A and Matrix B:\n");
    print_matrix(result);

    return 0;
}