//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is a prime
bool is_prime(int num) {
    if (num <= 1) return false; // Numbers less than 2 are not prime
    if (num <= 3) return true;  // 2 and 3 are prime

    // Eliminate even numbers and multiples of 3
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Use 6k ± 1 rule for testing primality
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate an array of prime numbers up to a given limit
int* generate_primes(int limit, int* size) {
    // Allocate enough memory to store the primes
    int* primes = malloc(limit * sizeof(int));
    if (primes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    *size = 0; // Initialize the size of the prime numbers array

    // Loop through all numbers from 2 up to the limit
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[*size] = num; // Store the prime number
            (*size)++; // Increment the size
        }
    }

    return primes; // Return the list of prime numbers
}

// Function to print an array of integers
void print_primes(int* primes, int size) {
    printf("Prime numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", primes[i]);
        // Print a new line after every 10 primes for better readability
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Main function to drive the program
int main() {
    int limit;

    // Ask user for the limit
    printf("Enter the upper limit to generate prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 2) {
        fprintf(stderr, "Invalid input! Please enter an integer greater than 1.\n");
        return EXIT_FAILURE;
    }

    int size;
    int* primes = generate_primes(limit, &size); // Generate the prime numbers

    // Print the generated prime numbers
    print_primes(primes, size);

    // Free the allocated memory
    free(primes);
    return EXIT_SUCCESS; // Successful exit
}