//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initializeArray(bool *isPrime, int limit) {
    for (int i = 0; i <= limit; i++) {
        isPrime[i] = true;  // Assume all numbers are prime initially
    }
    isPrime[0] = false;  // 0 is not a prime number
    isPrime[1] = false;  // 1 is not a prime number
}

void generatePrimes(int limit) {
    bool *isPrime = malloc((limit + 1) * sizeof(bool));
    if (!isPrime) {
        printf("Memory allocation failed!\n");
        return;
    }

    initializeArray(isPrime, limit);

    for (int num = 2; num * num <= limit; num++) {
        if (isPrime[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                isPrime[multiple] = false;  // Mark multiples as non-prime
            }
        }
    }

    // Display the prime numbers
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(isPrime); // Avoid memory leak
}

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the upper limit for prime number generation: ");
    
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a valid upper limit (integer greater than 1): ");
        while (getchar() != '\n');  // Clear invalid input
    }

    printf("Generating primes up to %d...\n", limit);
    generatePrimes(limit);
    
    printf("Prime number generation completed. Thank you for using the program!\n");
    return 0;
}