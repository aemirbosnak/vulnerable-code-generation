//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    if (num <= 3) return true;   // 2 and 3 are prime numbers
    if (num % 2 == 0 || num % 3 == 0) return false; // Check divisibility
    
    // Check for factors from 5 to sqrt(num)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    
    return true;
}

// Function to generate prime numbers in a given range
void generate_primes(int lower, int upper) {
    if (lower < 1) {
        printf("Oh wow! Lower limit must be greater than 0! Setting lower to 1.\n");
        lower = 1;
    }
    if (upper < lower) {
        printf("Surprise! Upper limit can't be less than lower limit. Correcting...\n");
        upper = lower + 10; // Set upper limit to 10 more than lower limit as default
        printf("Now the upper limit is set to: %d\n", upper);
    }

    printf("Fetching prime numbers between %d and %d...\n", lower, upper);
    
    // Array to store prime numbers
    int prime_count = 0;
    int *primes = malloc((upper - lower + 1) * sizeof(int));
    
    for (int num = lower; num <= upper; num++) {
        if (is_prime(num)) {
            primes[prime_count] = num;  // Store found prime
            prime_count++;
            printf("Found a prime number: %d!\n", num); // Excited to find a prime!
        }
    }
    
    // Output the prime numbers found
    if (prime_count > 0) {
        printf("Yay! The prime numbers between %d and %d are:\n", lower, upper);
        for (int i = 0; i < prime_count; i++) {
            printf("%d ", primes[i]);
        }
        printf("\nTotal primes found: %d\n", prime_count);
    } else {
        printf("Oops! No prime numbers found in this range. Better luck next time!\n");
    }
    
    free(primes);
}

int main() {
    int lower, upper;

    printf("Welcome to the Prime Number Generator!\n");
    printf("Please enter the lower bound: ");
    scanf("%d", &lower);
    
    printf("Now, please enter the upper bound: ");
    scanf("%d", &upper);
    
    generate_primes(lower, upper);

    printf("Thank you for using the Prime Number Generator! Till next time!\n");

    return 0;
}