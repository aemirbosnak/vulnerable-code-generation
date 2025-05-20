//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: invasive
/* Unorthodox Fibonacci Sequence Visualizer */

#include <stdio.h>

int main() {
    int n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    
    for (i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Visualizing the Fibonacci Sequence as a Tree

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = 0; k < fib[i]; k++) {
            printf("#");
        }
        printf("\n");
    }

    // Visualizing the Fibonacci Sequence as a Stack of Blocks

    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = 0; k < fib[i]; k++) {
            printf("%d", fib[i]);
        }
        printf("\n");
    }

    // Visualizing the Fibonacci Sequence as a Pyramid of Stars

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = 0; k < fib[i] * 2 - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Visualizing the Fibonacci Sequence as a Spiral

    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = 0; k < fib[i]; k++) {
            printf("%d", fib[i]);
        }
        printf("\n");
    }

    for (i = n - 2; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = 0; k < fib[i]; k++) {
            printf("%d", fib[i]);
        }
        printf("\n");
    }

    return 0;
}