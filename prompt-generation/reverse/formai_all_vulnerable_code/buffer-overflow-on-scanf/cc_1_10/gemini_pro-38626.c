//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    // If the number is 1, it is not prime
    if (number == 1) {
        return false;
    }

    // Iterate over all numbers from 2 to the square root of the number
    for (int i = 2; i <= number / 2; i++) {
        // If the number is divisible by any number from 2 to its square root, it is not prime
        if (number % i == 0) {
            return false;
        }
    }

    // If the number is not divisible by any number from 2 to its square root, it is prime
    return true;
}

// Function to generate a list of prime numbers up to a given number
int* generate_prime_numbers(int limit) {
    // Allocate memory for the list of prime numbers
    int* prime_numbers = (int*)malloc(sizeof(int) * limit);

    // Initialize the list of prime numbers
    int prime_number_count = 0;
    for (int i = 2; i <= limit; i++) {
        // If the number is prime, add it to the list of prime numbers
        if (is_prime(i)) {
            prime_numbers[prime_number_count] = i;
            prime_number_count++;
        }
    }

    // Return the list of prime numbers
    return prime_numbers;
}

// Function to print a list of prime numbers
void print_prime_numbers(int* prime_numbers, int limit) {
    // Print the list of prime numbers
    for (int i = 0; i < limit; i++) {
        printf("%d ", prime_numbers[i]);
    }

    // Print a newline at the end of the list
    printf("\n");
}

// Main function
int main() {
    // Get the limit from the user
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    // Generate a list of prime numbers up to the given limit
    int* prime_numbers = generate_prime_numbers(limit);

    // Print the list of prime numbers
    print_prime_numbers(prime_numbers, limit);

    // Free the memory allocated for the list of prime numbers
    free(prime_numbers);

    return 0;
}