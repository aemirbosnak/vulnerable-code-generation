//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdio.h>

int factorial(int n);
int fibonacci(int n);

int main()
{
    int n, choice, result;

    printf("Enter 1 for factorial or 2 for fibonacci: ");
    scanf("%d", &choice);

    printf("Enter a number: ");
    scanf("%d", &n);

    if (choice == 1)
    {
        result = factorial(n);
        printf("The factorial of %d is %d", n, result);
    }
    else if (choice == 2)
    {
        printf("The fibonacci series of %d is: ", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", fibonacci(i));
        }
    }
    else
    {
        printf("\nInvalid choice entered!");
    }

    return 0;
}

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

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
        return fibonacci(n-1) + fibonacci(n-2);
    }
}