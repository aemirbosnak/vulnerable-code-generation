//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

typedef uint64_t fib_t;

#define FIB_LIMIT (1ULL << 31) // 2147483647

// Recursive Fibonacci function
fib_t fib(fib_t n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

// Iterative Fibonacci function (for comparison)
fib_t fib_iter(fib_t n) {
    fib_t a = 0, b = 1;
    while (n--) {
        fib_t c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    fib_t n;
    clock_t start, end;

    printf("Enter a number to calculate the Fibonacci sequence up to: ");
    scanf("%llu", &n);

    if (n > FIB_LIMIT) {
        printf("The number is too large.\n");
        return 1;
    }

    start = clock();
    fib_t fib_res = fib(n);
    end = clock();

    printf("Fibonacci sequence up to %llu: ", n);
    for (fib_t i = 0; i <= n; i++) {
        printf("%llu ", fib(i));
    }
    printf("\nTime taken by recursive method: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    fib_res = fib_iter(n);
    end = clock();

    printf("Time taken by iterative method: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("Fibonacci number at position %llu: %llu\n", n, fib_res);

    return 0;
}