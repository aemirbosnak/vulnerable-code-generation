//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to generate prime numbers up to a limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to check if a number is perfect
bool is_perfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

// Function to generate perfect numbers up to a limit
void generate_perfect_numbers(int limit) {
    printf("Perfect numbers up to %d:\n", limit);
    for (int i = 1; i <= limit; i++) {
        if (is_perfect(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to calculate Fibonacci numbers up to a limit
void generate_fibonacci(int limit) {
    int a = 0, b = 1;
    printf("Fibonacci sequence up to %d:\n", limit);
    while (a <= limit) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Main function to execute the program
int main() {
    int limit;

    // Get user input for the limit
    printf("Enter a limit for generating prime and perfect numbers: ");
    scanf("%d", &limit);

    // Validate input
    if (limit <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }
    
    // Generate prime numbers
    generate_primes(limit);
    
    // Generate perfect numbers
    generate_perfect_numbers(limit);
    
    // Generate Fibonacci numbers
    generate_fibonacci(limit);
    
    // Extra Visualization: Prime Number Density Graphing (not graphical, text output)
    printf("\nPrime Number Density:\n");
    for (int i = 1; i <= limit; i++) {
        if (is_prime(i)) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");

    printf("Thank you for using the Math Program!\n");
    return 0;
}