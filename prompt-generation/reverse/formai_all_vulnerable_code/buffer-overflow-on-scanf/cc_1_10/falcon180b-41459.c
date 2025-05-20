//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PRIME_NUMBERS 1000 // Maximum number of prime numbers to generate

// Function to generate prime numbers
void generate_primes(int num_primes) {
    int i, j, is_prime;
    int primes[MAX_PRIME_NUMBERS]; // Array to store prime numbers
    int num_generated_primes = 0;

    // Set all numbers to prime initially
    for (i = 2; i < MAX_PRIME_NUMBERS; i++) {
        primes[i] = 1;
    }

    // Generate prime numbers
    for (i = 2; i < MAX_PRIME_NUMBERS; i++) {
        if (primes[i] == 1) {
            num_generated_primes++;
            if (num_generated_primes == num_primes) {
                break;
            }
        }
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                primes[i] = 0;
                break;
            }
        }
    }

    // Print prime numbers
    printf("Prime numbers:\n");
    for (i = 2; i < MAX_PRIME_NUMBERS; i++) {
        if (primes[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num_primes;

    // Get number of prime numbers to generate
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num_primes);

    // Generate prime numbers
    generate_primes(num_primes);

    return 0;
}