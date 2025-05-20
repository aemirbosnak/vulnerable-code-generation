//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_SIZE 1000  // Maximum number of prime numbers we want to find

// Function to check if a number is prime
bool is_prime(int number) {
    // Special cases
    if (number <= 1) return false; // 0 and 1 are not primes
    if (number <= 3) return true;  // 2 and 3 are prime

    // Eliminate multiples of 2 and 3
    if (number % 2 == 0 || number % 3 == 0) return false;

    // Check potential factors from 5 to sqrt(number)
    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate a list of prime numbers
void generate_primes(int *primes, int limit) {
    int count = 0; // Counter for how many primes we have found

    // Check numbers starting from 2 up to the limit
    for (int num = 2; count < limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num; // Store the prime number
        }
    }
}

// Function to display a list of prime numbers
void display_primes(int *primes, int count) {
    printf("Generated Prime Numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
        // Print a new line after every 10 primes for better readability
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n"); // End line after all primes are displayed
}

// Main function for the Prime Number Generator Program
int main() {
    int limit;  // Number of prime numbers to generate
    int primes[MAX_SIZE]; // Array to hold the generated primes

    // User input for how many primes to generate
    printf("Welcome to the Prime Number Generator!\n");
    printf("Enter the number of prime numbers you want to generate (Max: %d): ", MAX_SIZE);
    scanf("%d", &limit);

    // Check if the input is within valid range
    if (limit < 1 || limit > MAX_SIZE) {
        printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    // Generate the prime numbers
    generate_primes(primes, limit);
    
    // Display the generated prime numbers
    display_primes(primes, limit);

    // Randomly select a prime number from the generated list
    int random_index = rand() % limit; // Random index to select a prime
    printf("Randomly selected prime number: %d\n", primes[random_index]);

    // Exit message
    printf("Thank you for using the Prime Number Generator!\n");
    return 0;
}