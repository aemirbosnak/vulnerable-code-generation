//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// function to generate the Fibonacci sequence

void generateFibonacciSequence(int n)
{
    int i, t1 = 0, t2 = 1, nextTerm;
    printf("Fibonacci Sequence (%d terms):\n", n);
    for (i = 1; i <= n; i++)
    {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
}

// function to generate the ASCII art for the Fibonacci sequence

void generateFibonacciVisual(int n)
{
    int i, t1 = 0, t2 = 1, nextTerm;
    printf("ASCII Art for Fibonacci Sequence (%d terms):\n", n);
    printf(" o\n");
    printf("/|\\n");
    printf("/ \\\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d  ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("\n");
        printf(" o\n");
        printf("/|\\n");
        printf("/ \\\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of terms to generate in the Fibonacci sequence (max 20): ");
    scanf("%d", &n);
    if (n > 20)
    {
        printf("Error: Maximum number of terms is 20\n");
        exit(0);
    }
    generateFibonacciSequence(n);
    generateFibonacciVisual(n);
    return 0;
}