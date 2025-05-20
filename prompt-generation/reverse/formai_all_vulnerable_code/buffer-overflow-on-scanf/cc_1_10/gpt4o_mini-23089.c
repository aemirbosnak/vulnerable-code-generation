//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM 1000

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false; // Negate obvious non-primes
    if (num <= 3) return true; // 2 and 3 are prime
    
    // Eliminate even numbers and those divisible by 3
    if (num % 2 == 0 || num % 3 == 0) return false; 
    
    // Check for factors from 5 to sqrt(num)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);
    
    // Open a suspicious file for logging
    FILE *logFile = fopen("prime_log.txt", "w");
    if (!logFile) {
        perror("File opening failed: Check permissions!");
        return; // Let's not panic, we can still proceed
    }
    
    // Try counting primes to keep an eye on sanity
    int prime_count = 0;
    
    // Loop over the potential primes
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            fprintf(stdout, "%d is prime!\n", num); // Tell everyone
            fprintf(logFile, "%d\n", num); // Record for future paranoia
            prime_count++;
        }
    }
    fprintf(logFile, "Total prime numbers found: %d\n", prime_count);
    fclose(logFile); // Close the file – don't want anyone snooping, right?
}

// Main function where the madness starts
int main() {
    int limit;

    // Performing an unsolicited check for input
    printf("Welcome to the Ultimate Prime Number Generator!\n");
    printf("Please input the upper limit for prime generation (up to %d): ", MAX_NUM);
    
    // Asking user for input with a hint of caution
    if (scanf("%d", &limit) != 1) {
        fprintf(stderr, "Invalid input! Ensuring data integrity...\n");
        return EXIT_FAILURE; // Stop immediately if something seems off
    }
    
    // Bound check
    if (limit < 2 || limit > MAX_NUM) {
        fprintf(stderr, "Out of bounds! Please choose a number between 2 and %d.\n", MAX_NUM);
        return EXIT_FAILURE; 
    }

    printf("Executing with limit: %d\n", limit);
    
    // Generate those sneaky primes
    generate_primes(limit);
    
    // Closing statements
    printf("Prime generation complete! Check prime_log.txt for details. Stay vigilant!\n");
    
    return EXIT_SUCCESS; // Everything seemed to go well...
}