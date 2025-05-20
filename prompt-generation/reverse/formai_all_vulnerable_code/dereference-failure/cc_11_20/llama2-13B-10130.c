//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 1000
#define M 100
#define P 10

int main() {
    int i, j, k;
    double x, y, z, w, s, t, r;
    double *arr1, *arr2, *arr3;
    double sum1, sum2, sum3;

    // Generate random data
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        x = drand48() * 10 - 5;
        y = drand48() * 10 - 5;
        z = drand48() * 10 - 5;
        w = drand48() * 10 - 5;
        s = x * x + y * y + z * z + w * w;
        arr1[i] = s;
    }

    // Calculate mean and standard deviation
    for (i = 0; i < N; i++) {
        sum1 += arr1[i];
    }
    sum1 /= N;
    for (i = 0; i < N; i++) {
        sum2 += (arr1[i] - sum1) * (arr1[i] - sum1);
    }
    sum2 /= N;
    for (i = 0; i < N; i++) {
        sum3 += pow(arr1[i] - sum1, 2);
    }
    sum3 /= N;

    // Calculate correlation coefficient
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) continue;
            z = arr1[i] - sum1;
            w = arr1[j] - sum1;
            t = z * w;
            r = t / sqrt(sum2 * sum3);
            arr2[i * N + j] = r;
        }
    }

    // Calculate covariance matrix
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            arr3[i * N + j] = arr2[i * N + j] * arr2[i * N + j];
        }
    }

    // Print results
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", arr3[i * N + j]);
        }
        printf("\n");
    }

    return 0;
}