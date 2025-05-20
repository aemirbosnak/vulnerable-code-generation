//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000
#define P 100000

int main() {
    int i, j, k, n, m, r, p;
    int *a, *b, *c;
    clock_t start, end;
    double cpu_time_used;

    // Allocate memory dynamically
    a = (int *) malloc(N * sizeof(int));
    b = (int *) malloc(N * sizeof(int));
    c = (int *) malloc(N * sizeof(int));

    // Initialize arrays
    for (i = 0; i < N; i++) {
        a[i] = i;
        b[i] = 2 * i;
    }

    // Start timer
    start = clock();

    // Perform matrix multiplication
    for (i = 0; i < N; i += P) {
        for (j = 0; j < N; j += P) {
            for (k = 0; k < N; k += P) {
                for (m = 0; m < P; m++) {
                    for (n = 0; n < P; n++) {
                        r = 0;
                        for (p = 0; p < P; p++) {
                            r += a[i + m + p * P] * b[j + n + p * P];
                        }
                        c[i + m + k * P] += r;
                    }
                }
            }
        }
    }

    // Stop timer
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    // Free memory
    free(a);
    free(b);
    free(c);

    return 0;
}