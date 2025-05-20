//FormAI DATASET v1.0 Category: Browser Plugin ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a given number
int factorial(int n)
{
    if (n == 1 || n == 0) // Base case
    {
        return 1;
    }
    else // Recursive case
    {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of n natural numbers
int sum(int n)
{
    if (n == 1) // Base case
    {
        return 1;
    }
    else // Recursive case
    {
        return n + sum(n - 1);
    }
}

// Function to print fibonacci series upto n terms
void fibonacci(int n, int a, int b)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        printf("%d ", a + b);
        fibonacci(n - 1, b, a + b);
    }
}

int main()
{
    int n;

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));

    printf("Enter a number to calculate the sum of n natural numbers: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers is %d\n", n, sum(n));

    printf("Enter a number to generate fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci series upto %d terms is: ", n);
    printf("0 1 ");
    fibonacci(n - 2, 0, 1);

    return 0;
}