//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE] = "";
    char operator;
    double operand1, operand2;

    // Get the operator and operand
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
            operand2 += operand1;
            break;
        case '-':
            operand2 -= operand1;
            break;
        case '*':
            operand2 *= operand1;
            break;
        case '/':
            if (operand1 == 0)
            {
                printf("Cannot divide by zero\n");
            }
            else
            {
                operand2 /= operand1;
            }
            break;
        default:
            printf("Invalid operator\n");
            break;
    }

    // Display the result
    printf("The result is: %.2lf\n", operand2);

    return 0;
}