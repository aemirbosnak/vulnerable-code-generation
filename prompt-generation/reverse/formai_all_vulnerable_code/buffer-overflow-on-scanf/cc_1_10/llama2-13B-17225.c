//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_VALUE 1e-10
#define MAX_VALUE 1e10

// Function to generate a random number between two values
int random_between(int min, int max) {
    return (rand() % (max - min)) + min;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// Function to check if two numbers are equal
int equal(int a, int b) {
    return (a == b) || (a == -b);
}

// Function to calculate the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

// Function to calculate the least common multiple of two numbers
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Prompt user for two numbers
    printf("Enter two numbers: ");
    int a, b;
    scanf("%d%d", &a, &b);

    // Check if the numbers are valid
    if (a < 0 || b < 0) {
        printf("Invalid input. Please enter positive numbers.\n");
        return 1;
    }

    // Calculate the greatest common divisor and least common multiple
    int gcd_a = gcd(a, b);
    int lcm_a = lcm(a, b);

    // Calculate the result of the operation
    int result = 0;
    if (equal(a, b)) {
        result = a;
    } else if (is_prime(a) && is_prime(b)) {
        result = a * b;
    } else {
        result = (a * b) / gcd_a;
    }

    // Print the result
    printf("The result of %d and %d is %d\n", a, b, result);

    return 0;
}