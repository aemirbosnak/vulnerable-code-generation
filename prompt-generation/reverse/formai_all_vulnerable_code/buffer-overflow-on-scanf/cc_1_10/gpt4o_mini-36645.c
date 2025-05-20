//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true;  // 2 and 3 are prime numbers

    // Check for even numbers or multiples of 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    // Check for other factors
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit, int **primes, int *prime_count) {
    *prime_count = 0;
    *primes = (int *)malloc(limit * sizeof(int));
    
    if (*primes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int num = 2; num < limit; num++) {
        if (is_prime(num)) {
            (*primes)[(*prime_count)++] = num;
        }
    }
}

// Function to print the prime numbers
void print_primes(int *primes, int prime_count) {
    printf("Prime numbers:\n");
    for (int i = 0; i < prime_count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// Function to free allocated memory for primes
void free_primes(int *primes) {
    free(primes);
}

int main() {
    int limit;
    int *primes = NULL;
    int prime_count = 0;

    // Asking the user to input the limit
    printf("Enter the upper limit for prime number generation: ");
    scanf("%d", &limit);

    // Generate prime numbers
    generate_primes(limit, &primes, &prime_count);
    
    // Print the generated prime numbers
    print_primes(primes, prime_count);
    
    // Free the allocated memory
    free_primes(primes);

    return 0;
}