//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 10000

// Function declarations
bool is_prime(int n);
void generate_prime_numbers(int limit);
void display_primes(int *primes, int count);

int main() {
    int limit;
    
    printf("Welcome to the Enigmatic Prime Number Generator!\n");
    printf("Enter the upper limit to generate prime numbers (up to %d): ", MAX);
    scanf("%d", &limit);

    if (limit <= 0 || limit > MAX) {
        printf("Hmm, that's quite the riddle! Please choose a number between 1 and %d.\n", MAX);
        return 1;
    }
    
    generate_prime_numbers(limit);
    
    return 0;
}

// A mysterious function that checks if a number is prime.
bool is_prime(int n) {
    if (n <= 1) return false; // The conundrum begins!
    if (n <= 3) return true; // The smallest primes revealed...

    // Only check up to the square root of n for factors
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false; // A divisor found! Not prime...
    }
    return true; // A prime! Secrets kept safe...
}

// Generating prime numbers until the given limit
void generate_prime_numbers(int limit) {
    int *primes = (int *)malloc(limit * sizeof(int)); // Allocating memory for our mystery container
    int count = 0; // The count of primes unearthed

    if (primes == NULL) {
        printf("Alas! Memory allocation failed. The primes remain undiscovered...\n");
        return;
    }

    for (int num = 2; num <= limit; num++) { // From the dawn of 2...
        if (is_prime(num)) { // The ultimate test of primality!
            primes[count++] = num; // A prime is found, captured within!
        }
    }

    // Reveal the primes discovered on this whimsical journey
    display_primes(primes, count);
    free(primes); // Let them roam free!
}

// Function to display the found primes
void display_primes(int *primes, int count) {
    printf("The prime numbers unveiled between 2 and your limit:\n");

    for (int i = 0; i < count; i++) { // For each found prime...
        printf("%d ", primes[i]); // Display their essence...
    }
    printf("\nA total of %d primes were found... until next time!\n", count); // The grand tally...
}