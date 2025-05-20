//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_ITERATIONS 100000000
#define ARRAY_SIZE 1000000

void matrixMultiplication(int *a, int *b, int *c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i * n + j] = 0;
            for (int k = 0; k < n; k++) {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
}

int main() {
    int *a, *b, *c;
    int n = ARRAY_SIZE;
    int i, j, k;

    a = (int *)malloc(n * n * sizeof(int));
    b = (int *)malloc(n * n * sizeof(int));
    c = (int *)malloc(n * n * sizeof(int));

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i * n + j] = rand() % 10;
            b[i * n + j] = rand() % 10;
        }
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (i = 0; i < NUM_ITERATIONS; i++) {
        matrixMultiplication(a, b, c, n);
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken by the program is %lf seconds.\n", cpu_time_used);

    return 0;
}