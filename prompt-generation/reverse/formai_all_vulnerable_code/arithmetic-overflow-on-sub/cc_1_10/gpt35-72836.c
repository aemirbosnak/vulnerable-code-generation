//FormAI DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>

// Declare global variables
int num1, num2, result;
char operator;

// Declare function prototypes
void addition();
void subtraction();
void multiplication();
void division();

int main()
{
    // Prompt user for input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Prompt user for operator
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Decide which operation to perform based on user input
    switch(operator)
    {
        case '+':
            addition();
            break;
        case '-':
            subtraction();
            break;
        case '*':
            multiplication();
            break;
        case '/':
            division();
            break;
        default:
            printf("Invalid operator!");
    }

    return 0;
}

void addition()
{
    result = num1 + num2;
    printf("%d + %d = %d", num1, num2, result);
}

void subtraction()
{
    result = num1 - num2;
    printf("%d - %d = %d", num1, num2, result);
}

void multiplication()
{
    result = num1 * num2;
    printf("%d * %d = %d", num1, num2, result);
}

void division()
{
    if(num2 == 0)
    {
        printf("Cannot divide by zero!");
    }
    else
    {
        result = num1 / num2;
        printf("%d / %d = %d", num1, num2, result);
    }
}