//Falcon-180B DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int is_prime(int n);

int main()
{
    int num;
    srand(time(NULL));
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    int count = 0;
    int max_prime = 0;
    int prime = 2;

    while (count < num)
    {
        if (is_prime(prime))
        {
            printf("%d ", prime);
            if (prime > max_prime)
            {
                max_prime = prime;
            }
            count++;
        }
        prime++;
    }

    return 0;
}

int is_prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}