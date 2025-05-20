//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false; // Numbers less than or equal to 1 are not prime
    if (num == 2) return true;  // 2 is a prime number
    if (num % 2 == 0) return false; // Exclude even numbers greater than 2

    // Check for factors up to the square root of num
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false; // Found a factor, num is not prime
        }
    }
    return true; // No factors found, num is prime
}

// Function to generate and print prime numbers
void generate_primes(int limit) {
    printf("🎉 Welcome to the Prime Number Generator! 🎉\n\n");
    printf("Generating prime numbers up to %d:\n\n", limit);

    bool found_prime = false; // Flag to check if we've found any primes

    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("✨ %d is a prime number! ✨\n", num);
            found_prime = true; // We've found at least one prime
        }
    }

    if (!found_prime) {
        printf("Oops! No prime numbers found up to %d!\n", limit);
    } else {
        printf("\n🎉 Finished generating prime numbers! 🎉\n");
    }
}

// Function to get user input
int get_user_input() {
    int limit;
    printf("Please enter a positive integer to find primes up to: ");
    
    // Loop until a valid input is received
    while (true) {
        scanf("%d", &limit);
        if (limit > 0) {
            return limit; // Return the valid positive integer
        }
        printf("Oops! That's not a positive integer. Please try again: ");
    }
}

int main() {
    printf("🌟 Hello, Prime Enthusiast! 🌟\n");
    
    int limit = get_user_input();
    generate_primes(limit);
    
    printf("\nThank you for using the Prime Number Generator! Come back for more primes! 😊\n");
    return 0; // Signal successful completion
}