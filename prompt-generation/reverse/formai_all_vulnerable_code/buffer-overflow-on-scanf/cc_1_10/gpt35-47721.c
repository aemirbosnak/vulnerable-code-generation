//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: minimalist
#include <stdio.h>

int is_prime(int n);
void prime_generator(int lower_limit, int upper_limit);

int main()
{
    int lower_limit, upper_limit;

    printf("Enter lower limit: ");
    scanf("%d", &lower_limit);
    printf("Enter upper limit: ");
    scanf("%d", &upper_limit);

    printf("Prime numbers between %d and %d are:\n", lower_limit, upper_limit);
    prime_generator(lower_limit, upper_limit);

    return 0;
}

int is_prime(int n)
{
    if (n <= 1)
    {
        return 0;
    }

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

void prime_generator(int lower_limit, int upper_limit)
{
    int i;
    for (i = lower_limit; i <= upper_limit; i++)
    {
        if (is_prime(i))
        {
            printf("%d\n", i);
        }
    }
}