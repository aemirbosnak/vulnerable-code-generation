//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_PRIME_LIMIT 10000

// Function prototypes
void sieveOfEratosthenes(int limit);
bool isPrime(int number);
void printPrimes(int* primes, int count);

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter an upper limit (greater than 1 and less than %d): ", MAX_PRIME_LIMIT);
    scanf("%d", &limit);

    // Validate the input limit
    if (limit <= 1 || limit >= MAX_PRIME_LIMIT) {
        printf("Invalid limit! Please restart the program and input a correct limit.\n");
        return 1;
    }

    // Running the Sieve of Eratosthenes
    printf("Generating prime numbers up to %d...\n", limit);
    sieveOfEratosthenes(limit);

    return 0;
}

void sieveOfEratosthenes(int limit) {
    bool* isPrimeArray = malloc((limit + 1) * sizeof(bool));
    if (isPrimeArray == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= limit; i++) {
        isPrimeArray[i] = true; // Assume all numbers are prime initially
    }
    
    isPrimeArray[0] = isPrimeArray[1] = false; // 0 and 1 are not primes

    for (int p = 2; p * p <= limit; p++) {
        if (isPrimeArray[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrimeArray[i] = false; // Mark multiples of p as non-prime
            }
        }
    }

    // Collect and print the primes
    int* primes = (int*)malloc(limit * sizeof(int));
    int count = 0;

    for (int i = 2; i <= limit; i++) {
        if (isPrimeArray[i]) {
            primes[count++] = i; // Store prime number
        }
    }

    printPrimes(primes, count);

    // Free allocated memory
    free(isPrimeArray);
    free(primes);
}

void printPrimes(int* primes, int count) {
    printf("Prime numbers up to the specified limit:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) { // Print 10 numbers per line
            printf("\n");
        }
    }
    if (count % 10 != 0) {
        printf("\n"); // New line for the last line if not completed
    }
}