//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>

// Function to perform arithmetic operations on two integers
int arithmetic_operations(int num1, int num2, char operation) {
    int result = 0;

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
            if(num2 == 0) {
                printf("Error: Division by zero\n");
                return 0;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operation\n");
            return 0;
    }

    return result;
}

int main() {
    int num1, num2, operation, result;

    // Get input from user
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform arithmetic operation and display result
    result = arithmetic_operations(num1, num2, operation);
    if(result!= 0) {
        printf("Result: %d\n", result);
    }

    return 0;
}