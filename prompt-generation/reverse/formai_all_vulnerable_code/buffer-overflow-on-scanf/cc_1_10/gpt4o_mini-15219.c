//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    if (number <= 3) {
        return true; // 2 and 3 are prime numbers
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false; // multiples of 2 and 3 are not prime
    }
    
    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers within a specified range
void generate_primes(int lower_limit, int upper_limit) {
    printf("Prime numbers between %d and %d:\n", lower_limit, upper_limit);
    
    // Start at the lower limit and check each number
    for (int number = lower_limit; number <= upper_limit; number++) {
        if (is_prime(number)) {
            printf("%d ", number);
        }
    }
    printf("\n"); // New line for better output formatting
}

// Function to handle user input and execute prime generation
void prime_number_generator() {
    int lower_limit, upper_limit;

    // Get user input for the range
    printf("Enter the lower limit: ");
    scanf("%d", &lower_limit);
    printf("Enter the upper limit: ");
    scanf("%d", &upper_limit);

    // Validate the input range
    if (lower_limit > upper_limit) {
        printf("Invalid range! The lower limit must be less than or equal to the upper limit.\n");
        return;
    }

    // Generate prime numbers within the valid range
    generate_primes(lower_limit, upper_limit);
}

// Main function
int main() {
    printf("Welcome to the Prime Number Generator!\n");
    char continue_choice;

    // Loop to allow multiple executions
    do {
        prime_number_generator();
        printf("Do you want to generate another set of prime numbers? (y/n): ");
        scanf(" %c", &continue_choice);
    } while (continue_choice == 'y' || continue_choice == 'Y');

    printf("Thank you for using the Prime Number Generator. Goodbye!\n");
    return 0;
}