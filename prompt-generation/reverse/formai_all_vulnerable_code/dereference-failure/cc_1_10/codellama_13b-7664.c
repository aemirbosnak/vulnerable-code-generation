//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
/*
 * Fibonacci Sequence Visualizer
 *
 * This program generates a visual representation of the Fibonacci sequence
 * using the ASCII characters.
 *
 * Usage: ./fibonacci_sequence <n>
 *
 * where <n> is the number of elements to generate in the sequence
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100

int fibonacci_sequence(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci_sequence(n-1) + fibonacci_sequence(n-2);
}

void print_fibonacci_sequence(int n) {
    int i, fib;
    char str[MAX_LEN];

    for (i = 0; i < n; i++) {
        fib = fibonacci_sequence(i);
        snprintf(str, MAX_LEN, "%d", fib);
        printf("%s", str);
        if (i < n-1) {
            printf(" ");
        }
    }
}

int main(int argc, char **argv) {
    int n;

    if (argc < 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);
    if (n <= 0) {
        printf("Invalid input: n must be a positive integer\n");
        return 1;
    }

    print_fibonacci_sequence(n);
    printf("\n");

    return 0;
}