//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
#include <stdio.h>

int recursiveFactorial(int number)
{
    if (number == 1) 
    {
        return 1;
    } 
    else 
    {
        return number * recursiveFactorial(number - 1);
    }
}

int recursiveFibonacci(int number)
{
    if (number == 0) 
    {
        return 0;
    } 
    else if (number == 1)
    {
        return 1;
    }
    else 
    {
        return recursiveFibonacci(number - 1) + recursiveFibonacci(number - 2);
    }
}

int recursivePower(int base, int exponent)
{
    if (exponent == 0) 
    {
        return 1;
    } 
    else 
    {
        return base * recursivePower(base, exponent - 1);
    }
}

int main()
{
    int option, number, base, exponent;
    
    printf("Welcome to the Recursive Calculator!\n\n");
    
    do 
    {
        printf("Please select an option:\n");
        printf("1 - Factorial\n");
        printf("2 - Fibonacci\n");
        printf("3 - Power\n");
        printf("0 - Exit\n");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
                printf("Please enter a positive integer:\n");
                scanf("%d", &number);
                printf("%d! = %d\n", number, recursiveFactorial(number));
                break;
            case 2:
                printf("Please enter the position in the Fibonacci sequence:\n");
                scanf("%d", &number);
                printf("The number at position %d in the Fibonacci sequence is %d\n", number, recursiveFibonacci(number));
                break;
            case 3:
                printf("Please enter the base:\n");
                scanf("%d", &base);
                printf("Please enter the exponent:\n");
                scanf("%d", &exponent);
                printf("%d^%d = %d\n", base, exponent, recursivePower(base, exponent));
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        
        printf("\n");
    }
    while(option != 0);

    return 0;
}