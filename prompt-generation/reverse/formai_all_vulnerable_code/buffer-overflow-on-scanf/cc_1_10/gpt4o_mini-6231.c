//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function declaration
bool is_prime(int num);

int main() {
    int lower, upper;

    // Introduction message
    printf("Welcome to the Prime Number Generator!\n");
    printf("This program will help you find all prime numbers in a specified range.\n");

    // User input for range
    printf("Please enter the lower bound of the range: ");
    scanf("%d", &lower);
    printf("Please enter the upper bound of the range: ");
    scanf("%d", &upper);

    // Validating the range
    if (lower < 2) {
        lower = 2; // Start from the smallest prime number
    }
    if (upper < 2 || lower > upper) {
        printf("Invalid range. Please ensure the upper bound is greater than or equal to the lower bound and both are at least 2.\n");
        return 1; // Exit with an error code.
    }

    printf("Generating prime numbers between %d and %d...\n", lower, upper);
    printf("Prime numbers:\n");

    // Generating prime numbers in the specified range
    for (int num = lower; num <= upper; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");

    return 0;
}

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false; // 0 and 1 are not prime
    }
    if (num <= 3) {
        return true; // 2 and 3 are prime
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false; // Eliminate multiples of 2 and 3
    }

    // Check for factors up to the square root of num
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false; // Found a factor, not prime
        }
    }
    return true; // No factors found, it is prime
}