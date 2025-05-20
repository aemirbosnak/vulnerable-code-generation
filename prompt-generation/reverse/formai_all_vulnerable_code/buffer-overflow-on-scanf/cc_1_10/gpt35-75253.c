//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void printFibonacci(int n)
{
    int a = 0, b = 1, c = 0;
    printf("%d %d ", a, b);
    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

void drawFibonacci(int n)
{
    int a = 0, b = 1, c = 1;
    printf("   ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", c);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", i + 1);
        for (int j = 0; j < i; j++)
        {
            printf("    ");
        }
        for (int j = i; j < n; j++)
        {
            c = a + b;
            printf("%4d", c);
            a = b;
            b = c;
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("\nFibonacci Sequence:\n");
    printFibonacci(n);
    printf("\n\nFibonacci Sequence Visualizer:\n\n");
    drawFibonacci(n);
    return 0;
}