//Gemma-7B DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
    int i, n, ctr = 0, primes[MAX] = {0};

    printf("Enter the number of primes you want: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        primes[i] = generatePrime();
    }

    printf("Primes generated: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", primes[i]);
    }

    printf("\n");

    return 0;
}

int generatePrime()
{
    int p, ctr = 0, primes[MAX] = {0};

    while(1)
    {
        p = rand() % MAX;
        for(int i = 0; i < MAX; i++)
        {
            if(primes[i] == p)
            {
                ctr++;
            }
        }

        if(ctr == 0)
        {
            primes[ctr] = p;
            return p;
        }
    }
}