//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, int operation) {
    unsigned int result = 0;
    switch(operation) {
        case 0: // AND operation
            result = num1 & num2;
            break;
        case 1: // OR operation
            result = num1 | num2;
            break;
        case 2: // XOR operation
            result = num1 ^ num2;
            break;
        case 3: // NOT operation
            result = ~num1;
            break;
        case 4: // Left shift operation
            result = num1 << num2;
            break;
        case 5: // Right shift operation
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }
    printf("Result: %u\n", result);
}

int main() {
    unsigned int num1, num2;
    int operation;

    // Get input from the user
    printf("Enter the first number: ");
    scanf("%u", &num1);
    printf("Enter the second number: ");
    scanf("%u", &num2);
    printf("Enter the operation (0 for AND, 1 for OR, 2 for XOR, 3 for NOT, 4 for left shift, 5 for right shift): ");
    scanf("%d", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}