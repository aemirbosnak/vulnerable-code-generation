//Falcon2-11B DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <errno.h>
#include <stdint.h>

#define BINARY_SEARCH_LIMIT 1000
#define MAX_BINARY_SEARCH_SIZE 500000

// Function to calculate Fibonacci sequence
int fibonacci(int limit)
{
    int a = 0, b = 1;
    int fib[limit];
    fib[0] = a;
    fib[1] = b;
    
    for (int i = 2; i < limit; i++)
    {
        fib[i] = a + b;
        a = b;
        b = fib[i];
    }
    return fib[limit - 1];
}

// Benchmarking function from benchmark.h library
void benchmark(const char *name, void (*fn)(void), unsigned long long iterations)
{
    clock_t start, end;
    double ms;

    start = clock();
    for (unsigned long long i = 0; i < iterations; i++)
        fn();
    end = clock();

    ms = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
    printf("%s took %lld microseconds (%lf ms)\n", name, ms, ms / 1000);
}

int main()
{
    int limit = 10;
    benchmark("Fibonacci", fibonacci, 1);
    printf("Fibonacci(%d) = %d\n", limit, fibonacci(limit));
    return 0;
}