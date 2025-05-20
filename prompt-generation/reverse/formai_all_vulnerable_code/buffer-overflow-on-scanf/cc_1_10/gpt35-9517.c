//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: unmistakable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int num);

int main()
{
    int num, i;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Prime numbers up to %d are: ", num);

    for (i = 2; i <= num; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}

bool isPrime(int num)
{
    int i;

    if (num == 2)
    {
        return true;
    }

    if (num % 2 == 0 || num == 1)
    {
        return false;
    }

    for (i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}