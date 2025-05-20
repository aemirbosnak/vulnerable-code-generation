//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate the sum of all prime numbers up to a given limit
long long sum_of_primes(int limit) {
    if (limit < 2) return 0;

    // Create an array to mark prime numbers
    bool *is_prime = (bool *)malloc((limit + 1) * sizeof(bool));
    if (is_prime == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize all entries in the array as true
    for (int i = 0; i <= limit; i++) {
        is_prime[i] = true;
    }

    // 0 and 1 are not prime numbers
    is_prime[0] = is_prime[1] = false;

    // Implement Sieve of Eratosthenes
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Sum up all prime numbers
    long long sum = 0;
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            sum += i;
        }
    }

    // Free allocated memory
    free(is_prime);
    
    return sum;
}

int main() {
    printf("🎉 Welcome to the Prime Number Sum Calculator! 🎉\n");
    
    int limit;
    printf("Please enter the upper limit for calculating the sum of primes: ");
    scanf("%d", &limit);

    // Calculate the sum of primes
    long long result = sum_of_primes(limit);
    
    // Display the result
    printf("The sum of all prime numbers up to %d is: %lld\n", limit, result);
    
    printf("🌈 Thank you for using our program! Have a great day! 🌈\n");
    return 0;
}