//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000

// Function prototypes
void calculate_prime(int n);
int is_prime(int n);

int main()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);

    calculate_prime(n);

    return 0;
}

void calculate_prime(int n)
{
    int i, j, count = 0;
    for (i = 2; i <= n; i++)
    {
        for (j = 2; j <= i; j++)
        {
            if (is_prime(i) && is_prime(j) && i != j)
            {
                count++;
            }
        }
    }

    printf("The number of primes between %d and %d is: %d", 2, n, count);
}

int is_prime(int n)
{
    int i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}