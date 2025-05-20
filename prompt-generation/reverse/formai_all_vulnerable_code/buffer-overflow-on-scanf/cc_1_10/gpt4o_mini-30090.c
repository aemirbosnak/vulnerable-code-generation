//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LENGTH 1000

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // Handle 0 and 1
    if (number <= 3) return true;  // 2 and 3 are prime

    if (number % 2 == 0 || number % 3 == 0) return false; // Exclude multiples of 2 and 3

    // Check for factors up to the square root of number
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a limit
void generate_primes(int limit) {
    int count = 0; // Count of prime numbers generated
    int *primes = malloc(sizeof(int) * MAX_LENGTH); // Dynamically allocating memory for primes

    printf("******************************************\n");
    printf("         Welcome to the Prime Number       \n");
    printf("            Generator Extravaganza!        \n");
    printf("******************************************\n");
    printf("Generating prime numbers up to %d:\n\n", limit);

    // Collecting prime numbers
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            primes[count++] = num; // Save the prime
            printf("* %d is a prime number! *\n", num);
        }
    }

    // Summary of primes generated
    printf("\nFinished generating primes!\n");
    printf("Total number of primes found: %d\n", count);
    
    // Optionally print all primes together
    printf("\nPrime Numbers are: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Free allocated memory
    free(primes);
}

int main() {
    int limit;

    // Asking user for input
    printf("Enter the limit up to which you want to generate prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 0) {
        printf("That's not a valid number! Please try again with a positive integer.\n");
        return EXIT_FAILURE; // Exit with failure if input is invalid
    }

    // Generate primes
    generate_primes(limit);

    // Farewell message
    printf("Thank you for participating in the Prime Number Generator Extravaganza!\n");
    printf("Keep on calculating, and may you find countless primes ahead!\n");
 
    return EXIT_SUCCESS; // Successful completion
}