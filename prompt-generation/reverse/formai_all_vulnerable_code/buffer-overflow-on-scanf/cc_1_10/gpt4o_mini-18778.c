//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LIMIT 1000

// Function prototype
bool is_prime(int number);
void generate_primes(int limit);

int main() {
    int limit;

    // Introduction to the prime number generator
    printf("Welcome to the SHOCKING Prime Number Generator!\n");
    printf("Prepare to be amazed as we unveil the mysterious primes!\n");

    // Prompt user for a limit to generate prime numbers
    printf("Enter a limit up to which you want to find prime numbers (max %d): ", MAX_LIMIT);
    scanf("%d", &limit);

    // Validation of the user input
    if (limit < 2 || limit > MAX_LIMIT) {
        printf("What?! That's out of bounds! Please enter a number between 2 and %d!\n", MAX_LIMIT);
        return 1; // Exit with an error
    }

    printf("Generating prime numbers up to %d...\n", limit);
    generate_primes(limit);

    printf("And there you have it! The primes are revealed!\n");
    return 0; // Successful exit
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true; // 2 and 3 are prime
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false; // Eliminate multiples of 2 and 3
    }

    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false; // Check for factors of the form 6k ± 1
        }
    }
    return true; // It's a prime!
}

// Function to generate and display prime numbers up to a specified limit
void generate_primes(int limit) {
    printf("--------------------------------------------------\n");
    printf("List of prime numbers up to %d:\n", limit);
    printf("--------------------------------------------------\n");

    // Shockingly display the prime numbers!
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }

    printf("\n--------------------------------------------------\n");
    printf("All primes have been discovered! Can you believe it?!\n");
}