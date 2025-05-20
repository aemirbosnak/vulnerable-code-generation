//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_primes(int n) {
    // Creating a boolean array and initializing all entries as true.
    // A value in prime[i] will be false if i is Not a prime.
    bool *is_prime = malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = false; // 0 is not a prime number
    is_prime[1] = false; // 1 is not a prime number

    for (int p = 2; p * p <= n; p++) {
        // If is_prime[p] is not changed, then it is a prime
        if (is_prime[p]) {
            // Updating all multiples of p as not prime
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers up to %d:\n", n);
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(is_prime);
}

int main() {
    int limit;

    // Greet user and prompt for input
    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter an upper limit to generate prime numbers: ");
    
    // Read user input
    if (scanf("%d", &limit) != 1 || limit < 2) {
        printf("You have entered an invalid number. Please enter a number greater than or equal to 2.\n");
        return 1; // Exit with an error code
    }

    // Call function to print primes
    print_primes(limit);

    // Bid farewell
    printf("Thank you for using the Prime Number Generator. Goodbye!\n");
    return 0; // Successful completion
}