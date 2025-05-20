//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int num) {
    // Function to check if a number is prime
    if (num <= 1) return 0;  // Numbers less than or equal to 1 are not prime
    if (num <= 3) return 1;  // 2 and 3 are prime numbers

    // Eliminate multiples of 2 and 3
    if (num % 2 == 0 || num % 3 == 0) return 0;

    // Check for prime status using 6k +/- 1 rule
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

void generate_primes(int limit) {
    // Function to generate and print prime numbers up to a specified limit
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);  // Print prime numbers
        }
    }
    printf("\n");
}

int get_user_input() {
    // Function to get user input with validation
    int limit;
    while (1) {
        printf("Enter a positive integer to generate prime numbers (or 0 to exit): ");
        if (scanf("%d", &limit) != 1 || limit < 0) {
            printf("Invalid input. Please enter a valid positive integer.\n");
            // Clear the input buffer
            while(getchar() != '\n');
        } else {
            break;  // Valid input received
        }
    }
    return limit;
}

int main() {
    // Main function to execute the prime number generator
    printf("Welcome to the Prime Number Generator!\n");
    
    while (1) {
        int limit = get_user_input(); // Take user input for the limit
        if (limit == 0) {
            printf("Exiting the program. Goodbye!\n");
            break; // Exit the program if the user enters 0
        }
        
        generate_primes(limit); // Generate and display prime numbers
    }
    
    return 0;
}