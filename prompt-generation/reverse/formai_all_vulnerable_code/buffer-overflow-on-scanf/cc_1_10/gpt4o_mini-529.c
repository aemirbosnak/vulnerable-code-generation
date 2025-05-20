//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // found a divisor, not prime
        }
    }
    return true; // no divisors found, it is prime
}

// Function to generate prime numbers up to a specified limit
void generate_primes(int limit) {
    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return;
    }

    printf("Prime numbers up to %d:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num); // print the prime number
        }
    }
    printf("\n");
}

// Function to find prime factors of a number
void prime_factors(int number) {
    printf("Prime factors of %d are: ", number);
    
    // Start checking for prime factors from 2
    for (int i = 2; i <= number; i++) {
        while (number % i == 0) {
            printf("%d ", i); // print the prime factor
            number /= i; // divide the number by its prime factor
        }
    }
    printf("\n");
}

// Menu to interact with the user
void display_menu() {
    printf("Prime Number Generator and Factorization Tool\n");
    printf("1. Generate prime numbers up to a limit\n");
    printf("2. Find prime factors of a number\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    int limit, number;

    // Main loop of the program
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the limit (greater than or equal to 2): ");
                scanf("%d", &limit);
                generate_primes(limit);
                break;
            case 2:
                printf("Enter a positive number to find its prime factors: ");
                scanf("%d", &number);
                if (number <= 0) {
                    printf("Please enter a valid positive number.\n");
                } else {
                    prime_factors(number);
                }
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0); // exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0; // should never reach this point
}