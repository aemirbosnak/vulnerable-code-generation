//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, int operation) {
    int result = 0;
    int mask = 0;

    // Set the mask based on the operation
    switch (operation) {
        case 0: // AND operation
            mask = 0x000000FF;
            break;
        case 1: // OR operation
            mask = 0x0000FF00;
            break;
        case 2: // XOR operation
            mask = 0x00FF0000;
            break;
        case 3: // NOT operation
            result = ~num1;
            break;
        default:
            printf("Invalid operation selected\n");
            exit(1);
    }

    // Perform the operation and print the result
    switch (operation) {
        case 0: // AND operation
            result = num1 & num2;
            printf("AND result: %d\n", result);
            break;
        case 1: // OR operation
            result = num1 | num2;
            printf("OR result: %d\n", result);
            break;
        case 2: // XOR operation
            result = num1 ^ num2;
            printf("XOR result: %d\n", result);
            break;
        case 3: // NOT operation
            printf("NOT result: %d\n", result);
            break;
        default:
            printf("Invalid operation selected\n");
            exit(1);
    }
}

int main() {
    int num1, num2, operation;

    // Get input from user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (0 for AND, 1 for OR, 2 for XOR, 3 for NOT): ");
    scanf("%d", &operation);

    // Call the bitwise_operations function
    bitwise_operations(num1, num2, operation);

    return 0;
}