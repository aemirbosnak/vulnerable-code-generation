//FormAI DATASET v1.0 Category: Educational ; Style: recursive
#include <stdio.h>

// Function to calculate Fibonacci number

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to print the Fibonacci series upto n numbers

void print_fibonacci_series(int n)
{
    int i;

    printf("Fibonacci Series:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
}

// Function to calculate factorial of a number

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Function to print the factorial of a number

void print_factorial(int n)
{
    int fact;

    fact = factorial(n);

    printf("Factorial of %d: %d\n", n, fact);
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    print_fibonacci_series(n);

    print_factorial(n);

    return 0;
}