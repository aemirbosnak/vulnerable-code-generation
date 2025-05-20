//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate prime numbers up to a limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to get a valid integer input from user
int get_valid_input() {
    int limit;
    char term;

    while (true) {
        printf("Enter the upper limit to generate primes: ");
        if (scanf("%d%c", &limit, &term) != 2 || term != '\n' || limit < 1) {
            // Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a positive integer.\n");
        } else {
            break; // Valid input received
        }
    }
    
    return limit;
}

// Main function
int main() {
    printf("Welcome to the Prime Number Generator!\n");

    int limit = get_valid_input();

    generate_primes(limit);

    printf("Thank you for using the Prime Number Generator.\n");
    
    return 0;
}