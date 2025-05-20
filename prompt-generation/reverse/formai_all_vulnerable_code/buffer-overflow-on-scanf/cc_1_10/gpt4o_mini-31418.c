//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a given limit
void generate_primes(int limit) {
    printf("Prime Numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to calculate the nth prime number
int nth_prime(int n) {
    if (n < 1) {
        return -1; // Error: n must be positive
    }
    
    int count = 0;
    int candidate = 1;

    while (count < n) {
        candidate++;
        if (is_prime(candidate)) {
            count++;
        }
    }
    return candidate;
}

// Function to find all prime numbers in a given range
void find_primes_in_range(int start, int end) {
    if (start > end) {
        printf("Invalid range! Start must be less than or equal to End.\n");
        return;
    }

    printf("Prime Numbers in the range [%d, %d]:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Main function to demonstrate the prime number generator functionalities
int main() {
    int limit, nth, start, end;

    // Generate primes up to a limit given by the user
    printf("Enter a limit to generate prime numbers: ");
    scanf("%d", &limit);
    generate_primes(limit);

    // Get the nth prime number
    printf("Enter a positive integer n to find the nth prime number: ");
    scanf("%d", &nth);
    int prime = nth_prime(nth);
    if (prime != -1) {
        printf("The %dth prime number is: %d\n", nth, prime);
    } else {
        printf("Error: n must be positive!\n");
    }

    // Find primes in a specified range
    printf("Enter a range [start end] to find prime numbers: ");
    scanf("%d %d", &start, &end);
    find_primes_in_range(start, end);

    return 0;
}