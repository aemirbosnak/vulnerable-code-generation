//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
bool is_prime(int number);
void generate_primes(int limit);
void print_primes(int* primes, int count);
void introspective_message();

// Main function
int main() {
    introspective_message();
    int limit;

    printf("Enter the upper limit for generating prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Please enter a valid number greater than or equal to 2.\n");
        return EXIT_FAILURE;
    }

    generate_primes(limit);
    return EXIT_SUCCESS;
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, is prime
}

// Function to generate and print prime numbers up to a limit
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    int* primes = (int*)malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num; // Store prime number
        }
    }

    print_primes(primes, count); // Print the collected prime numbers
    free(primes); // Free allocated memory
}

// Function to print the prime numbers
void print_primes(int* primes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) { // New line every 10 primes
            printf("\n");
        }
    }
    printf("\nTotal primes found: %d\n", count);
}

// Function that gives an introspective message about the program
void introspective_message() {
    printf("Welcome to the Introspective C Prime Number Generator!\n");
    printf("In this program, we explore the beauty of prime numbers.\n");
    printf("Primes are numbers greater than 1 with no divisors other than 1 and themselves.\n");
    printf("Let's generate some primes together and discover their wonders! 🌟\n");
}