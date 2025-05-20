//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

// Recursive function to calculate the sum of all positive integers up to n
int sum(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + sum(n-1);
    }
}

// Recursive function to calculate the factorial of n
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

// Recursive function to print the first n numbers in the Fibonacci sequence
void fibonacci(int n, int a, int b)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        printf("%d ", a);
        fibonacci(n-1, b, a+b);
    }
}

int main()
{
    int choice;
    
    do
    {
        printf("\n1. Calculate the sum of all positive integers up to n\n");
        printf("2. Calculate the factorial of n\n");
        printf("3. Print the first n numbers in the Fibonacci sequence\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                {
                    int n;
                    printf("Enter a positive integer: ");
                    scanf("%d", &n);
                    printf("The sum of all positive integers up to %d is %d\n", n, sum(n));
                    break;
                }
            case 2:
                {
                    int n;
                    printf("Enter a non-negative integer: ");
                    scanf("%d", &n);
                    printf("%d! = %d\n", n, factorial(n));
                    break;
                }
            case 3:
                {
                    int n;
                    printf("Enter a positive integer: ");
                    scanf("%d", &n);
                    printf("The first %d numbers in the Fibonacci sequence are: ", n);
                    fibonacci(n, 0, 1);
                    printf("\n");
                    break;
                }
            case 4:
                {
                    printf("Exiting...\n");
                    break;
                }
            default:
                {
                    printf("Invalid choice. Please enter a number between 1 and 4.\n");
                    break;
                }
        }
    } while (choice != 4);
    
    return 0;
}