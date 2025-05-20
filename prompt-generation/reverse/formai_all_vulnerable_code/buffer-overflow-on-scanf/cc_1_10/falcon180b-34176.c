//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000
#define ROOT_2 1.41421356

int isprime(int n)
{
    int i, flag = 1;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

void prime_generator()
{
    int i, count = 0, n;
    srand(time(0));
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &n);
    printf("\nPrime numbers:\n");
    for (i = 2; count < n; i++)
    {
        if (isprime(i))
        {
            printf("%d ", i);
            count++;
        }
        if (i == MAX - 1)
        {
            i = 2;
        }
    }
}

int main()
{
    int choice;
    printf("Prime Number Generator\n");
    printf("1. Generate prime numbers\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            prime_generator();
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}