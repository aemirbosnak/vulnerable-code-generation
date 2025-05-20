//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true;  // 2 and 3 are prime numbers

    if (number % 2 == 0 || number % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false; // Check for other factors
    }
    return true;
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d:\n", limit);
    
    for (int number = 2; number <= limit; number++) {
        if (is_prime(number)) {
            printf("%d ", number); // Print the prime number
        }
    }
    printf("\n"); // New line after printing all prime numbers
}

// Function to take input from user
int get_user_input() {
    int limit;
    printf("Enter the upper limit to generate prime numbers: ");
    
    while (true) {
        int result = scanf("%d", &limit); 
        if (result != 1 || limit < 0) {
            printf("Invalid input. Please enter a positive integer: ");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            break; // Valid input
        }
    }
    
    return limit;
}

// Function to display program features
void display_intro() {
    printf("***************************************\n");
    printf("*         Prime Number Generator      *\n");
    printf("***************************************\n");
    printf("This program generates all prime numbers up to a given limit.\n");
    printf("Please follow the prompts to enter the limit.\n");
    printf("Prime numbers are numbers greater than 1 that are only divisible by 1 and themselves.\n");
    printf("***************************************\n");
}

int main() {
    display_intro(); // Display introductory information
    int limit = get_user_input(); // Get user-defined limit for prime number generation
    generate_primes(limit); // Generate and display prime numbers up to the limit
    return 0;
}