//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: all-encompassing
#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
    int i, flag = 0;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0 && n > 1)
        return 1;
    else
        return 0;
}

void SieveOfEratosthenes(int n, int primes[])
{
    int i, j;
    for(i=2; i<=n; i++)
        primes[i] = 1;
    for(i=2; i*i<=n; i++)
    {
        if(primes[i] == 1)
        {
            for(j=i*i; j<=n; j+=i)
                primes[j] = 0;
        }
    }
}

int main()
{
    int n, i, count = 0, primes[100000];
    printf("Enter the number of prime numbers to be generated: ");
    scanf("%d", &n);
    for(i=2; count<n; i++)
    {
        if(isPrime(i) == 1)
        {
            printf("%d ", i);
            count++;
        }
    }
    return 0;
}