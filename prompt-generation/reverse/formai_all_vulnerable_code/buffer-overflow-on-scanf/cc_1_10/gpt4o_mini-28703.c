//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int num, int divisor) {
    if (num < 2) {
        return 0; // Numbers less than 2 are not prime
    }
    if (divisor == 1) {
        return 1; // If we reach 1, the number is prime
    }
    if (num % divisor == 0) {
        return 0; // Number is divisible, hence not prime
    }
    return is_prime(num, divisor - 1); // Recur with next divisor
}

// Recursive function to generate prime numbers in a given range
void generate_primes(int start, int end) {
    if (start > end) {
        return; // Base case: if start exceeds end, return
    }
    if (is_prime(start, start / 2)) { // Check if the current number is prime
        printf("%d ", start); // Print the prime number
    }
    generate_primes(start + 1, end); // Recur for the next number
}

// Main function to take user input and generate primes
int main() {
    int start, end;

    printf("Enter the start of the range: ");
    if (scanf("%d", &start) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the end of the range: ");
    if (scanf("%d", &end) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }

    if (start > end) {
        fprintf(stderr, "Invalid range. Start should be less than or equal to end.\n");
        exit(EXIT_FAILURE);
    }

    printf("Prime numbers between %d and %d are: ", start, end);
    generate_primes(start, end); // Call to generate prime numbers

    printf("\n");
    return 0;
}