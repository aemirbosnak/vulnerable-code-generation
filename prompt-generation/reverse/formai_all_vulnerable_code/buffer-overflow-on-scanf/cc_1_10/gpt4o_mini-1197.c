//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM 1000  // Define a limit for the prime number generation

// Function to check if a number is prime
int is_prime(int n) {
    int i;
    
    if (n <= 1) return 0;  // 0 and 1 are not prime numbers
    if (n == 2) return 1;  // 2 is a prime number
    if (n % 2 == 0) return 0; // even number greater than 2 is not prime

    // Check for factors from 3 to the square root of n
    for (i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return 0;  // n is divisible, hence not prime
    }

    return 1;  // n is prime
}

// Function to generate prime numbers up to a certain limit
void generate_primes(int limit) {
    int i;
    printf("Prime numbers up to %d are:\n", limit);
    
    for (i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);  // Print the prime number
        }
    }
    printf("\n");  // New line after printing all primes
}

// Function to get user input for the limit
int get_input() {
    int limit;
    
    printf("Enter the upper limit for prime number generation (max %d): ", MAX_NUM);
    scanf("%d", &limit);
    
    // Validate input
    if (limit < 1 || limit > MAX_NUM) {
        fprintf(stderr, "Invalid input. Please enter a number between 1 and %d.\n", MAX_NUM);
        exit(1); // Exit if input is out of valid range
    }
    
    return limit;
}

// Main function to run the prime number generator
int main() {
    int upper_limit;
    
    // Get user input
    upper_limit = get_input();
    
    // Generate and display prime numbers
    generate_primes(upper_limit);
    
    return 0;  // Return success
}