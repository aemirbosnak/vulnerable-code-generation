//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000

int main() {
    int i, j, k, n;
    double s, t;
    double *a, *b, *c;

    // Allocate memory for matrices
    a = (double*) malloc(SIZE * SIZE * sizeof(double));
    b = (double*) malloc(SIZE * SIZE * sizeof(double));
    c = (double*) malloc(SIZE * SIZE * sizeof(double));

    // Initialize matrices
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            a[i * SIZE + j] = rand() % 100;
            b[i * SIZE + j] = rand() % 100;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            c[i * SIZE + j] = 0;
            for (k = 0; k < SIZE; k++) {
                c[i * SIZE + j] += a[i * SIZE + k] * b[k * SIZE + j];
            }
        }
    }

    // Measure execution time
    clock_t start = clock();
    for (n = 0; n < 100; n++) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                s = 0;
                for (k = 0; k < SIZE; k++) {
                    s += a[i * SIZE + k] * b[k * SIZE + j];
                }
                c[i * SIZE + j] = s;
            }
        }
    }
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("Execution time: %lf seconds\n", cpu_time_used);

    // Free memory
    free(a);
    free(b);
    free(c);

    return 0;
}