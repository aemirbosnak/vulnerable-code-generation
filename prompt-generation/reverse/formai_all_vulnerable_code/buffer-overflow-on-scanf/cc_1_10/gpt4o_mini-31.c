//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declarations
bool is_prime(int number);
void generate_primes(int limit);
void introspective_message(int number);

int main() {
    int limit;

    // Introduction
    printf("Welcome to the Prime Number Generator!\n");
    printf("In this program, we will explore the fascinating world of prime numbers.\n");
    printf("Please enter the upper limit up to which you want to generate prime numbers: ");
    
    // Get user input
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Please enter a valid number greater than or equal to 2.\n");
        return 1; // Exit if input is invalid
    }

    // Generate and display prime numbers
    printf("Generating prime numbers up to %d...\n", limit);
    generate_primes(limit);

    return 0;
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // Negative numbers, 0, and 1 are not prime
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a divisor, so it's not prime
        }
    }
    return true; // No divisors found, it is prime
}

// Function to generate and print prime numbers up to the specified limit
void generate_primes(int limit) {
    printf("The prime numbers are:\n");
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            introspective_message(i); // Call introspective message for each prime
        }
    }
    printf("\n");
}

// Function to display an introspective message about prime numbers
void introspective_message(int number) {
    if (number < 10) {
        printf(" - %d is a single-digit prime number, a building block of many integers.\n", number);
    } 
    else if (number < 100) {
        printf(" - %d is a two-digit prime number, it dwells among friends but stands alone.\n", number);
    } 
    else {
        printf(" - %d, a three-digit prime, grand in its solitude, challenges the composite multitude.\n", number);
    }
}