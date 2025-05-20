//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int number) {
    if (number <= 1) return 0; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) 
            return 0; // Found a divisor, not prime
    }
    return 1; // No divisors found, it's prime
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to print a fancy start message
void print_start_message() {
    printf("=======================================\n");
    printf("    WELCOME TO THE PRIME GENERATOR    \n");
    printf("    Generating primes... Please wait   \n");
    printf("=======================================\n");
}

// Function to read an integer from the user
int read_limit() {
    int limit;
    printf("Enter the upper limit for prime generation: ");
    while (scanf("%d", &limit) != 1 || limit <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while(getchar() != '\n'); // Clear the buffer
    }
    return limit;
}

// Function to print a closing message
void print_closing_message() {
    printf("=======================================\n");
    printf("         THANK YOU FOR USING          \n");
    printf("          THE PRIME GENERATOR         \n");
    printf("=======================================\n");
}

int main() {
    print_start_message();

    int limit = read_limit(); // Get the limit from the user
    generate_primes(limit);   // Generate and print the primes

    print_closing_message();   // Print a closing message
    return 0;
}