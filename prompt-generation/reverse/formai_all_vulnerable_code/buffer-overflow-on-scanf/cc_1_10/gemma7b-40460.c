//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    float num1, num2;
    int i = 0;

    // Initialize the buffer and operator
    buffer[0] = '\0';
    operator = '\0';

    // Enter the calculator mode
    printf("Enter operator (+, -, *, /, %): ");

    // Get the operator
    operator = getchar();

    // Clear the buffer
    buffer[0] = '\0';

    // Get the first number
    printf("Enter first number: ");

    // Get the first number
    scanf("%f", &num1);

    // Get the second number
    printf("Enter second number: ");

    // Get the second number
    scanf("%f", &num2);

    // Perform the calculation
    switch (operator)
    {
        case '+':
            num1 += num2;
            break;
        case '-':
            num1 -= num2;
            break;
        case '*':
            num1 *= num2;
            break;
        case '/':
            if (num2 == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                num1 /= num2;
            }
            break;
        default:
            printf("Invalid operator\n");
    }

    // Print the result
    printf("The result is: %.2f\n", num1);

    return 0;
}