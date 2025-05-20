//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>

// Function declarations
int factorial(int n);
int is_prime(int n);
void display_results(int number, int fact, int prime_check);

int main() {
    int number;
    
    // Prompt the user for a number
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    
    // Validate input
    if (number < 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }
    
    // Calculate factorial of the number
    int fact = factorial(number);
    
    // Check if the number is prime
    int prime_check = is_prime(number);
    
    // Display results
    display_results(number, fact, prime_check);
    
    return 0;
}

// Function to calculate factorial of a number recursively
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to check if a number is prime recursively
int is_prime(int n) {
    return is_prime_helper(n, n / 2);
}

// Helper function to assist in prime checking
int is_prime_helper(int n, int divisor) {
    if (n <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    if (divisor == 1) {
        return 1; // Found no divisors, n is prime
    }
    if (n % divisor == 0) {
        return 0; // Found a divisor, n is not prime
    }
    return is_prime_helper(n, divisor - 1);
}

// Function to display the results of calculations
void display_results(int number, int fact, int prime_check) {
    printf("Results for the number: %d\n", number);
    printf("Factorial: %d\n", fact);
    
    if (prime_check) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }
}