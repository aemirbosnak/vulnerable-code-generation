//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to generate and print prime numbers up to a limit
void generate_primes(int limit) {
    printf("Prime numbers up to %d are:\n", limit);
    for (int num = 2; num <= limit; num++) {
        if (is_prime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n");
}

// Function to get user input
int get_input() {
    int num;
    printf("Enter an upper limit for prime number generation: ");
    while (1) {
        scanf("%d", &num);
        if (num >= 0) {
            break;
        } else {
            printf("Please enter a non-negative integer: ");
        }
    }
    return num;
}

// Main function
int main() {
    int limit = get_input();
    
    if (limit < 2) {
        printf("There are no prime numbers up to %d.\n", limit);
    } else {
        generate_primes(limit);
    }
    
    return 0;
}