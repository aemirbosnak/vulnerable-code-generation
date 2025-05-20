//FormAI DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>

// A function to check if a number is prime or not
int isPrime(int n)
{
    // Corner cases
    if(n <= 1)
        return 0;
    if(n <= 3)
        return 1;

    // Check if n is divisible by 2 or 3
    if(n%2 == 0 || n%3 == 0)
        return 0;

    // Check for divisibility of n by every number from 5 to sqrt(n)
    for(int i=5; i*i<=n; i=i+6)
    {
        if(n%i == 0 || n%(i+2) == 0)
            return 0;
    }

    // If n is not divisible by any number from 2 to sqrt(n), then n is a prime number
    return 1;
}

// A function to find the largest prime factor of a given number
int largestPrimeFactor(long long n)
{
    int maxPrime = -1;

    // Divide the number by 2 until it becomes an odd number
    while(n%2 == 0)
    {
        maxPrime = 2;
        n = n/2;
    }

    // Check for divisibility of n by every odd number from 3 to sqrt(n)
    for(int i=3; i*i<=n; i=i+2)
    {
        while(n%i == 0)
        {
            maxPrime = i;
            n = n/i;
        }
    }

    // If n itself is a prime number greater than 2, then it is the largest prime factor
    if(n > 2)
        maxPrime = n;

    return maxPrime;
}

int main()
{
    long long n;

    // Take input from user
    printf("Enter a positive integer: ");
    scanf("%lld", &n);

    // Calculate the largest prime factor of the given number
    int largest = largestPrimeFactor(n);

    // Print the result
    printf("The largest prime factor of %lld is %d.\n", n, largest);

    return 0;
}