//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

/* Function to check if a number is prime */
bool isPrime(int n)
{
    /* If the number is less than 2, it is not prime */
    if (n < 2)
        return false;

    /* Loop to check if a number is prime */
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    /* If the number is not divisible by any number till its square root, it is prime */
    return true;
}

/* Function to generate prime numbers */
void generatePrimes(int n)
{
    int count = 0;

    /* Loop to generate prime numbers from 2 to n */
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
            count++;
        }
    }

    /* Print the count of prime numbers generated */
    printf("\nTotal prime numbers generated: %d\n", count);
}

/* Main function to test the prime number generator */
int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    /* Generate prime numbers */
    printf("Prime numbers from 2 to %d are: ", n);
    generatePrimes(n);

    return 0;
}