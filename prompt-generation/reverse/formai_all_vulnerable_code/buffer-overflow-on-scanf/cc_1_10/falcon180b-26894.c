//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OPERATIONS 1000000

void matrix_multiplication(int **a, int **b, int **c, int n) {
    int i, j, k;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int n, i, j;
    int **a, **b, **c;
    double start_time, end_time;

    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    a = (int **)malloc(n * sizeof(int *));
    b = (int **)malloc(n * sizeof(int *));
    c = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(n * sizeof(int));
        c[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    start_time = clock();
    matrix_multiplication(a, b, c, n);
    end_time = clock();

    printf("The product of the matrices is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Time taken for matrix multiplication: %lf seconds\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);

    for (i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    for (i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    return 0;
}