//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>

// Define the Bitwise operations
#define AND_OPERATION 1
#define OR_OPERATION 2
#define XOR_OPERATION 3
#define NOT_OPERATION 4
#define SHIFT_LEFT_OPERATION 5
#define SHIFT_RIGHT_OPERATION 6

// Function to perform Bitwise operations
void perform_bitwise_operation(int operation, int num1, int num2) {
    switch(operation) {
        case AND_OPERATION:
            printf("Bitwise AND operation result: %d\n", num1 & num2);
            break;
        case OR_OPERATION:
            printf("Bitwise OR operation result: %d\n", num1 | num2);
            break;
        case XOR_OPERATION:
            printf("Bitwise XOR operation result: %d\n", num1 ^ num2);
            break;
        case NOT_OPERATION:
            printf("Bitwise NOT operation result: %d\n", ~num1);
            break;
        case SHIFT_LEFT_OPERATION:
            printf("Bitwise shift left operation result: %d\n", num1 << num2);
            break;
        case SHIFT_RIGHT_OPERATION:
            printf("Bitwise shift right operation result: %d\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
    }
}

int main() {
    int num1, num2, operation;

    // Get input from user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation (1 for AND, 2 for OR, 3 for XOR, 4 for NOT, 5 for shift left, 6 for shift right): ");
    scanf("%d", &operation);

    // Perform Bitwise operation
    perform_bitwise_operation(operation, num1, num2);

    return 0;
}