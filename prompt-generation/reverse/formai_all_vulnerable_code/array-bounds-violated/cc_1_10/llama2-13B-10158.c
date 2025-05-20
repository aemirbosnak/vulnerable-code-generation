//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define M 1000
#define N 100
#define P 20

int main() {
    int i, j, k, n;
    double a, b, c, d, e, f, g;
    char str[100];

    // Generate a random matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            a = (double)rand() / RAND_MAX;
            b = (double)rand() / RAND_MAX;
            c = (double)rand() / RAND_MAX;
            d = (double)rand() / RAND_MAX;
            e = (double)rand() / RAND_MAX;
            f = (double)rand() / RAND_MAX;
            g = (double)rand() / RAND_MAX;
            str[j * M + i] = (a + b) * (c + d) - e * f + g;
        }
    }

    // Print the matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", str[j * M + i]);
        }
        printf("\n");
    }

    // Calculate the determinant
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            a = str[j * M + i];
            b = str[(j + 1) * M + i];
            c = str[(j + 2) * M + i];
            d = str[(j + 3) * M + i];
            e = str[(j + 4) * M + i];
            f = str[(j + 5) * M + i];
            g = str[(j + 6) * M + i];
            str[j * M + i] = a * (e * f - g) - b * (d * f - c) + c * (b * e - a) + d * (a * e - c);
        }
    }

    // Print the determinant
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%.2f ", str[j * M + i]);
        }
        printf("\n");
    }

    return 0;
}