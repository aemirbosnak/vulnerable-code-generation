//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num == 2) return 1;  // 2 is prime
    if (num % 2 == 0) return 0; // even number greater than 2 is not prime

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0; // found a divisor
    }
    return 1; // if no divisors found, it's prime
}

void benchmark_primes(int limit) {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start timing
    int prime_count = 0;

    for (int i = 0; i <= limit; i++) {
        if (is_prime(i)) {
            prime_count++;
        }
    }

    end = clock(); // End timing
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Number of prime numbers up to %d: %d\n", limit, prime_count);
    printf("Time taken to compute: %f seconds\n", cpu_time_used);
}

int main() {
    int limit;

    printf("Enter the upper limit for prime number computation: ");
    scanf("%d", &limit);

    if (limit < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1; // Exit program with error code
    }

    benchmark_primes(limit);

    return 0; // Successful termination
}