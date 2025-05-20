//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: artistic
#include <stdio.h>

int isPrime(int num)
{
    if(num <= 1)
    {
        return 0;
    }

    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void printPrimes(int num)
{
    for(int i = 2; i <= num; i++)
    {
        if(isPrime(i))
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    printf("Enter maximum number to search for primes: ");

    int num;
    scanf("%d", &num);

    printf("\n");

    if(num < 2)
    {
        printf("There are no prime numbers below %d.\n", num);
    }
    else
    {
        printf("The prime numbers below %d are:\n", num);
        printPrimes(num);
    }

    return 0;
}