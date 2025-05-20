//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void displayInstructions() {
    printf("---------------------------------------------------\n");
    printf("Welcome to the Arithmetic Operations Calculator!\n");
    printf("You can perform the following operations:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Press 'q' to quit.\n");
    printf("---------------------------------------------------\n");
}

double performOperation(double num1, char operator, double num2) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0.0) {
                return num1 / num2;
            } else {
                printf("Error: Division by zero is undefined!\n");
                return 0.0;
            }
        default:
            printf("Error: Unsupported operation '%c'\n", operator);
            return 0.0;
    }
}

int main() {
    displayInstructions();

    char operator;
    double num1, num2, result;

    while (1) {
        printf("Enter your operation (e.g., 5 + 3): ");
        if (scanf("%lf %c %lf", &num1, &operator, &num2) != 3) {
            char exitChar;
            scanf("%c", &exitChar);
            if (exitChar == 'q' || exitChar == 'Q') {
                printf("Exiting the calculator. Goodbye!\n");
                break;
            } else {
                printf("Invalid input format. Please try again.\n");
                // Clear the input buffer
                while(getchar() != '\n');
                continue;
            }
        }
        
        result = performOperation(num1, operator, num2);
        printf("Result: %.2lf\n", result);
        printf("---------------------------------------------------\n");
    }

    return 0;
}