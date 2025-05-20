//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a divisor, not a prime number
        }
    }
    return true; // No divisors found, it's a prime number
}

// Function to print prime numbers in the given range
void print_primes_in_range(int start, int end) {
    if (start < 2) {
        start = 2; // The first prime number is 2
    }
    
    printf("Prime numbers between %d and %d are:\n", start, end);
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num); // Print the prime number
        }
    }
    printf("\n"); // New line after printing all primes
}

// Main function to take user input and execute the prime number generator
int main() {
    int start, end;

    // Prompt user for input range
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    // Validate range input
    if (start < 0 || end < 0) {
        printf("Please enter non-negative integers for the range.\n");
        return 1; // Exit with an error code
    }
    
    if (start > end) {
        printf("The start of the range should be less than or equal to the end.\n");
        return 1; // Exit with an error code
    }
    
    // Print the prime numbers in the specified range
    print_primes_in_range(start, end);

    return 0; // Successful termination of the program
}