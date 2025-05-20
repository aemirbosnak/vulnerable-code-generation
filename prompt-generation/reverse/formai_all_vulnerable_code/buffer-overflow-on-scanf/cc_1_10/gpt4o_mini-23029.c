//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    if (num == 2) return true;   // 2 is the only even prime number
    if (num % 2 == 0) return false; // eliminate even numbers quickly
    
    for (int i = 3; i * i <= num; i += 2) { // Check odd factors
        if (num % i == 0) {
            return false; // Found a divisor, not prime
        }
    }
    return true; // No divisors found, it's prime
}

// Function to generate prime numbers up to a given limit
void generate_primes(int limit) {
    printf("Generating prime numbers up to %d...\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("Freshly baked prime pastry: %d\n", num);
        }
    }
}

int main() {
    int limit;
    char choice;

    printf("Welcome to the Prime Pastry Bakery!\n");
    do {
        printf("Please enter the maximum number of pastries (primes) to bake: ");
        scanf("%d", &limit);

        if (limit < 1) {
            printf("Oh no! We can't bake zero or negative pastries.\n");
            continue; // Ask for input again
        }

        generate_primes(limit);

        printf("Would you like to order another batch of pastries? (y/n): ");
        getchar(); // to consume the newline character left by scanf
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for visiting the Prime Pastry Bakery! Enjoy your day!\n");
    return 0;
}