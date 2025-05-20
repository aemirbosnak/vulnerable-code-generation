//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: imaginative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUM 1000000

int main()
{
    int i, j, count = 0;
    int primes[MAX_NUM];
    int sieve_size = (int)sqrt(MAX_NUM);
    int* sieve = (int*)malloc(sieve_size * sizeof(int));

    printf("Prime Number Generator\n");
    printf("======================\n");

    // Initialize sieve
    for(i=2; i<=sieve_size; i++)
    {
        sieve[i-2] = 1;
    }

    // Sieve of Eratosthenes
    for(i=2; i<=sieve_size; i++)
    {
        if(sieve[i-2] == 1)
        {
            for(j=i*i; j<=sieve_size; j+=i)
            {
                sieve[j-2] = 0;
            }
        }
    }

    // Store primes in array
    for(i=2; i<=sieve_size; i++)
    {
        if(sieve[i-2] == 1)
        {
            primes[count++] = i;
        }
    }

    // Print primes
    printf("\nPrime numbers:\n");
    for(i=0; i<count; i++)
    {
        printf("%d ", primes[i]);
    }

    free(sieve);
    return 0;
}