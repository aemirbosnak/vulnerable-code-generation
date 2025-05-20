//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_primes_in_range(int start, int end);
bool is_prime(int number);
void get_input(int *start, int *end);

int main() {
    int start, end;

    printf("Welcome to the Prime Number Generator!\n");

    // Get user input
    get_input(&start, &end);

    // Ensure the start is less than end
    if (start > end) {
        printf("Invalid range! Start must be less than or equal to end.\n");
        return 1; // Exit the program with an error code
    }

    // Print the prime numbers in the given range
    printf("\nGenerating prime numbers between %d and %d:\n", start, end);
    print_primes_in_range(start, end);

    return 0;
}

// Function to get input from the user
void get_input(int *start, int *end) {
    printf("Please enter the starting number: ");
    while (scanf("%d", start) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while(getchar() != '\n'); // clear input buffer
    }
    printf("Please enter the ending number: ");
    while (scanf("%d", end) != 1) {
        printf("Invalid input. Please enter an integer: ");
        while(getchar() != '\n'); // clear input buffer
    }
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1)
        return false; // 0 and 1 are not primes
    if (number <= 3)
        return true; // 2 and 3 are primes

    // Exclude multiples of 2 and 3
    if (number % 2 == 0 || number % 3 == 0)
        return false;

    // Check for factors from 5 to sqrt(number)
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to print primes in a given range
void print_primes_in_range(int start, int end) {
    bool found_any = false;
    for (int num = start; num <= end; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
            found_any = true;
        }
    }
    if (!found_any) {
        printf("No prime numbers found in the range [%d, %d].\n", start, end);
    } else {
        printf("\nFinished generating primes in the range [%d, %d].\n", start, end);
    }
}