//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 50

void fib_recursive(int n, int *fib_arr) {
    if (n <= 0) {
        fib_arr[0] = 0;
        return;
    } else if (n == 1) {
        fib_arr[0] = 0;
        fib_arr[1] = 1;
        return;
    }

    fib_recursive(n - 1, fib_arr);
    fib_arr[n] = fib_arr[n - 1] + fib_arr[n - 2];
}

void fib_iterative(int n, int *fib_arr) {
    if (n <= 0) {
        fib_arr[0] = 0;
        return;
    }

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
    }
}

int main() {
    clock_t start, end;
    int n, *fib_arr;

    printf("Enter the number up to which you want to find the Fibonacci sequence: ");
    scanf("%d", &n);

    if (n > MAX_N) {
        printf("Error: The number you entered is greater than the maximum allowed.\n");
        return 1;
    }

    fib_arr = (int *)calloc(n + 1, sizeof(int));

    if (fib_arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    start = clock();
    fib_recursive(n, fib_arr);
    end = clock();

    printf("\nFibonacci sequence using recursion:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib_arr[i]);
    }
    printf("\nTime taken: %fs\n", (float)(end - start) / CLOCKS_PER_SEC);

    fib_arr[0] = 0;
    fib_arr[1] = 1;

    start = clock();
    fib_iterative(n, fib_arr);
    end = clock();

    printf("\nFibonacci sequence using iteration:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib_arr[i]);
    }
    printf("\nTime taken: %fs\n", (float)(end - start) / CLOCKS_PER_SEC);

    free(fib_arr);

    return 0;
}