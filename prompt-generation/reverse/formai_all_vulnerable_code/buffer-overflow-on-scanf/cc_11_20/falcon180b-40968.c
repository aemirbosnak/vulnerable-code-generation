//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_ITER 1000
#define EPSILON 0.0001

int main() {
    int n, iter;
    double x, y, z, real, imag, mag, threshold;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    start = clock();
    iter = 0;
    while (iter < MAX_ITER && fabs(A[0][0]) > EPSILON) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x = A[i][j];
                y = A[i][j + 1];
                z = A[i + 1][j];
                real = x - y - z;
                imag = x * y + x * z + y * z;
                mag = sqrt(real * real + imag * imag);
                if (mag > threshold) {
                    A[i][j] = mag;
                    A[i][j + 1] = real / mag;
                    A[i + 1][j] = imag / mag;
                } else {
                    A[i][j] = 0;
                    A[i][j + 1] = 0;
                    A[i + 1][j] = 0;
                }
            }
        }
        iter++;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Iterations: %d\n", iter);
    printf("CPU time used: %lf seconds\n", cpu_time_used);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}