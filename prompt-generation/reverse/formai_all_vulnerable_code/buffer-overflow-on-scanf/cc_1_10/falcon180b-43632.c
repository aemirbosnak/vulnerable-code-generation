//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to check if a number is prime
int is_prime(int n) {
    // 1 is not a prime number
    if (n == 1) {
        return 0;
    }
    // 2 is a prime number
    if (n == 2) {
        return 1;
    }
    // Check if the number is even
    if (n % 2 == 0) {
        return 0;
    }
    // Check odd numbers up to the square root of n
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    // If no factors were found, the number is prime
    return 1;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of primes to generate from the user
    int num_primes;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num_primes);

    // Generate the specified number of prime numbers
    int primes[num_primes];
    int num_generated = 0;
    while (num_generated < num_primes) {
        // Generate a random number between 2 and 100
        int n = rand() % 99 + 2;
        // Check if the number is prime
        if (is_prime(n)) {
            // Add the prime number to the array
            primes[num_generated] = n;
            // Increment the number of primes generated
            num_generated++;
        }
    }

    // Print the generated prime numbers
    printf("The generated prime numbers are:\n");
    for (int i = 0; i < num_generated; i++) {
        printf("%d ", primes[i]);
    }
    printf("\n");

    return 0;
}