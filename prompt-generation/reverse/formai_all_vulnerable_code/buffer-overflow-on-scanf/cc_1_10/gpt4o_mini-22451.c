//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void generatePrimes(int limit);
void printPrimes(int *sieve, int limit);

int main() {
    int limit;

    // Welcome message and instructions
    printf("------------------------------------------------\n");
    printf("            Prime Number Generator               \n");
    printf("------------------------------------------------\n");
    printf("Enter the upper limit to generate prime numbers: ");
    
    // Reading the upper limit
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a valid number greater than 1.\n");
        return 1;
    }

    // Generate and display prime numbers
    generatePrimes(limit);

    return 0;
}

void generatePrimes(int limit) {
    // Create a boolean array to mark sieve of Eratosthenes
    int *sieve = malloc((limit + 1) * sizeof(int));
    if (sieve == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i <= limit; i++) {
        sieve[i] = 1; // Assume all numbers are prime
    }

    sieve[0] = sieve[1] = 0; // 0 and 1 are not prime numbers

    // Start the Sieve of Eratosthenes algorithm
    for (int p = 2; p * p <= limit; p++) {
        if (sieve[p] == 1) { // If prime
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                sieve[multiple] = 0; // Mark multiples of p as non-prime
            }
        }
    }

    // Print the resulting prime numbers
    printf("Prime numbers up to %d are:\n", limit);
    printPrimes(sieve, limit);

    // Free allocated memory
    free(sieve);
}

void printPrimes(int *sieve, int limit) {
    for (int i = 2; i <= limit; i++) {
        if (sieve[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}