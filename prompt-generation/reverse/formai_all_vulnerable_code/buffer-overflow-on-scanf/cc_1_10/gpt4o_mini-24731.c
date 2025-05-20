//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to generate primes using traditional method
void generate_primes_traditional(int limit) {
    printf("Prime numbers up to %d (Traditional Method):\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to generate primes using Sieve of Eratosthenes
void generate_primes_sieve(int limit) {
    bool *sieve = malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++) {
        sieve[i] = true; // Assume all numbers are prime initially
    }
    sieve[0] = sieve[1] = false; // 0 and 1 are not prime

    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false; // Mark multiples of i as non-prime
            }
        }
    }

    printf("Prime numbers up to %d (Sieve of Eratosthenes):\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(sieve);
}

// Main function to drive the program
int main() {
    int limit;
    int method_choice;

    printf("Enter the upper limit for prime number generation: ");
    scanf("%d", &limit);

    printf("Choose the method to generate primes:\n");
    printf("1. Traditional Method\n");
    printf("2. Sieve of Eratosthenes\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &method_choice);

    switch (method_choice) {
        case 1:
            generate_primes_traditional(limit);
            break;
        case 2:
            generate_primes_sieve(limit);
            break;
        default:
            printf("Invalid choice! Please select 1 or 2.\n");
            break;
    }

    return 0;
}