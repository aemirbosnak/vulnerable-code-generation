//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to check if a given number is a prime number
int is_prime(int num)
{
    if (num < 2)
        return 0;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

// Function to calculate the factorial of a given number
int factorial(int num)
{
    int result = 1;

    for (int i = 1; i <= num; i++)
    {
        result *= i;
    }

    return result;
}

int main()
{
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    if (is_prime(num))
    {
        printf("%d is a prime number.\n", num);
    }
    else
    {
        printf("%d is not a prime number.\n", num);
    }

    printf("%d! = %d\n", num, factorial(num));

    return 0;
}