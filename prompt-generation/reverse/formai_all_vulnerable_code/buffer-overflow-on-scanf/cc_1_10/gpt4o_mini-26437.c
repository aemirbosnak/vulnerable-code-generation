//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false; // Handle numbers less than or equal to 1
    if (num <= 3) return true; // 2 and 3 are prime numbers

    // Eliminate even numbers and divisible by 3 for efficiency
    if (num % 2 == 0 || num % 3 == 0) return false; 

    // Check divisibility starting from 5 to sqrt(num)
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false; // Found a divisor
    }

    return true; // No divisors found, thus prime
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    printf("Curious Prime Numbers up to %d:\n", limit);
    // Using a prime counter for layout purposes
    int prime_count = 0;

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            prime_count++;
            // Let's add a bit of flair, every 10 primes or so we will break the line
            if (prime_count % 10 == 0) {
                printf("\n"); // New line for every 10 prime numbers
            }
        }
    }

    printf("\nTotal prime numbers found: %d\n", prime_count);
}

// Main function to drive the prime number generation
int main() {
    int limit;

    // Asking the user for the limit
    printf("Welcome to the Curious Prime Number Generator!\n");
    printf("Enter the limit up to which you want to find prime numbers: ");
    
    // Simple input validation loop
    while (true) {
        if (scanf("%d", &limit) != 1 || limit < 2) {
            printf("Please enter a valid integer greater than 1: ");
            while(getchar() != '\n'); // Clear invalid input
        } else {
            break; // Valid input
        }
    }

    // Generate primes given the valid limit
    generate_primes(limit);
    
    printf("Thanks for using the Curious Prime Number Generator. Until next time!\n");
    return 0;
}