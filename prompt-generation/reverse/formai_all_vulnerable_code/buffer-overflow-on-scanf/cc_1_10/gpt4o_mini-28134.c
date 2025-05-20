//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function Declarations
void generatePrimes(int limit);
bool isPrime(int num);

int main() {
    int limit;

    // User input for the prime number limit
    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the upper limit for prime number generation: ");
    scanf("%d", &limit);

    // Check for valid input
    if (limit < 2) {
        printf("Please enter a number greater than or equal to 2.\n");
        return 1;
    }

    // Generate prime numbers up to the specified limit
    generatePrimes(limit);

    return 0;
}

// Function to generate prime numbers up to a given limit
void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\nPrime number generation complete!\n");
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // Numbers less than 2 are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it is prime
}

// Additional function to display prime numbers in a formatted manner
void displayFormattedPrimes(int limit) {
    printf("Formatted Prime Numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%3d", num);
            // New line after every 10 primes for better readability
            if ((num - 1) % 10 == 0) {
                printf("\n");
            }
        }
    }
    printf("\nFormatted prime number display complete!\n");
}

// Function to find and return the total number of primes up to a given limit
int countPrimes(int limit) {
    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            count++;
        }
    }
    return count;
}

// Function to output additional prime statistics
void primeStatistics(int limit) {
    int totalPrimes = countPrimes(limit);
    printf("Total number of primes up to %d: %d\n", limit, totalPrimes);
}

// Function to generate prime numbers using the Sieve of Eratosthenes algorithm
void sieveOfEratosthenes(int limit) {
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true; // Assume all numbers are prime initially
    }

    // Implementing Sieve of Eratosthenes
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false; // Mark multiples as not prime
            }
        }
    }

    // Displaying prime numbers found by the sieve
    printf("Sieve of Eratosthenes result up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\nSieve prime generation complete!\n");

    // Free allocated memory
    free(is_prime);
}