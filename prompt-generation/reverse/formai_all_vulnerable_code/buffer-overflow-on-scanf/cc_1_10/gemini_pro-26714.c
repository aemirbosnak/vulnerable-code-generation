//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to generate a list of prime numbers up to a given limit
int *generate_primes(int limit, int *length) {
    // Create an array to store the prime numbers
    int *primes = malloc(limit * sizeof(int));

    // Initialize the length of the array to 0
    *length = 0;

    // Iterate over the numbers up to the limit
    for (int i = 2; i <= limit; i++) {
        // Check if the number is prime
        if (is_prime(i)) {
            // Add the number to the array of prime numbers
            primes[(*length)++] = i;
        }
    }

    // Return the array of prime numbers
    return primes;
}

// Function to print an array of prime numbers
void print_primes(int *primes, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");
}

int main() {
    // Get the limit from the user
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Generate a list of prime numbers up to the limit
    int *primes;
    int length;
    primes = generate_primes(limit, &length);

    // Print the list of prime numbers
    printf("The prime numbers up to %d are: ", limit);
    print_primes(primes, length);

    // Free the memory allocated for the array of prime numbers
    free(primes);

    return 0;
}