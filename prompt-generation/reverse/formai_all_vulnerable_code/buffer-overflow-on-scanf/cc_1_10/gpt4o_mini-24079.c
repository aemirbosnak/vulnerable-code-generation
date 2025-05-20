//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_LIMIT 1000

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // 0 and 1 are not prime numbers
    if (number <= 3) return true; // 2 and 3 are prime numbers
    if (number % 2 == 0 || number % 3 == 0) return false; // eliminating multiples of 2 and 3

    // Check for factors up to the square root of the number
    for (int i = 5; i <= sqrt(number); i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a specified limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to run the prime number generation process
void run_prime_generator() {
    int limit;
    printf("Enter the upper limit for generating prime numbers (max %d): ", MAX_LIMIT);
    scanf("%d", &limit);

    if (limit < 0 || limit > MAX_LIMIT) {
        printf("Invalid limit! Please enter a number between 0 and %d.\n", MAX_LIMIT);
        return;
    }

    generate_primes(limit);
}

// Main function
int main() {
    printf("======= Prime Number Generator =======\n");
    run_prime_generator();
    return 0;
}