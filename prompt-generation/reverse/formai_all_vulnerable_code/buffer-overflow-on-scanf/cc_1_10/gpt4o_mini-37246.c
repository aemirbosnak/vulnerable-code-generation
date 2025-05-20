//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int is_prime(int n);
void generate_primes(int limit);
int sum_of_primes(int limit);
void print_primes(int limit);

int main() {
    int limit;

    printf("Enter the limit to calculate the sum of prime numbers: ");
    if (scanf("%d", &limit) != 1 || limit < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return 1;
    }

    printf("\nGenerating prime numbers up to %d:\n", limit);
    print_primes(limit);
    
    int sum = sum_of_primes(limit);
    printf("\nThe sum of prime numbers up to %d is: %d\n", limit, sum);
    
    return 0;
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // Found a divisor
    }
    return 1; // n is prime
}

// Function to print all prime numbers up to a limit
void print_primes(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to calculate the sum of all prime numbers up to a limit
int sum_of_primes(int limit) {
    int sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            sum += i;
        }
    }
    return sum;
}

// Improving the program: Combining functionalities
void generate_primes(int limit) {
    printf("\nPrime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}