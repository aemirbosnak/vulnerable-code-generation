//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Calculator {
    double operand1;
    double operand2;
    char operator;
} Calculator;

void displayMenu() {
    printf("\nSimple Shape-Shifting Calculator\n");
    printf("Choose an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit\n");
}

int getUserInput(Calculator *calc) {
    printf("Enter first operand: ");
    if (scanf("%lf", &calc->operand1) != 1) {
        printf("Invalid input for operand. Please enter a number.\n");
        return -1;
    }
    
    printf("Enter an operator: ");
    while (getchar() != '\n'); // Clear input buffer
    if (scanf("%c", &calc->operator) != 1 || 
        (calc->operator != '+' && calc->operator != '-' && 
         calc->operator != '*' && calc->operator != '/')) {
        printf("Invalid operator. Please enter one of +, -, *, /.\n");
        return -2;
    }

    printf("Enter second operand: ");
    if (scanf("%lf", &calc->operand2) != 1) {
        printf("Invalid input for operand. Please enter a number.\n");
        return -3;
    }
    
    return 0;
}

void calculate(Calculator *calc) {
    double result;
    int error_flag = 0;
    
    switch (calc->operator) {
        case '+':
            result = calc->operand1 + calc->operand2;
            break;
        case '-':
            result = calc->operand1 - calc->operand2;
            break;
        case '*':
            result = calc->operand1 * calc->operand2;
            break;
        case '/':
            if (calc->operand2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                error_flag = 1;
            } else {
                result = calc->operand1 / calc->operand2;
            }
            break;
        default:
            printf("Error: Invalid operation.\n");
            error_flag = 1;
    }

    if (!error_flag) {
        printf("Result of %.2lf %c %.2lf = %.2lf\n", calc->operand1, calc->operator, calc->operand2, result);
    }
}

int main() {
    Calculator calc;
    int choice = 0;
    
    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please select a number between 1 and 5.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }

        int inputStatus = getUserInput(&calc);
        if (inputStatus == 0) {
            calculate(&calc);
        } else {
            // Handling each input error
            switch(inputStatus) {
                case -1:
                    printf("Fix the first operand input before retrying.\n");
                    break;
                case -2:
                    printf("Fix the operator input before retrying.\n");
                    break;
                case -3:
                    printf("Fix the second operand input before retrying.\n");
                    break;
                default:
                    printf("An unexpected error occurred.\n");
            }
        }
    } while (choice != 5);
    
    return 0;
}