//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double operand1, operand2, result;

    // Initialize the game state
    operand1 = operand2 = 0;
    operator = '\0';

    // Enter the game loop
    while (1) {
        // Get the user input
        printf("Enter an operator (+, -, *, /, =): ");
        scanf("%s", buffer);

        // Check if the user has entered an operator
        if (buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/') {
            // Extract the operator
            operator = buffer[0];

            // Get the second operand
            printf("Enter the second operand: ");
            scanf("%lf", &operand2);

            // Perform the calculation
            switch (operator) {
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
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator.\n");
                    break;
            }

            // Display the result
            printf("The result is: %.2lf\n", result);

            // Reset the operands and operator
            operand1 = operand2 = 0;
            operator = '\0';
        } else if (buffer[0] == '=') {
            // Check if the operator is valid
            if (operator != '\0') {
                // Perform the calculation
                switch (operator) {
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
                        result = operand1 / operand2;
                        break;
                    default:
                        printf("Invalid operator.\n");
                        break;
                }

                // Display the result
                printf("The result is: %.2lf\n", result);
            } else {
                printf("Invalid input.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}