//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 1000000

int main() {
    int i, j;
    double *a, *b, *c;
    double start_time, end_time;
    int count = 0;

    a = (double *) malloc(SIZE * sizeof(double));
    b = (double *) malloc(SIZE * sizeof(double));
    c = (double *) malloc(SIZE * sizeof(double));

    for (i = 0; i < SIZE; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    start_time = clock();

    for (i = 0; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }

    end_time = clock();

    for (i = 0; i < SIZE; i++) {
        if (c[i]!= (a[i] + b[i])) {
            count++;
        }
    }

    if (count == 0) {
        printf("Test passed! \n");
    } else {
        printf("Test failed! \n");
    }

    printf("Time taken to complete the test: %.6f seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

    free(a);
    free(b);
    free(c);

    return 0;
}