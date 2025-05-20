//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int n);
int main()
{
    int num;
    int count = 0;
    int max_num = 0;
    int min_num = 0;
    int i;

    srand(time(NULL));

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    printf("Enter the minimum number: ");
    scanf("%d", &min_num);

    printf("Enter the maximum number: ");
    scanf("%d", &max_num);

    for(i = min_num; i <= max_num; i++)
    {
        if(isPrime(i))
        {
            printf("%d ", i);
            count++;
        }
        if(count == num)
            break;
    }

    return 0;
}

int isPrime(int n)
{
    int i;

    for(i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
            return 0;
    }

    return 1;
}