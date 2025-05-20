//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 1000000

// Function to generate prime numbers
void generatePrimes(bool primes[], int limit)
{
    // Initialize all values as prime except 0 and 1
    for (int i = 2; i <= limit; i++)
        primes[i] = true;

    // Sieve of Eratosthenes algorithm
    for (int p = 2; p <= sqrt(limit); p++)
    {
        // If primes[p] is not already changed, then it is a prime number
        if (primes[p] == true)
        {
            // Update all multiples of p as not prime
            for (int i = p * p; i <= limit; i += p)
                primes[i] = false;
        }
    }
}

int main()
{
    bool primes[MAX];
    int limit = 0;

    printf("Enter the maximum number to check for prime numbers: ");
    scanf("%d", &limit);

    // Check if the limit is valid
    if (limit < 2)
    {
        printf("Invalid limit, enter a value greater than or equal to 2\n");
        return 0;
    }

    // Generate prime numbers
    generatePrimes(primes, limit);

    // Print all prime numbers
    printf("Prime numbers between 2 and %d are:\n", limit);
    for (int i = 2; i <= limit; i++)
    {
        if (primes[i] == true)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}