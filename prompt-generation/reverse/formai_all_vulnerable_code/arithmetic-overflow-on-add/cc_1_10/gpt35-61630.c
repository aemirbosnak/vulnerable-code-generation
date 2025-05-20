//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n)
{
    if (n < 0)
    {
        printf("Invalid input!");
        return;
    }
    
    if (n == 0)
    {
        printf("0");
        return;
    }
    
    if (n == 1)
    {
        printf("0, 1");
        return;
    }
    
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("Fibonacci sequence up to %d:\n", n);
    
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fib[i]);
    }
}

void drawFibonacci(int n)
{
    if (n < 0)
    {
        printf("Invalid input!");
        return;
    }
    
    if (n == 0)
    {
        printf("*");
        return;
    }
    
    if (n == 1)
    {
        printf("**");
        return;
    }
    
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("Fibonacci sequence as asterisks up to %d:\n", n);
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < fib[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printFibonacci(n);
    printf("\n");
    drawFibonacci(n);
    
    return 0;
}