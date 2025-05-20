//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: futuristic
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define size 1000000

int primes[size];
int count=0;

void sieve()
{
    int i,j;
    for(i=2;i<=sqrt(size);i++)
    {
        if(primes[i]==0)
        {
            for(j=i*i;j<=size;j+=i)
            {
                primes[j]=1;
            }
        }
    }
}

int main()
{
    int i,j,n;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d",&n);
    srand(time(NULL));

    for(i=2;i<=size;i++)
    {
        primes[i]=0;
    }

    sieve();

    printf("Prime numbers generated:\n");
    for(i=2;i<=size;i++)
    {
        if(primes[i]==0)
        {
            printf("%d ",i);
            count++;
        }
        if(count==n)
        {
            break;
        }
    }
    return 0;
}