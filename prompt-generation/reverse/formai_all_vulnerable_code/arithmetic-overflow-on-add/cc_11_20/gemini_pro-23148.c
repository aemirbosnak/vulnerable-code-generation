//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define width 100
#define height 100
#define max_sleep 1000000

int main() {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h;
    int fib[100];
    int fib_sum[100];
    int fib_sum_sq[100];

    // Initialize the Fibonacci sequence
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Initialize the Fibonacci sum array
    fib_sum[0] = 0;
    for (i = 1; i < 100; i++) {
        fib_sum[i] = fib_sum[i - 1] + fib[i];
    }

    // Initialize the Fibonacci sum squared array
    fib_sum_sq[0] = 0;
    for (i = 1; i < 100; i++) {
        fib_sum_sq[i] = fib_sum_sq[i - 1] + fib_sum[i] * fib_sum[i];
    }

    // Draw the Fibonacci sequence
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            if (i == 0 || j == 0) {
                printf("#");
            } else if (i == fib[j]) {
                printf("@");
            } else if (j == fib_sum[i]) {
                printf("%");
            } else if (i * j == fib_sum_sq[i]) {
                printf("$");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    // Wait for the user to press a key
    getchar();

    return 0;
}