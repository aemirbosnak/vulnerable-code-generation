//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include <stdio.h>

// Function to check if a number is prime
int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// Function to generate all primes between a and b, inclusive
void generatePrimes(int a, int b)
{
    printf("All prime numbers between %d and %d:\n", a, b);

    // If a is less than 2, set it to 2 as 2 is the first prime number
    if (a < 2)
        a = 2;

    // Check all numbers between a and b, inclusive
    for (int i = a; i <= b; i++)
    {
        // If the current number is prime, print it
        if (isPrime(i) == 1)
            printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int a, b;

    printf("Enter the lower limit: ");
    scanf("%d", &a);

    printf("Enter the upper limit: ");
    scanf("%d", &b);

    // Call the generatePrimes() function to generate all primes between a and b
    generatePrimes(a, b);

    return 0;
}