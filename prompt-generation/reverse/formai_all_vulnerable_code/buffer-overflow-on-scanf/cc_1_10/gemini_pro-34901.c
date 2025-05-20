//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(unsigned int num) {
    if (num <= 1) {
        return false;
    }
    for (unsigned int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers
unsigned int *generate_primes(unsigned int n) {
    unsigned int *primes = malloc(sizeof(unsigned int) * n);
    unsigned int count = 0;
    unsigned int num = 2;
    while (count < n) {
        if (is_prime(num)) {
            primes[count++] = num;
        }
        num++;
    }
    return primes;
}

// Function to print an array of prime numbers
void print_primes(unsigned int *primes, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        printf("%u ", primes[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Get the number of prime numbers to generate
    unsigned int n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%u", &n);

    // Generate the prime numbers
    unsigned int *primes = generate_primes(n);

    // Print the prime numbers
    printf("The first %u prime numbers are: ", n);
    print_primes(primes, n);

    // Free the memory allocated for the array of prime numbers
    free(primes);

    return 0;
}