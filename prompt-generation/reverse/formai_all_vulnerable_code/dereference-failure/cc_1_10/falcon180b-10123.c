//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void sieve(int n, int *primes)
{
    int i, j;
    for (i = 2; i <= n; i++)
    {
        primes[i] = TRUE;
    }
    for (i = 2; i * i <= n; i++)
    {
        if (primes[i])
        {
            for (j = i * i; j <= n; j += i)
            {
                primes[j] = FALSE;
            }
        }
    }
}

int main()
{
    int n, i, count = 0;
    int *primes;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    primes = (int*)malloc(n * sizeof(int));

    sieve(n, primes);

    printf("Prime numbers between 2 and %d:\n", n);

    for (i = 2; i <= n; i++)
    {
        if (primes[i])
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal number of prime numbers: %d", count);

    free(primes);

    return 0;
}