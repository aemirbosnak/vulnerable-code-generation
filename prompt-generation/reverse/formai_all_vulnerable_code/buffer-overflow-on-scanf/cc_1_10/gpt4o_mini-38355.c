//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * Function to check if a number is prime
 * @param num - The number to be checked
 * @return True if prime, false otherwise
 */
bool is_prime(int num) {
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    if (num <= 3) return true;   // 2 and 3 are prime numbers

    // Exclude multiples of 2 and 3
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Check all numbers of the form 6k +/- 1
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

/**
 * Function to generate prime numbers up to a given limit
 * @param limit - The upper limit for prime number generation
 */
void generate_primes(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

/**
 * Function to get user input and validate it
 * @return The valid integer input from user
 */
int get_input() {
    int limit;
    while (1) {
        printf("Enter a positive integer limit for prime generation: ");
        if (scanf("%d", &limit) != 1 || limit <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            while(getchar() != '\n'); // clear the input buffer
        } else {
            break;
        }
    }
    return limit;
}

/**
 * Main function
 * Entry point of the program
 */
int main() {
    int limit = get_input();  // Get valid input from the user
    generate_primes(limit);   // Generate and display prime numbers
    return 0;
}