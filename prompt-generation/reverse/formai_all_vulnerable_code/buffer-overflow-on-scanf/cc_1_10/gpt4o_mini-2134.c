//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
int* generate_primes(int limit, int* count) {
    *count = 0;
    int* primes = (int*)malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[(*count)++] = num; // Store prime and increase count
        }
    }
    return primes;
}

// Function to print the prime numbers
void print_primes(int* primes, int count) {
    printf("Prime numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// Function to free allocated memory
void free_primes(int* primes) {
    free(primes);
}

int main() {
    int limit;
    
    printf("Enter the upper limit to generate prime numbers: ");
    while (true) {
        if (scanf("%d", &limit) != 1 || limit < 2) {
            printf("Please enter a valid integer greater than or equal to 2: ");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break; // Valid input, exit loop
        }
    }

    int prime_count;
    int* primes = generate_primes(limit, &prime_count);
    
    print_primes(primes, prime_count);
    
    free_primes(primes);
    
    return 0;
}