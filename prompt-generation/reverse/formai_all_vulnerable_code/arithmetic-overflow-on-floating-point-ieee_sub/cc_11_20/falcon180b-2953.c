//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main() {
    double num1, num2, result;
    char operator;

    // Display welcome message
    printf("Welcome to the peaceful calculator!\n");

    // Main loop
    while (1) {
        // Clear the screen
        system("clear");

        // Get input from user
        printf("Enter a number: ");
        scanf("%lf", &num1);
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);

        // Get second number if needed
        switch (operator) {
            case '+':
            case '-':
            case '*':
            case '/':
                printf("Enter another number: ");
                scanf("%lf", &num2);
                break;
            default:
                break;
        }

        // Perform calculation
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
                break;
        }

        // Display result
        printf("Result: %.2lf\n", result);

        // Ask user if they want to continue
        printf("Do you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (tolower(choice)!= 'y') {
            break;
        }
    }

    return 0;
}