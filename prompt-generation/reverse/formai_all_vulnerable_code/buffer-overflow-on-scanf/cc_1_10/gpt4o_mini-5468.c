//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate primes up to a specified limit
void generate_primes(int limit) {
    printf("Welcome to Prime Pastries!\n");
    printf("We use the following prime numbers for our secret recipes:\n");
    
    // Array to store prime numbers
    int* primes = (int*) malloc(limit * sizeof(int));
    int prime_count = 0;

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i;
        }
    }

    // Print the list of prime numbers in a delicious format
    printf("\nPrime Ingredients:\n");
    for (int i = 0; i < prime_count; i++) {
        printf(" - %d\n", primes[i]);
    }

    // Offering additional information based on the number of primes found
    if (prime_count == 0) {
        printf("Looks like we have no prime ingredients for our recipes!\n");
    } else if (prime_count < 10) {
        printf("We have a scarce selection of prime ingredients, perfect for a minimalistic recipe!\n");
    } else {
        printf("Wow! We have a plethora of prime ingredients. Time to bake something special!\n");
    }

    // Free allocated memory
    free(primes);
}

int main() {
    int limit;

    printf("Enter the maximum number to generate prime numbers: ");
    scanf("%d", &limit);

    if (limit < 2) {
        printf("The limit should be 2 or greater!\n");
        return 1; // Exiting the program for invalid input
    }

    // Generate and display prime numbers
    generate_primes(limit);
    
    printf("\nThank you for visiting Prime Pastries!\n");
    return 0;
}