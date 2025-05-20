//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_PRIME_LIMIT 10000 // Maximum limit to generate primes
#define INITIAL_ARRAY_SIZE 100 // Initial size for dynamic array
#define RESIZE_FACTOR 2 // Factor to resize the array when needed

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) 
            return false;
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
int* generate_primes(int limit, int* prime_count) {
    int *primes = malloc(INITIAL_ARRAY_SIZE * sizeof(int));
    int size = INITIAL_ARRAY_SIZE;
    *prime_count = 0;

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            if (*prime_count >= size) {
                size *= RESIZE_FACTOR;
                primes = realloc(primes, size * sizeof(int));
            }
            primes[*prime_count] = num;
            (*prime_count)++;
        }
    }

    return primes;
}

// Function to print the generated prime numbers
void print_primes(int* primes, int prime_count) {
    printf("Generated Prime Numbers:\n");
    for (int i = 0; i < prime_count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\nTotal count of primes found: %d\n", prime_count);
}

// Main function
int main() {
    int limit, prime_count;
    
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the upper limit for prime generation (max %d):\n", MAX_PRIME_LIMIT);
    
    while (true) {
        scanf("%d", &limit);
        
        if (limit < 2 || limit > MAX_PRIME_LIMIT) {
            printf("Please enter a valid limit between 2 and %d:\n", MAX_PRIME_LIMIT);
        } else {
            break;
        }
    }
    
    // Generate primes
    int* primes = generate_primes(limit, &prime_count);
    
    // Print generated primes
    print_primes(primes, prime_count);
    
    // Free dynamically allocated memory
    free(primes);
    
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}