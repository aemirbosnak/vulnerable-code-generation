//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000000

int isPrime(int n);
void sieveOfEratosthenes(int n);

int main()
{
    int n;
    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d",&n);
    printf("The first %d prime numbers are:\n",n);
    sieveOfEratosthenes(MAX);
    return 0;
}

int isPrime(int n)
{
    if(n<=1)
        return 0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

void sieveOfEratosthenes(int n)
{
    int primes[MAX+1];
    for(int i=0;i<=n;i++)
        primes[i]=1;
    primes[0]=primes[1]=0;
    for(int p=2;p*p<=n;p++)
    {
        if(primes[p])
        {
            for(int i=p*p;i<=n;i+=p)
                primes[i]=0;
        }
    }
    for(int p=2;p<=n;p++)
    {
        if(primes[p])
            printf("%d ",p);
    }
}