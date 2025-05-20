//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    if (num <= 3) return 1; // 2 and 3 are prime numbers 

    if (num % 2 == 0 || num % 3 == 0) return 0; // eliminate multiples of 2 and 3

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0; // check for divisors
    }
    return 1; // found to be a prime number
}

// Function to generate prime numbers in a peaceful manner
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);
    printf("--------------------------------------------------\n");
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num); // print the prime number
        }
    }
    printf("\n--------------------------------------------------\n");
    printf("Prime number generation completed.\n");
}

// Main function to interact with the user
int main() {
    int limit;

    printf("Welcome to the Peaceful Prime Number Generator!\n");
    printf("--------------------------------------------------\n");
    printf("Please enter the upper limit for prime generation: ");
    
    // Read user input gently
    while (scanf("%d", &limit) != 1 || limit < 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n'); // clear the input buffer
    }

    // Generates prime numbers
    generate_primes(limit);

    // Display a thank you note
    printf("Thank you for using the Peaceful Prime Number Generator. Have a wonderful day!\n");
    return 0;
}