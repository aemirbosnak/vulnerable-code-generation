//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000000

int main(int argc, char *argv[]) {
    int n, i, j, k;
    int *a, *b, *c;
    clock_t start, end;

    // Allocate memory for arrays
    a = (int *) malloc(MAX_N * sizeof(int));
    b = (int *) malloc(MAX_N * sizeof(int));
    c = (int *) malloc(MAX_N * sizeof(int));

    // Initialize arrays with random values
    for (i = 0; i < MAX_N; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    // Measure time for addition
    start = clock();
    for (i = 0; i < MAX_N; i++) {
        c[i] = a[i] + b[i];
    }
    end = clock();
    printf("Time taken for addition: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Measure time for subtraction
    start = clock();
    for (i = 0; i < MAX_N; i++) {
        c[i] = a[i] - b[i];
    }
    end = clock();
    printf("Time taken for subtraction: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Measure time for multiplication
    start = clock();
    for (i = 0; i < MAX_N; i++) {
        c[i] = a[i] * b[i];
    }
    end = clock();
    printf("Time taken for multiplication: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Measure time for division
    start = clock();
    for (i = 0; i < MAX_N; i++) {
        if (b[i] == 0) {
            printf("Division by zero error at index %d\n", i);
            exit(1);
        }
        c[i] = a[i] / b[i];
    }
    end = clock();
    printf("Time taken for division: %f seconds\n", (double) (end - start) / CLOCKS_PER_SEC);

    // Free memory for arrays
    free(a);
    free(b);
    free(c);

    return 0;
}