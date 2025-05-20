//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIB_MAX 100

int main(int argc, char *argv[]) {
    int fib[FIB_MAX];
    int i, j, k;

    // Initialize the Fibonacci sequence.
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < FIB_MAX; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Print the Fibonacci sequence.
    for (i = 0; i < FIB_MAX; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Visualize the Fibonacci sequence.
    for (i = 0; i < FIB_MAX; i++) {
        for (j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Reverse the Fibonacci sequence.
    for (i = 0, j = FIB_MAX - 1; i < j; i++, j--) {
        k = fib[i];
        fib[i] = fib[j];
        fib[j] = k;
    }

    // Print the reversed Fibonacci sequence.
    for (i = 0; i < FIB_MAX; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Visualize the reversed Fibonacci sequence.
    for (i = 0; i < FIB_MAX; i++) {
        for (j = 0; j < fib[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}