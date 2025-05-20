//FormAI DATASET v1.0 Category: Arithmetic ; Style: relaxed
#include <stdio.h>

// This program takes user input and performs various arithmetic operations
// using if statements to handle potential errors

int main()
{
    float num1, num2, result;
    char operator;
    
    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    
    // Check if second number is 0
    if(num2 == 0)
    {
        printf("Error: division by zero is not allowed\n");
        printf("Please enter a non-zero number: ");
        scanf("%f", &num2);
    }
    
    printf("Please enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    
    // Perform arithmetic operation based on operator
    if(operator == '+')
    {
        result = num1 + num2;
    }
    else if(operator == '-')
    {
        result = num1 - num2;
    }
    else if(operator == '*')
    {
        result = num1 * num2;
    }
    else if(operator == '/')
    {
        result = num1 / num2;
    }
    else
    {
        printf("Error: invalid operator\n");
        return 0;
    }
    
    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    
    return 0;
}