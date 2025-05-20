//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000000

bool isPrime[MAX + 1];

void SieveOfEratosthenes()
{
    int i, j;

    for (i = 2; i <= MAX; i++)
    {
        isPrime[i] = true;
    }

    for (i = 2; i*i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (j = i*i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    int n, count = 0;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &n);

    SieveOfEratosthenes();

    printf("The first %d prime numbers are:\n", n);

    for (int i = 2; count < n; i++)
    {
        if (isPrime[i])
        {
            printf("%d ", i);
            count++;
        }
    }

    return 0;
}