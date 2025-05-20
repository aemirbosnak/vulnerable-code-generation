//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000000
#define M 10
#define PI 3.14159265358979323846

int main() {
    int i, j, k;
    double t1, t2, t3, t4;
    double x, y, z;
    double *a, *b, *c;

    srand(time(NULL));

    a = (double*) malloc(N * sizeof(double));
    b = (double*) malloc(N * sizeof(double));
    c = (double*) malloc(N * sizeof(double));

    for (i = 0; i < N; i++) {
        a[i] = rand() % 1000;
        b[i] = rand() % 1000;
        c[i] = rand() % 1000;
    }

    t1 = clock();

    for (i = 0; i < N; i++) {
        x = a[i] + b[i] + c[i];
    }

    t2 = clock();

    for (i = 0; i < N; i++) {
        y = a[i] + b[i] - c[i];
    }

    t3 = clock();

    for (i = 0; i < N; i++) {
        z = a[i] - b[i] + c[i];
    }

    t4 = clock();

    printf("Time for addition: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    printf("Time for subtraction: %f\n", (double)(t3 - t2) / CLOCKS_PER_SEC);
    printf("Time for multiplication: %f\n", (double)(t4 - t3) / CLOCKS_PER_SEC);

    free(a);
    free(b);
    free(c);

    return 0;
}