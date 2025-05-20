//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double operand1, operand2, result;
    int i = 0;

    // Clear the buffer
    buffer[0] = '\0';

    // Get the operator
    printf("Enter an operator (+, -, *, /, %): ");
    operator = getchar();

    // Get the first operand
    printf("Enter the first operand: ");
    scanf("%lf", &operand1);

    // Get the second operand
    printf("Enter the second operand: ");
    scanf("%lf", &operand2);

    // Perform the calculation
    switch (operator)
    {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0)
            {
                printf("Error: division by zero is not allowed.\n");
            }
            else
            {
                result = operand1 / operand2;
            }
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }

    // Print the result
    printf("The result is: %.2lf\n", result);

    // Store the result in the buffer
    snprintf(buffer, MAX_BUFFER_SIZE, "%lf", result);

    // Display the result on the console
    printf("The result is: %s\n", buffer);

    return 0;
}