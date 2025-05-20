//FormAI DATASET v1.0 Category: Calculator ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to the Energetic Calculator!");
    bool run = true;
    while (run) {
        // Get user input for operation
        char operation;
        printf("\nPlease enter your desired operation (+, -, *, /): ");
        scanf(" %c", &operation);
        
        // Get user input for operands
        float operand1, operand2;
        printf("Please enter your first operand: ");
        scanf("%f", &operand1);
        printf("Please enter your second operand: ");
        scanf("%f", &operand2);
        
        // Perform calculation based on operation
        float result = 0;
        switch (operation) {
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
                if (operand2 == 0) {
                    printf("\nError: Division by zero");
                    break;
                }
                result = operand1 / operand2;
                break;
            default:
                printf("\nError: Invalid operation entered");
                break;
        }
        
        // Print the result
        printf("\nYour result is: %.2f", result);
        
        // Ask user if they want to continue using the calculator
        char continue_choice;
        printf("\n\nWould you like to perform another calculation? (y/n): ");
        scanf(" %c", &continue_choice);
        if (continue_choice == 'n') {
            run = false;
        }
    }
    printf("\nThank you for using the Energetic Calculator!");
    return 0;
}