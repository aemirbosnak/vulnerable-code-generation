//Gemma-7B DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>

int factorial(int n);
int decimal_to_binary(int num);
int fibonacci(int n);

int main()
{
    int choice, num;

    printf("Enter your choice:\n");
    printf("1. Calculate factorial\n");
    printf("2. Convert decimal to binary\n");
    printf("3. Calculate Fibonacci number\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("The factorial of %d is %d\n", num, factorial(num));
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &num);
            printf("The binary equivalent of %d is %d\n", num, decimal_to_binary(num));
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("The Fibonacci number of %d is %d\n", num, fibonacci(num));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

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

int decimal_to_binary(int num)
{
    int binary = 0;
    int i = 0;

    while (num)
    {
        int digit = num % 2;
        num /= 2;
        binary += digit * pow(2, i);
        i++;
    }

    return binary;
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
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}