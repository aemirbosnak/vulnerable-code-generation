//GEMINI-pro DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2, result;
    char operator;

    // Get input from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator); // Note the space before %c to ignore whitespace

    // Perform the calculation
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            // Handle division by zero
            if (num2 == 0) {
                printf("Error: Division by zero is undefined.\n");
                return 1; // Exit with an error code
            }
            result = num1 / num2;
            break;

        default:
            printf("Error: Invalid operator.\n");
            return 1; // Exit with an error code
    }

    // Print the result
    printf("The result is: %d\n", result);

    return 0;
}