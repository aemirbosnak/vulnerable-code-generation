//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    char operator = '\0';
    double number1 = 0.0;
    double number2 = 0.0;

    // Loop until the user enters an operator or an error occurs
    while (operator == '\0')
    {
        printf("Enter an operator (+, -, *, /, %): ");
        scanf("%s", buffer);

        // Check if the input is valid
        if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
        {
            operator = buffer[0];
        }
        else
        {
            printf("Invalid input.\n");
        }
    }

    // Get the first number
    printf("Enter the first number: ");
    scanf("%lf", &number1);

    // Get the second number
    printf("Enter the second number: ");
    scanf("%lf", &number2);

    // Perform the calculation
    double result = 0.0;
    switch (operator)
    {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                result = number1 / number2;
            }
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", result);

    return 0;
}