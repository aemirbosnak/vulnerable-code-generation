//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a function to perform basic arithmetic operations
int perform_arithmetic(int num1, int num2, char operation) {
    int result = 0;

    // Perform arithmetic operation based on the given operator
    switch(operation) {
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
                printf("Error: Division by zero\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator\n");
            exit(1);
    }

    return result;
}

int main() {
    int num1, num2;
    char operation;

    // Get user input for two numbers and an arithmetic operation
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter arithmetic operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform arithmetic operation and display the result
    int result = perform_arithmetic(num1, num2, operation);
    printf("Result: %d\n", result);

    return 0;
}