//FormAI DATASET v1.0 Category: Game ; Style: recursive
#include <stdio.h>

int factorial(int n)
{
    if(n == 0)
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
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void print_triangle(int n)
{
    if(n == 0)
    {
        return;
    }
    else
    {
        print_triangle(n-1);
        for(int i = 0; i < n; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int option;
    printf("1. Factorial\n2. Fibonacci\n3. Print Triangle\n");
    scanf("%d", &option);
    switch(option)
    {
        case 1:
        {
            int num;
            printf("Enter a number: ");
            scanf("%d", &num);
            int fact = factorial(num);
            printf("Factorial of %d is %d\n", num, fact);
            break;
        }
        case 2:
        {
            int num;
            printf("Enter a number: ");
            scanf("%d", &num);
            int fib = fibonacci(num);
            printf("Fibonacci of %d is %d\n", num, fib);
            break;
        }
        case 3:
        {
            int num;
            printf("Enter number of stars: ");
            scanf("%d", &num);
            print_triangle(num);
            break;
        }
        default:
        {
            printf("Invalid option selected\n");
            break;
        }
    }
    return 0;
}