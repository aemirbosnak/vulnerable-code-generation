//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int *sieveOfEratosthenes(int limit) {
    int *isPrime = (int *)malloc((limit + 1) * sizeof(int));
    if (!isPrime) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= limit; i++) {
        isPrime[i] = 1; // Assume all numbers are prime initially
    }
    
    isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime

    for (int i = 2; i <= sqrt(limit); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }
    return isPrime;
}

long long sumOfPrimes(int *isPrime, int limit) {
    long long total = 0;
    for (int i = 0; i <= limit; i++) {
        if (isPrime[i]) {
            total += i;
        }
    }
    return total;
}

void primeStatistics(int *isPrime, int limit) {
    int count = 0;
    for (int i = 0; i <= limit; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    printf("Total prime numbers up to %d: %d\n", limit, count);
    long long totalSum = sumOfPrimes(isPrime, limit);
    printf("Sum of all prime numbers up to %d: %lld\n", limit, totalSum);
}

int main() {
    int limit;

    printf("Enter the upper limit for prime number generation: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Invalid input. Please enter an integer greater than 1.\n");
        return EXIT_FAILURE;
    }

    int *isPrime = sieveOfEratosthenes(limit);
    
    printf("Prime numbers up to %d:\n", limit);
    printArray(isPrime, limit);
    
    primeStatistics(isPrime, limit);

    free(isPrime);
    return EXIT_SUCCESS;
}