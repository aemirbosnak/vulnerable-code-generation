//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: accurate
#include <stdio.h>

// function to generate fibonacci sequence up to n terms
void fibonacci(int n)
{
    int a = 0, b = 1, c, i;
    
    printf("%d %d ", a, b); // prints first two terms of the series
    for(i = 2; i < n; i++)
    {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

// function to draw the fibonacci sequence using asterisks up to n terms
void fibonacci_visual(int n)
{
    int a = 0, b = 1, c, i, j;
    
    printf("%d %d\n", a, b); // prints first two terms of the series
    
    for(i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        
        for(j = 0; j < c; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    
    printf("Enter the number of terms in fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("\nFibonacci Sequence up to %d terms:\n", n);
    fibonacci(n);
    
    printf("\nFibonacci Sequence Visualizer up to %d terms:\n", n);
    fibonacci_visual(n);
    
    return 0;
}