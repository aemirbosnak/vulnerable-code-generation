//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool is_prime(int number);
void generate_primes(int lower, int upper);

int main() {
    int lower, upper;

    // User input for the range
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper);

    // Validate input
    if(lower < 2 || upper < lower) {
        printf("Please enter valid bounds (lower >= 2 and upper >= lower).\n");
        return 1;
    }

    // Generate prime numbers within the specified range
    printf("Prime numbers between %d and %d are:\n", lower, upper);
    generate_primes(lower, upper);

    return 0;
}

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) return false; // Handle special cases
    if (number <= 3) return true;  // 2 and 3 are prime numbers

    if (number % 2 == 0 || number % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false; // Check for factors up to the square root
        }
    }
    return true; // Number is prime
}

// Function to generate and print prime numbers in a range
void generate_primes(int lower, int upper) {
    for (int i = lower; i <= upper; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n"); // New line at the end
}