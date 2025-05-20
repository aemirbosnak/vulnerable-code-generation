//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int i, fact = 1;
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of the digits of a number
int sum_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to check if a number is prime
int is_prime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate a random number between 1 and 100
    int num = random_range(1, 100);

    // Calculate the factorial of the number
    int fact = factorial(num);

    // Calculate the sum of the digits of the number
    int sum = sum_digits(num);

    // Check if the number is prime
    int prime = is_prime(num);

    // Calculate the GCD of the number and 10
    int gcd_10 = gcd(num, 10);

    // Print the results
    printf("Number: %d\n", num);
    printf("Factorial: %d\n", fact);
    printf("Sum of digits: %d\n", sum);
    printf("Is prime: %s\n", prime ? "Yes" : "No");
    printf("GCD with 10: %d\n", gcd_10);

    return 0;
}