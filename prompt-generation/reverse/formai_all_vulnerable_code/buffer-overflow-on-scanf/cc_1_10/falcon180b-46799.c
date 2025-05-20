//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: recursive
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int n);
void SieveOfEratosthenes(int n);

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Prime numbers up to %d are:\n",n);
    SieveOfEratosthenes(n);
    return 0;
}

bool isPrime(int n)
{
    if(n<=1)
        return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

void SieveOfEratosthenes(int n)
{
    int arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=1;
    }
    for(int p=2;p*p<=n;p++)
    {
        if(arr[p]==1)
        {
            for(int i=p*p;i<=n;i+=p)
            {
                arr[i]=0;
            }
        }
    }
    printf("Prime numbers:\n");
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==1)
        {
            printf("%d ",i);
        }
    }
}