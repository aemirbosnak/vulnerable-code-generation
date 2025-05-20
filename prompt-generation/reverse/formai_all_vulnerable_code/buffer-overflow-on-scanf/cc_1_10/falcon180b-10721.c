//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 1000
#define MAX_PRIMES 100

int isPrime(int number);
void generatePrimes(int numbers[], int primes[], int count);

int main()
{
    int numbers[MAX_NUMBERS], primes[MAX_PRIMES];
    int count, i;

    printf("Enter the number of integers to generate: ");
    scanf("%d", &count);

    printf("Enter %d integers:\n", count);
    for (i = 0; i < count; i++)
    {
        scanf("%d", &numbers[i]);
    }

    generatePrimes(numbers, primes, count);

    printf("Prime numbers:\n");
    for (i = 0; i < MAX_PRIMES; i++)
    {
        if (primes[i]!= 0)
        {
            printf("%d\n", primes[i]);
        }
    }

    return 0;
}

int isPrime(int number)
{
    int i;

    if (number <= 1)
    {
        return 0;
    }

    for (i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void generatePrimes(int numbers[], int primes[], int count)
{
    int i, j, k;

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < MAX_PRIMES; j++)
        {
            if (primes[j] == 0)
            {
                primes[j] = numbers[i];
                break;
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        for (j = 0; j < MAX_PRIMES; j++)
        {
            if (primes[j] == numbers[i])
            {
                k = j + 1;
                while (k < MAX_PRIMES)
                {
                    if (isPrime(primes[k]))
                    {
                        break;
                    }
                    k++;
                }

                if (k < MAX_PRIMES)
                {
                    primes[k] = 0;
                }
            }
        }
    }
}