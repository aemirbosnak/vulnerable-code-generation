//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void sieve_primes(int n)
{
    int i, j, primes[n], isPrime = 1;

    primes[0] = primes[1] = 0;
    primes[2] = 1;

    for (i = 3; i < n; i++)
    {
        for (j = 2; j * i <= n; j++)
        {
            if (primes[j] && primes[j] % i == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
            primes[i] = 1;
    }
}

int main()
{
    int n, i, count = 0, primes[MAX];

    printf("Enter the number of primes to generate: ");
    scanf("%d", &n);

    sieve_primes(n);

    printf("Prime numbers generated: ");
    for (i = 0; i < n; i++)
    {
        if (primes[i])
            printf("%d ", primes[i]);

        count++;
    }

    printf("\nTotal number of primes generated: %d", count);

    return 0;
}