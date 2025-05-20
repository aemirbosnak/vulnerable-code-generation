//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store calculator operations
typedef struct Operation {
    char operator;
    double operand1;
    double operand2;
    double result;
} Operation;

// Function to perform calculator operations
double performOperation(Operation operation) {
    switch (operation.operator) {
        case '+':
            return operation.operand1 + operation.operand2;
        case '-':
            return operation.operand1 - operation.operand2;
        case '*':
            return operation.operand1 * operation.operand2;
        case '/':
            return operation.operand1 / operation.operand2;
        default:
            return 0;
    }
}

// Main function
int main() {
    // Create an operation structure
    Operation operation;

    // Get the operator, operand1, and operand2 from the user
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operation.operator);

    printf("Enter operand1: ");
    scanf("%lf", &operation.operand1);

    printf("Enter operand2: ");
    scanf("%lf", &operation.operand2);

    // Perform the operation
    operation.result = performOperation(operation);

    // Display the result
    printf("The result is: %.2lf\n", operation.result);

    return 0;
}