//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool is_prime(int number);
void print_primes_in_range(int start, int end);

// The main function serves as the entry point of the program
int main() {
    int lower_bound, upper_bound;

    // Requesting user input for the range to search for prime numbers
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower_bound);
    
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper_bound);

    // Validating the range input
    if (lower_bound < 2) {
        printf("The lower bound should be at least 2, as 0 and 1 are not prime.\n");
        return 1; // Program exits if input is invalid
    }
    if (upper_bound < lower_bound) {
        printf("The upper bound should be greater than or equal to the lower bound.\n");
        return 1; // Program exits if input is invalid
    }

    // Print the prime numbers in the specified range
    printf("Prime numbers between %d and %d are:\n", lower_bound, upper_bound);
    print_primes_in_range(lower_bound, upper_bound);

    return 0; // Program successfully completed
}

// This function determines if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false; // Found a divisor, hence not prime
        }
    }
    return true; // No divisors found means the number is prime
}

// This function prints all prime numbers in a given range
void print_primes_in_range(int start, int end) {
    for (int current_number = start; current_number <= end; current_number++) {
        // Utilize the is_prime function to check primality
        if (is_prime(current_number)) {
            printf("%d ", current_number); // Output the prime number found
        }
    }
    printf("\n"); // New line after listing all prime numbers
}