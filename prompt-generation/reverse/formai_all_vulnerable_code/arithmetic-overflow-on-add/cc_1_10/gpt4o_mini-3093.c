//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function declarations
void sieveOfEratosthenes(int limit);
void trialDivision(int limit);
bool isPrime(int number);

int main() {
    int limit;
    int choice;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Choose the method for generating prime numbers:\n");
    printf("1. Sieve of Eratosthenes\n");
    printf("2. Trial Division\n");
    printf("Enter your choice (1 or 2): ");
    
    // Input validation for choice
    while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid input. Please enter 1 or 2: ");
        while(getchar() != '\n'); // Clear the newline character
    }

    printf("Enter the limit for generating prime numbers: ");
    
    // Input validation for limit
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Invalid input. Please enter an integer greater than or equal to 2: ");
        while(getchar() != '\n'); // Clear the newline character
    }

    printf("Generating prime numbers up to %d using ", limit);
    if (choice == 1) {
        printf("Sieve of Eratosthenes...\n");
        sieveOfEratosthenes(limit);
    } else {
        printf("Trial Division...\n");
        trialDivision(limit);
    }

    return 0;
}

// Function to generate prime numbers using the Sieve of Eratosthenes
void sieveOfEratosthenes(int limit) {
    bool *is_prime = malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false; // We know 0 and 1 are not prime numbers.

    for (int p = 2; p * p <= limit; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= limit; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(is_prime);
}

// Function to generate prime numbers using trial division
void trialDivision(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}