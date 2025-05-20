//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    double **a, **b, **c;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrices: ");
    scanf("%d", &n);

    a = (double**)malloc(n * sizeof(double*));
    b = (double**)malloc(n * sizeof(double*));
    c = (double**)malloc(n * sizeof(double*));

    for (i = 0; i < n; i++) {
        a[i] = (double*)malloc(n * sizeof(double));
        b[i] = (double*)malloc(n * sizeof(double));
        c[i] = (double*)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100;
            b[i][j] = rand() % 100;
        }
    }

    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU Time used: %lf seconds\n", cpu_time_used);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", c[i][j]);
        }
        printf("\n");
    }

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