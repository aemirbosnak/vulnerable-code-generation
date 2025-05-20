//FormAI DATASET v1.0 Category: Educational ; Style: Dennis Ritchie
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int num)
{
    int fact = 1;
    for(int i=1; i<=num; i++)
    {
        fact *= i;
    }
    return fact;
}

// Function to calculate the sum of first n natural numbers
int sum_natural_numbers(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum += i;
    }
    return sum;
}

// Function to calculate the Fibonacci sum of a number
int fibonacci_sum(int num)
{
    int a = 0, b = 1, c, sum = 0;
    for(int i=1; i<=num; i++)
    {
        sum += b;
        c = a + b;
        a = b;
        b = c;
    }
    return sum;
}

int main()
{
    int option, num, result;
    
    // Menu-driven program to perform different operations
    do
    {
        printf("\nWelcome to the Arithmetic Operations program!\n");
        printf("1. Factorial of a number\n");
        printf("2. Sum of first n natural numbers\n");
        printf("3. Fibonacci sum of a number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Enter the number: ");
                scanf("%d", &num);
                result = factorial(num);
                printf("The factorial of %d is %d\n", num, result);
                break;
            case 2:
                printf("Enter the value of n: ");
                scanf("%d", &num);
                result = sum_natural_numbers(num);
                printf("The sum of first %d natural numbers is %d\n", num, result);
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d", &num);
                result = fibonacci_sum(num);
                printf("The Fibonacci sum of %d is %d\n", num, result);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
                break;
        }
        
    } while(option != 4);

    return 0;
}