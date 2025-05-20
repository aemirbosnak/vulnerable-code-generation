//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function Prototypes
void print_welcome_message();
bool is_prime(int num);
void generate_primes(int limit);
void print_prime(int prime, int index);

int main() {
    print_welcome_message();

    int limit;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);
    
    if (limit < 2) {
        printf("No prime numbers available in the given range.\n");
        return 0;
    }

    generate_primes(limit);
    
    return 0;
}

// Welcome message to users
void print_welcome_message() {
    printf("=========================================\n");
    printf("         Prime Number Generator         \n");
    printf("=========================================\n");
    printf("Welcome, brave soul! You are about to embark \n");
    printf("on a journey through the realm of prime numbers!\n");
    printf("=========================================\n");
}

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false; // Numbers less than 2 are not prime
    if (num <= 3) return true;  // 2 and 3 are prime numbers
    
    // Eliminate multiples of 2 and 3
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i <= sqrt(num); i += 6) {
        // Check against all numbers in the form of 6k ± 1
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    
    return true;
}

// Function to generate and print prime numbers up to the given limit
void generate_primes(int limit) {
    int count = 0;

    printf("\nPrime numbers up to %d are:\n", limit);
    printf("-------------------------------------------------\n");
    
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            print_prime(num, count);
            count++;
        }
    }

    printf("-------------------------------------------------\n");
    printf("Total prime numbers found: %d\n", count);
}

// Function to print a formatted prime number
void print_prime(int prime, int index) {
    // Print the prime number with its index in a quirky format
    printf("Prime #%2d: *~* %d *~*\n", index + 1, prime);
}