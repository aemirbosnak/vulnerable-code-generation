//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: calm
#include <stdio.h>

// This function prints the Fibonacci sequence up to a specified limit
void fibonacci(int n)
{
    int a = 0, b = 1, c = 0;
    
    printf("%d %d ", a, b);

    for(int i=0; i<n-2; i++)
    {
        c = a + b;
        a = b;
        b = c;

        printf("%d ", c);
    }

    printf("\n");
}

// This function prints the Fibonacci sequence as a visual representation up to a specified limit
void fibonacciVisual(int n)
{
    int a = 0, b = 1, c = 0;

    printf("%d \n", a);
    printf("%d %d \n", a, b);

    for(int i=0; i<n-2; i++)
    {
        c = a + b;
        a = b;
        b = c;

        for(int j=0; j<c; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");
}

int main()
{
    int limit;

    printf("Enter a positive integer to generate the nth order Fibonacci sequence: ");
    scanf("%d", &limit);

    printf("\nFibonacci sequence up to %d: \n", limit);
    fibonacci(limit);

    printf("\nFibonacci sequence visualized up to %d: \n", limit);
    fibonacciVisual(limit);

    return 0;
}