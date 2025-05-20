//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function declarations
bool is_prime(int number);
void generate_primes(int limit);
void print_primes(int *primes, int count);
int *dynamic_prime_array(int capacity);
void free_prime_array(int *array);

int main() {
    int limit;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the upper limit for prime generation: ");
    if(scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Invalid input. Please enter an integer greater than or equal to 2.\n");
        return EXIT_FAILURE;
    }

    generate_primes(limit);

    return EXIT_SUCCESS;
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    
    // 6k +/- 1 rule
    if (number % 2 == 0 || number % 3 == 0) return false;
    
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to dynamically create an array of prime numbers
int *dynamic_prime_array(int capacity) {
    int *array = (int *)malloc(capacity * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return array;
}

// Function to free dynamically allocated memory
void free_prime_array(int *array) {
    free(array);
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    int capacity = limit / 2; // Rough estimate for maximum prime count
    int *primes = dynamic_prime_array(capacity);
    int count = 0;

    for (int i = 2; i <= limit; ++i) {
        if (is_prime(i)) {
            primes[count++] = i;
            if (count >= capacity) {
                capacity *= 2;
                primes = (int *)realloc(primes, capacity * sizeof(int));
                if (primes == NULL) {
                    fprintf(stderr, "Memory reallocation failed\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    print_primes(primes, count);
    free_prime_array(primes);
}

// Function to print prime numbers
void print_primes(int *primes, int count) {
    printf("Prime numbers up to the specified limit:\n");
    for (int i = 0; i < count; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\nTotal prime count: %d\n", count);
}