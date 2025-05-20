//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>
#include <math.h>

#define MAX 1000000

void sieve(int n)
{
    int i, j, k;
    int primes[MAX];
    int count = 0;

    for (i = 2; i <= sqrt(n); i++)
    {
        primes[i] = 1;
    }

    for (i = 2; i <= n; i++)
    {
        if (primes[i] == 1)
        {
            for (j = i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    for (i = 2; i <= n; i++)
    {
        if (primes[i] == 1)
        {
            printf("%d ", i);
            count++;
        }

        if (count == 50)
        {
            break;
        }
    }
}

int main()
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("\nPrime numbers up to %d:\n", n);
    sieve(n);

    return 0;
}