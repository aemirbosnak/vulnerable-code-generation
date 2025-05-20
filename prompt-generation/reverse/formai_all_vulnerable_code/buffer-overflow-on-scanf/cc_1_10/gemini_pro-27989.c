//GEMINI-pro DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to find the sum of digits of a number
int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to find the sum of prime digits of a number
int sum_of_prime_digits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (is_prime(digit))
            sum += digit;
        n /= 10;
    }
    return sum;
}

// Main function
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is prime
    if (is_prime(n))
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    // Find the sum of digits of the number
    int sum_of_digits_result = sum_of_digits(n);
    printf("The sum of digits of %d is %d.\n", n, sum_of_digits_result);

    // Find the sum of prime digits of the number
    int sum_of_prime_digits_result = sum_of_prime_digits(n);
    printf("The sum of prime digits of %d is %d.\n", n, sum_of_prime_digits_result);

    return 0;
}