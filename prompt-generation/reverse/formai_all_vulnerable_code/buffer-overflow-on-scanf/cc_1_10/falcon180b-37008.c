//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: automated
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000
long long int prime[MAX];
int isprime(int n)
{
    int i;
    if(n==2)
        return 1;
    if(n%2==0)
        return 0;
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
void sieveoferatosthenes(int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        prime[i]=1;
    }
    for(i=2;i*i<=n;i++)
    {
        if(prime[i]==1)
        {
            for(j=i*i;j<=n;j+=i)
            {
                prime[j]=0;
            }
        }
    }
}
int main()
{
    int n,i,count=0;
    printf("enter the value of n:\n");
    scanf("%d",&n);
    srand(time(0));
    for(i=2;count<n;i++)
    {
        if(isprime(i)==1)
        {
            prime[i]=1;
            count++;
        }
    }
    printf("the first %d prime numbers are:\n",n);
    for(i=2;i<=n;i++)
    {
        if(prime[i]==1)
        {
            printf("%d\t",i);
        }
    }
    return 0;
}