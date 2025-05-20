//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

/* Recursive function to calculate the result */
int calculate(char operator, int num1, int num2)
{
    switch(operator)
    {
        case '+':
            return add(num1, num2);
        case '-':
            return subtract(num1, num2);
        case '*':
            return multiply(num1, num2);
        case '/':
            return divide(num1,num2);
        default:
            printf("Invalid operator\n");
            exit(0);
    }
}

/* Add two numbers */
int add(int num1, int num2)
{
    char operator;
    int result = num1 + num2;

    printf("Current Result: %d\n",result);
    printf("Do you want to perform additional calculation? (y/n): ");
    scanf(" %c",&operator);

    if (operator == 'y' || operator == 'Y')
    {
        int num3;
        printf("Enter a number: ");
        scanf("%d", &num3);
        result = calculate('+', result, num3);
    }
    return result;
}

/* Subtract two numbers */
int subtract(int num1, int num2)
{
    char operator;
    int result = num1 - num2;

    printf("Current Result: %d\n",result);
    printf("Do you want to perform additional calculation? (y/n): ");
    scanf(" %c",&operator);

    if (operator == 'y' || operator == 'Y')
    {
        int num3;
        printf("Enter a number: ");
        scanf("%d", &num3);
        result = calculate('-', result, num3);
    }
    return result;
}

/* Multiply two numbers */
int multiply(int num1, int num2)
{
    char operator;
    int result = num1 * num2;

    printf("Current Result: %d\n",result);
    printf("Do you want to perform additional calculation? (y/n): ");
    scanf(" %c",&operator);

    if (operator == 'y' || operator == 'Y')
    {
        int num3;
        printf("Enter a number: ");
        scanf("%d", &num3);
        result = calculate('*', result, num3);
    }
    return result;
}

/* Divide two numbers */
int divide(int num1, int num2)
{
    char operator;
    int result = num1 / num2;

    printf("Current Result: %d\n",result);
    printf("Do you want to perform additional calculation? (y/n): ");
    scanf(" %c",&operator);

    if (operator == 'y' || operator == 'Y')
    {
        int num3;
        printf("Enter a number: ");
        scanf("%d", &num3);
        result = calculate('/', result, num3);
    }
    return result;
}

int main()
{
    char operator;
    int num1, num2, result;

    /* Display welcome message */
    printf("Welcome to Recursive Calculator\n");

    /* Get the user inputs */
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    /* Call the recursive function to calculate the result */
    result = calculate(operator, num1, num2);

    /* Display the result */
    printf("Result: %d\n", result);

    return 0;
}