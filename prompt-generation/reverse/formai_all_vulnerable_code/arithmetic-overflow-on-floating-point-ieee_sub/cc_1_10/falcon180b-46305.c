//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>

// Define the main function
int main() {
    // Declare variables
    double num1, num2, result;
    char operator;

    // Initialize variables
    num1 = 0;
    num2 = 0;
    result = 0;
    operator = '\0';

    // Loop until the user decides to quit
    while (operator!= 'q') {
        // Display the current values
        printf("Current values:\n");
        printf("num1 = %.2f\n", num1);
        printf("num2 = %.2f\n", num2);
        printf("result = %.2f\n", result);

        // Get input from the user
        printf("Enter a number: ");
        scanf("%lf", &num1);

        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("Enter another number: ");
        scanf("%lf", &num2);

        // Perform the selected operation
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
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                }
                break;
            default:
                printf("Error: Invalid operator.\n");
        }

        // Display the result
        printf("Result: %.2f\n", result);

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &operator);
    }

    // Exit the program
    return 0;
}