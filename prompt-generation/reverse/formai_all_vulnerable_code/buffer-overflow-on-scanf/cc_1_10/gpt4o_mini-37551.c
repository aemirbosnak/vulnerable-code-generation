//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not prime.
    if (num <= 3) return true;  // 2 and 3 are prime numbers.
    
    // Eliminate multiples of 2 and 3
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    // Check for factors from 5 to the square root of num
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a certain limit
void prime_generator(int limit) {
    printf("***** Welcome to the Prime Number Generator! *****\n");
    printf("Generating prime numbers up to %d...\n", limit);
    printf("-------------------------------------------------\n");
    
    // Loop through numbers from 2 to the specified limit
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d is a prime number!\n", i); // Exciting output for primes
        }
    }
    
    printf("-------------------------------------------------\n");
    printf("Generation completed! Hope you enjoyed the show!\n");
}

// Main function
int main() {
    int limit;
    
    // Ask user for the limit
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    // Input validation
    if (limit < 1) {
        printf("Please enter a number greater than 0. Let's try again!\n");
        return 1; // Exiting the program
    }
    
    // Generate prime numbers
    prime_generator(limit);
    
    return 0; // Program ended successfully
}