//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>

// Function to print Fibonacci sequence up to n terms
void printFibonacciSequence(int n)
{
    int i, term1 = 0, term2 = 1, nextTerm;
  
    // Printing first two terms
    printf("Fibonacci Sequence: %d, %d, ", term1, term2);
  
    // Iteratively calculating next terms and printing them
    for (i = 3; i <= n; i++)
    {
        nextTerm = term1 + term2;
        printf("%d, ", nextTerm);
        term1 = term2;
        term2 = nextTerm;
    }
}

// Function to print Fibonacci sequence using recursion
int fibonacci(int n)
{
    // Base case
    if (n <= 1)
        return n;

    // Recursive call
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to visualize Fibonacci sequence using asterisks
void visualizeFibonacci(int n)
{
    int i, j, term1 = 0, term2 = 1, nextTerm;
  
    // Printing first two terms
    printf("\nFibonacci Sequence:\n%d\n%d\n", term1, term2);
  
    // Iteratively calculating next terms and visualizing them using asterisks
    for (i = 3; i <= n; i++)
    {
        nextTerm = term1 + term2;

        // Printing dots (.) for previous terms
        for (j = 1; j <= nextTerm - term2; j++)
            printf(".");

        // Printing asterisks (*) for new term
        for (j = 1; j <= term2; j++)
            printf("*");
        
        printf("\n");
        
        term1 = term2;
        term2 = nextTerm;
    }
}

int main()
{
    int n;

    // Reading number of terms from user
    printf("Enter number of terms to print: ");
    scanf("%d", &n);

    // Printing Fibonacci sequence
    printFibonacciSequence(n);

    // Visualizing Fibonacci sequence
    visualizeFibonacci(n);

    return 0;
}