//Code Llama-13B DATASET v1.0 Category: Educational ; Style: expert-level
// Expert-level C Programming Example
// This program demonstrates advanced C programming concepts and techniques

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function Prototypes
int is_prime(int);
void print_prime_factors(int);

// Main Function
int main() {
    int number;
    printf("Enter a positive integer: ");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Invalid input. Enter a positive integer.\n");
        return 1;
    }
    printf("Prime factors of %d are: ", number);
    print_prime_factors(number);
    return 0;
}

// Function to check if a number is prime
int is_prime(int n) {
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to print prime factors of a number
void print_prime_factors(int n) {
    int i, factor;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            factor = n / i;
            if (is_prime(factor)) {
                printf("%d*%d ", i, factor);
            }
        }
    }
    printf("\n");
}