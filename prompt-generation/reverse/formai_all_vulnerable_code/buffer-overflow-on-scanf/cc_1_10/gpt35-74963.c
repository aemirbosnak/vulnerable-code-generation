//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: interoperable
#include <stdio.h>

// Recursive function to generate Fibonacci sequence
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print Fibonacci sequence
void printFibonacci(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
}

// Function to display Fibonacci sequence visually
void displayFibonacci(int n)
{
    int i, j, k, a, b, c;
    a = 0;
    b = 1;

    printf("%d %d ", a, b);

    for (i = 2; i < n; i++)
    {
        c = a + b;
        printf("%d ", c);

        // Display the number visually
        for (j = 1; j <= c; j++)
        {
            for (k = 1; k <= j; k++)
            {
                printf("* ");
            }
            printf("\n");
        }
        a = b;
        b = c;
    }
}

// Driver code
int main()
{
    int choice, n;

    // Display the menu
    printf("Menu:\n");
    printf("1. Print Fibonacci sequence\n");
    printf("2. Display Fibonacci sequence visually\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Get input for number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    switch(choice)
    {
        case 1:
            printFibonacci(n);
            break;
        case 2:
            displayFibonacci(n);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}