//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Get the input number
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    // Check if the number is even or odd
    if (num & 1)
    {
        printf("%d is odd.\n", num);
    }
    else
    {
        printf("%d is even.\n", num);
    }

    // Check if the number is divisible by 4
    if (!(num & 3))
    {
        printf("%d is divisible by 4.\n", num);
    }
    else
    {
        printf("%d is not divisible by 4.\n", num);
    }

    // Check if the number is a power of 2
    int i;
    for (i = 0; i < 32; i++)
    {
        if (num & (1 << i))
        {
            break;
        }
    }
    if (i == 32)
    {
        printf("%d is a power of 2.\n", num);
    }
    else
    {
        printf("%d is not a power of 2.\n", num);
    }

    // Check if the number is a palindrome
    int reverse = 0;
    int temp = num;
    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    if (num == reverse)
    {
        printf("%d is a palindrome.\n", num);
    }
    else
    {
        printf("%d is not a palindrome.\n", num);
    }

    // Check if the number is a prime number
    int is_prime = 1;
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    if (is_prime)
    {
        printf("%d is a prime number.\n", num);
    }
    else
    {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}