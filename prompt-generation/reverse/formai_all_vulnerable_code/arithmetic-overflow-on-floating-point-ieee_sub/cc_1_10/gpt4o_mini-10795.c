//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void displayWelcomeMessage() {
    printf("*************************************\n");
    printf("   Welcome to the C Arithmetic Tool   \n");
    printf("*************************************\n");
}

void performArithmeticOperations(float *result, float num1, float num2, char operation) {
    switch(operation) {
        case '+':
            *result = num1 + num2;
            printf("The result of %.2f + %.2f = %.2f\n", num1, num2, *result);
            break;
        case '-':
            *result = num1 - num2;
            printf("The result of %.2f - %.2f = %.2f\n", num1, num2, *result);
            break;
        case '*':
            *result = num1 * num2;
            printf("The result of %.2f * %.2f = %.2f\n", num1, num2, *result);
            break;
        case '/':
            if (num2 != 0) {
                *result = num1 / num2;
                printf("The result of %.2f / %.2f = %.2f\n", num1, num2, *result);
            } else {
                printf("Error: Division by zero is undefined!\n");
            }
            break;
        case '%':
            if ((int)num2 != 0) {
                *result = (int)num1 % (int)num2;
                printf("The result of %.0f %% %.0f = %.0f\n", num1, num2, *result);
            } else {
                printf("Error: Division by zero is undefined for modulus!\n");
            }
            break;
        default:
            printf("Error: Invalid operation selected!\n");
    }
}

int main() {
    displayWelcomeMessage();
    
    float num1, num2;
    float *result = (float *) malloc(sizeof(float)); // Dynamically allocate memory for result
    
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    
    printf("Enter the second number: ");
    scanf("%f", &num2);
    
    char operation;
    printf("Select an operation (+, -, *, /, %%): ");
    scanf(" %c", &operation);
    
    performArithmeticOperations(result, num1, num2, operation);
    
    // If result is computed, display further information
    if (result) {
        printf("\nStored Result: %.2f\n", *result);
    }
    
    // Performing some additional calculations with totals
    printf("\nLet's perform total calculations with results:\n");
    performArithmeticOperations(result, num1, *result, '+'); // Adding first number with result
    performArithmeticOperations(result, num2, *result, '*'); // Multiplying second number with result
    
    if (result) free(result); // Free the dynamically allocated memory
    printf("\nThank you for using the C Arithmetic Tool!\n");
    return 0;
}