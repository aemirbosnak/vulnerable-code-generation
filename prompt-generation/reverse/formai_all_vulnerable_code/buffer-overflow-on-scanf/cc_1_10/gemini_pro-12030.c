//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a list of prime numbers up to a given limit
int* generate_primes(int limit, int* size) {
    // Allocate memory for the list of prime numbers
    int* primes = malloc(sizeof(int) * limit);
    if (primes == NULL) {
        *size = 0;
        return NULL;
    }

    // Initialize the list of prime numbers
    int count = 0;
    for (int i = 2; i <= limit; ++i) {
        if (is_prime(i)) {
            primes[count++] = i;
        }
    }

    // Update the size of the list of prime numbers
    *size = count;

    // Return the list of prime numbers
    return primes;
}

// Function to print a list of prime numbers
void print_primes(int* primes, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", primes[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Get the limit from the user
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Generate a list of prime numbers up to the given limit
    int* primes = NULL;
    int size = 0;
    primes = generate_primes(limit, &size);

    // Print the list of prime numbers
    if (primes != NULL) {
        printf("The prime numbers up to %d are:\n", limit);
        print_primes(primes, size);
    } else {
        printf("Error: Could not generate the list of prime numbers.\n");
    }

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}