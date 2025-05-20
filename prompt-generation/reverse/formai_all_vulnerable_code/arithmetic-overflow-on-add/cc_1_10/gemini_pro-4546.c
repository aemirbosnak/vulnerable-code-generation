//GEMINI-pro DATASET v1.0 Category: Prime Number Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }

    if (num <= 3) {
        return true;
    }

    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    int i = 5;

    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }

        i += 6;
    }

    return true;
}

// Function to generate a list of prime numbers within a given range
int *generate_primes(int start, int end) {
    int *primes = malloc(sizeof(int) * (end - start + 1));

    int prime_count = 0;

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            primes[prime_count++] = i;
        }
    }

    return primes;
}

// Function to print a list of prime numbers
void print_primes(int *primes, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", primes[i]);
    }

    printf("\n");
}

int main() {
    // Get the range of numbers to check for primes from the user
    int start, end;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    // Generate a list of prime numbers within the given range
    int *primes = generate_primes(start, end);

    // Print the list of prime numbers
    printf("The prime numbers between %d and %d are:\n", start, end);
    print_primes(primes, end - start + 1);

    // Free the memory allocated for the list of prime numbers
    free(primes);

    return 0;
}