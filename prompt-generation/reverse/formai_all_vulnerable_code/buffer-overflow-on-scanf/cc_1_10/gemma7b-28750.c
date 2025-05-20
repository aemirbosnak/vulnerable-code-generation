//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint16_t calculate_prime(uint16_t n);

int main()
{
    uint16_t num = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    uint16_t result = calculate_prime(num);

    if (result != 0)
    {
        printf("Prime factors of %d: ", num);
        for (uint16_t i = 1; i <= result; i++)
        {
            if (num % i == 0)
            {
                printf("%d ", i);
            }
        }

        printf("\n");
    }
    else
    {
        printf("No prime factors found.\n");
    }

    return 0;
}

uint16_t calculate_prime(uint16_t n)
{
    uint16_t i = 2;
    uint16_t result = 0;

    while (i * i <= n)
    {
        if (n % i == 0)
        {
            result = i;
            n /= i;
        }
        else
        {
            i++;
        }
    }

    return result;
}