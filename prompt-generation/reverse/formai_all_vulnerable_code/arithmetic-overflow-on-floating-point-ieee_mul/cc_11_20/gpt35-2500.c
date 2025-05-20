//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char operator, choice;
    float num1, num2, result;

    do {
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &operator);

        // Check for valid operator
        if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
            printf("Error: Invalid operator.\n");
            continue;
        }

        printf("Enter two numbers: \n");
        
        // Validate first number input
        while (scanf(" %f", &num1) != 1) {  // Check for non-numeric input
            printf("Error: Invalid input.\n");
            printf("Enter the first number again: ");
            while(getchar() != '\n');  // Ignore remaining input
        }
        
        // Validate second number input
        while (scanf(" %f", &num2) != 1) {  // Check for non-numeric input
            printf("Error: Invalid input.\n");
            printf("Enter the second number again: ");
            while(getchar() != '\n');  // Ignore remaining input
        }

        // Perform calculation based on operator
        switch(operator) {
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
                if (num2 == 0) {  // Check for divide by zero error
                    printf("Error: Divide by zero.\n");
                    continue;
                }
                result = num1 / num2;
                break;
        }

        printf("Result: %.2f \n", result);

        // Prompt user to continue or exit program
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while(tolower(choice) == 'y');

    return 0;
}