//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>

int fibonacci(int n);
void generate_fibonacci(int limit);
int is_prime(int num);
void print_primes(int limit);

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Generate Fibonacci sequence up to a certain limit
void generate_fibonacci(int limit) {
    printf("Fibonacci sequence up to %d:\n", limit);
    for (int i = 0; fibonacci(i) <= limit; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

// Recursive function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime numbers
    return is_prime_helper(num, num - 1);
}

// Helper function for is_prime
int is_prime_helper(int num, int divisor) {
    if (divisor == 1) return 1; // If we have checked all divisors
    if (num % divisor == 0) return 0; // Found a divisor, so not prime
    return is_prime_helper(num, divisor - 1); // Check next divisor
}

// Print all primes up to a certain limit
void print_primes(int limit) {
    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int fibonacci_limit, prime_limit;

    printf("Enter the upper limit for Fibonacci sequence: ");
    scanf("%d", &fibonacci_limit);
    generate_fibonacci(fibonacci_limit);

    printf("Enter the upper limit for prime numbers: ");
    scanf("%d", &prime_limit);
    print_primes(prime_limit);

    return 0;
}