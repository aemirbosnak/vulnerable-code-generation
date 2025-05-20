//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000  // Maximum limit for prime number generation

// Function prototypes
void displayBanner();
void generatePrimes(int limit);
bool isPrime(int number);
void printPrime(int primeIndex, int prime);

int main() {
    int limit;

    // Display a welcoming banner
    displayBanner();

    // Ask the user for the upper limit
    printf("Enter the upper limit for prime number generation (up to %d): ", MAX_SIZE);
    scanf("%d", &limit);

    // Validate the input
    if (limit < 2 || limit > MAX_SIZE) {
        printf("Please enter a number between 2 and %d.\n", MAX_SIZE);
        return EXIT_FAILURE;
    }

    // Generate prime numbers up to the user-defined limit
    generatePrimes(limit);

    return EXIT_SUCCESS;
}

// Function to display an immersive banner
void displayBanner() {
    printf("========================================\n");
    printf("     Welcome to the Prime Number\n");
    printf("        Generator Program!\n");
    printf("========================================\n");
}

// Function to generate and display prime numbers up to 'limit'
void generatePrimes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);

    // Initializations
    int primeCount = 0;

    // Loop through each number up to 'limit'
    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            // Print the prime number
            printPrime(primeCount, num);
            primeCount++;
        }
    }

    // Print total primes found
    printf("Total prime numbers found: %d\n", primeCount);
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number < 2) return false;

    // Check divisibility up to the square root of 'number'
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;  // Number is not prime
        }
    }
    return true;  // Number is prime
}

// Function to print a prime number in a formatted manner
void printPrime(int primeIndex, int prime) {
    printf("Prime %2d: %d\n", primeIndex + 1, prime);
}