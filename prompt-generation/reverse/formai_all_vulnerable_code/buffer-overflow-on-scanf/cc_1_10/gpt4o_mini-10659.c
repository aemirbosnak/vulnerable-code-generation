//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: mathematical
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it is prime
}

// Function to generate prime numbers up to a certain limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int count = 2; count <= limit; count++) {
        if (is_prime(count)) {
            printf("%d ", count); // Print the prime number
        }
    }
    printf("\n"); // New line after all primes have been printed
}

// Function to generate prime numbers in a specified range
void generate_primes_in_range(int start, int end) {
    if (start < 2) {
        start = 2; // Adjust start to the first prime number
    }
    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int count = start; count <= end; count++) {
        if (is_prime(count)) {
            printf("%d ", count); // Print the prime number
        }
    }
    printf("\n"); // New line after all primes have been printed
}

// Function to count the number of primes up to a certain limit
int count_primes(int limit) {
    int prime_count = 0;
    for (int count = 2; count <= limit; count++) {
        if (is_prime(count)) {
            prime_count++; // Increment the prime count
        }
    }
    return prime_count; // Return the total count of primes
}

// Function to calculate the nth prime number
int nth_prime(int n) {
    int count = 0;
    int num = 1; // Start from 1
    while (count < n) {
        num++; // Check next number
        if (is_prime(num)) {
            count++; // Increment count if prime found
        }
    }
    return num; // Return the nth prime number found
}

// Function to generate the first n prime numbers
void generate_first_n_primes(int n) {
    printf("First %d prime numbers are:\n", n);
    int count = 0;
    int num = 1; // Start from 1
    while (count < n) {
        num++;
        if (is_prime(num)) {
            printf("%d ", num); // Print prime number
            count++; // Increment the count
        }
    }
    printf("\n"); // New line after all primes have been printed
}

// Main function to drive the program
int main() {
    int choice, limit, start, end, n;

    // User menu for interacting with the prime number generator
    do {
        printf("Prime Number Generator Menu:\n");
        printf("1. Generate primes up to a limit\n");
        printf("2. Generate primes in a range\n");
        printf("3. Count primes up to a limit\n");
        printf("4. Find nth prime number\n");
        printf("5. Generate first n prime numbers\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter limit: ");
                scanf("%d", &limit);
                generate_primes(limit);
                break;
            case 2:
                printf("Enter start and end of range: ");
                scanf("%d %d", &start, &end);
                generate_primes_in_range(start, end);
                break;
            case 3:
                printf("Enter limit: ");
                scanf("%d", &limit);
                printf("Number of primes up to %d: %d\n", limit, count_primes(limit));
                break;
            case 4:
                printf("Enter n to find the nth prime: ");
                scanf("%d", &n);
                printf("The %dth prime number is %d\n", n, nth_prime(n));
                break;
            case 5:
                printf("Enter n to generate first n primes: ");
                scanf("%d", &n);
                generate_first_n_primes(n);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0; // Exit of the program
}