//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int number) {
    if (number <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    if (number <= 3) {
        return 1; // 2 and 3 are prime numbers
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return 0; // Exclude multiples of 2 and 3
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0; // Found a factor, not prime
        }
    }
    return 1; // Number is prime
}

// Function to generate a list of primes up to a limit
int* generate_primes(int limit, int* count) {
    int* primes = malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int idx = 0;
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[idx++] = num; // Store the prime number
        }
    }
    *count = idx; // Set output count of primes
    return primes; // Return the list of primes
}

// Function to print the list of primes
void print_primes(int* primes, int count) {
    printf("Prime numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        if ((i + 1) % 10 == 0) { // New line after every 10 primes
            printf("\n");
        }
    }
    printf("\n"); // Final newline
}

// Main function
int main() {
    int limit;

    printf("Enter the upper limit for prime generation: ");
    scanf("%d", &limit);

    int count = 0;
    int* primes = generate_primes(limit, &count); // Generate primes

    print_primes(primes, count); // Print the generated primes

    free(primes); // Clean up allocated memory
    return 0;
}