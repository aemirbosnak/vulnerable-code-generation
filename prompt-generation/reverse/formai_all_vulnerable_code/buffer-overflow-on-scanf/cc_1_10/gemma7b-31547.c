//Gemma-7B DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Function to calculate the Fibonacci number of a number
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to find the prime factors of a number
void primeFactors(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Function to find the perfect squares of a number
void perfectSquares(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i * i <= n)
        {
            printf("%d ", i * i);
        }
    }
    printf("\n");
}

int main()
{
    int choice, number;

    printf("Enter your choice:\n");
    printf("1. Calculate factorial\n");
    printf("2. Calculate Fibonacci number\n");
    printf("3. Find prime factors\n");
    printf("4. Find perfect squares\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the number: ");
            scanf("%d", &number);
            printf("Factorial of %d is: %d\n", number, factorial(number));
            break;
        case 2:
            printf("Enter the number: ");
            scanf("%d", &number);
            printf("Fibonacci number of %d is: %d\n", number, fibonacci(number));
            break;
        case 3:
            printf("Enter the number: ");
            scanf("%d", &number);
            primeFactors(number);
            break;
        case 4:
            printf("Enter the number: ");
            scanf("%d", &number);
            perfectSquares(number);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}