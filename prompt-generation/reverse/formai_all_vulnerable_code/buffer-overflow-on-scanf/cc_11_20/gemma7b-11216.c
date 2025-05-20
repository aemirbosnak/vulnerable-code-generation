//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    char operator = '\0';
    double number1 = 0.0;
    double number2 = 0.0;
    double result = 0.0;

    printf("Welcome to the Scientific Calculator!\n");

    // Loop until the user enters an operator or a valid number
    while (operator == '\0' || (number1 == 0.0 && number2 == 0.0))
    {
        printf("Enter an operator (+, -, *, /, %): ");
        scanf("%s", buffer);

        // Check if the input is an operator
        if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/')
        {
            operator = buffer[0];
        }
        // Check if the input is a valid number
        else
        {
            number1 = atof(buffer);
        }
    }

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%lf", &number2);

    // Calculate the result based on the operator
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
                printf("Error: division by zero is not allowed.\n");
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