//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, char operation) {
    int result = 0;
    switch(operation) {
        case '&': // Bitwise AND
            result = num1 & num2;
            break;
        case '|': // Bitwise OR
            result = num1 | num2;
            break;
        case '^': // Bitwise XOR
            result = num1 ^ num2;
            break;
        case '~': // Bitwise NOT (complement)
            result = ~num1;
            break;
        case '<<': // Left shift
            result = num1 << num2;
            break;
        case '>>': // Right shift
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }
    printf("Result: %d\n", result);
}

int main() {
    int num1, num2, choice;
    char operation;

    // Get user input for two numbers and operation
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform the operation
    switch(operation) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            if(num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("Result: %d\n", num1 / num2);
            }
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }

    // Ask user if they want to perform bitwise operation
    printf("Do you want to perform bitwise operation? (y/n): ");
    scanf(" %c", &choice);
    if(choice == 'y') {
        printf("Enter bitwise operation (&, |, ^, ~, <<, >>): ");
        scanf(" %c", &operation);
        bitwise_operations(num1, num2, operation);
    }

    return 0;
}