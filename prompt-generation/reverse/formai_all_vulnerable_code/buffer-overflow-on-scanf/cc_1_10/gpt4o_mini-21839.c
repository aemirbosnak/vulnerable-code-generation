//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function to determine if a number is prime */
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it is prime
}

/* Function to generate prime numbers up to a specified limit */
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

/* Function to print a simple introduction */
void print_intro() {
    printf("**********************************\n");
    printf("* Welcome to Prime Number Finder! *\n");
    printf("**********************************\n");
    printf("This program generates all prime numbers up to a specified limit.\n");
}

/* Get user input for the upper limit */
int get_user_limit() {
    int limit;
    printf("Enter the upper limit for generating prime numbers: ");
    while (scanf("%d", &limit) != 1 || limit < 2) {
        printf("Invalid input. Please enter a number greater than or equal to 2: ");
        while (getchar() != '\n'); // Clear the invalid input
    }
    return limit;
}

/* Main function to orchestrate the execution flow */
int main() {
    print_intro(); // Print program introduction

    int limit = get_user_limit(); // Get limit from the user
    generate_primes(limit); // Generate and display prime numbers

    printf("Thank you for using the Prime Number Finder!\n");
    return 0; // Return success status
}