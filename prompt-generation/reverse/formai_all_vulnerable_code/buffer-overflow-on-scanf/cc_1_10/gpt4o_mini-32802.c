//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_prime(int number) {
    // Edge cases
    if (number <= 1) return false;
    if (number <= 3) return true;

    // Check divisibility from 2 to the square root of number
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void generate_primes(int limit) {
    // Check for valid limit
    if (limit < 2) {
        printf("Please enter a limit greater than 1.\n");
        return;
    }

    printf("Generating prime numbers up to %d:\n", limit);
    printf("2"); // 2 is the first prime number

    for (int num = 3; num <= limit; num += 2) {
        if (is_prime(num)) {
            printf(", %d", num);
        }
    }
    printf("\nGeneration complete.\n");
}

int main() {
    int limit;

    printf("Welcome! This program will generate all prime numbers up to a specified limit.\n");
    printf("Please enter a positive integer as your limit: ");
    
    // Retrieve input from user
    if (scanf("%d", &limit) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    generate_primes(limit);
    return 0;
}