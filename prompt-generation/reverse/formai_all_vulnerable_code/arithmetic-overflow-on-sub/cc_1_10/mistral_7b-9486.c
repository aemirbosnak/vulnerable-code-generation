//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FIB 50

typedef struct {
    int value;
    int next;
} node_t;

void fib_recursive(int n, int *a, int *b) {
    if (n <= 1) {
        *a = n;
    } else {
        fib_recursive(n - 1, b, a);
        *a += *b;
    }
    *b = *a - *b;
}

void fib_iterative(int n, int *result) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int temp = a;
        a = a + b;
        b = temp;
    }
    *result = a;
}

int main(int argc, char **argv) {
    clock_t start, end;
    double elapsed_time;
    int fib_number, fib_result;

    if (argc != 2) {
        printf("Usage: %s <Fibonacci number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fib_number = atoi(argv[1]);

    start = clock();

    fib_recursive(fib_number, &fib_result, NULL);

    end = clock();
    elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Fibonacci(%d) = %d\n", fib_number, fib_result);
    printf("Time taken: %f seconds\n", elapsed_time);

    start = clock();

    fib_iterative(fib_number, &fib_result);

    end = clock();
    elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Fibonacci(%d) = %d\n", fib_number, fib_result);
    printf("Time taken: %f seconds\n", elapsed_time);

    return EXIT_SUCCESS;
}