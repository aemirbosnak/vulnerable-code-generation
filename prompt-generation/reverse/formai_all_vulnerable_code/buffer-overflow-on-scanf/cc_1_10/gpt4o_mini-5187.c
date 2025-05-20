//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: genius
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

// Function to find and print prime factors of a number
void prime_factors(int n) {
    printf("Prime factors of %d are: ", n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0 && is_prime(i)) {
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}

// Function to generate Fibonacci sequence up to n
void fibonacci_sequence(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci sequence up to %d: ", n);
    while (a <= n) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

// Function to check if a number is perfect
bool is_perfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

// Main function
int main() {
    int number;
    
    // User input
    printf("Enter a positive integer: ");
    scanf("%d", &number);

    // Error handling for negative input
    if (number < 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Show the number that's been entered
    printf("You entered: %d\n\n", number);
    
    // Calculate and display prime factors
    prime_factors(number);

    // Generate and display Fibonacci sequence
    fibonacci_sequence(number);

    // Check if the number is a perfect number
    if (is_perfect(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    // Displaying whether the number is prime or not
    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}