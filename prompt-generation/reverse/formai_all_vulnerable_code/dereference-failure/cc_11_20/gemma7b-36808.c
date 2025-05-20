//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

int main() {

    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, operand1, operand2, operator;

    printf("**Welcome to the Post-Apocalyptic Calculator!**\n");
    printf("Please enter your expression: ");

    // Get the user's expression
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Parse the expression
    i = 0;
    while (buffer[i] != '\0') {
        // Check if the character is an operator
        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/') {
            operator = buffer[i];
            // Get the first operand
            operand1 = atoi(&buffer[i - 1]);
            // Get the second operand
            operand2 = atoi(&buffer[i + 1]);

            // Perform the calculation
            switch (operator) {
                case '+':
                    printf("%d + %d = %d\n", operand1, operand2, operand1 + operand2);
                    break;
                case '-':
                    printf("%d - %d = %d\n", operand1, operand2, operand1 - operand2);
                    break;
                case '*':
                    printf("%d * %d = %d\n", operand1, operand2, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: division by zero is not allowed\n");
                    } else {
                        printf("%d / %d = %d\n", operand1, operand2, operand1 / operand2);
                    }
                    break;
            }

            i++;
        } else {
            i++;
        }
    }

    return 0;
}