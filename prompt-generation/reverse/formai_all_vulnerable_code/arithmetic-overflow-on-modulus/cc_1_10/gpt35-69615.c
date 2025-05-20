//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
int power(int base, int exponent);
int factorial(int n);
int fibonacci(int n);
int gcd(int a, int b);
int lcm(int a, int b);

int main()
{
    int choice, num1, num2, result;
    
    while (1)
    {
        printf("\n*** Scientific Calculator ***\n");
        printf("1. Power\n2. Factorial\n3. Fibonacci\n4. GCD\n5. LCM\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter base and exponent: ");
                scanf("%d %d", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %d\n", result);
                break;
                
            case 2:
                printf("Enter a number: ");
                scanf("%d", &num1);
                result = factorial(num1);
                printf("Result: %d\n", result);
                break;
                
            case 3:
                printf("Enter a number: ");
                scanf("%d", &num1);
                printf("Fibonacci Series: ");
                for (int i = 0; i < num1; i++)
                {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;
                
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = gcd(num1, num2);
                printf("GCD: %d\n", result);
                break;
                
            case 5:
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                result = lcm(num1, num2);
                printf("LCM: %d\n", result);
                break;
            
            case 6:
                exit(0);
                
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function Definitions
int power(int base, int exponent)
{
    // Base Case
    if (exponent == 0)
    {
        return 1;
    }
    // Recursive Case
    else if (exponent > 0)
    {
        return base * power(base, exponent-1);
    }
}

int factorial(int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Recursive Case
    else
    {
        return n * factorial(n-1);
    }
}

int fibonacci(int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return n;
    }
    // Recursive Case
    else
    {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int gcd(int a, int b)
{
    // Base Case
    if (b == 0)
    {
        return a;
    }
    // Recursive Case
    else
    {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b)
{
    // LCM = (a * b) / GCD
    int gcdValue = gcd(a, b);
    return (a * b) / gcdValue;
}