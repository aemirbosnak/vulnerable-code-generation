//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform bitwise operations
void bitwise_operations(int num1, int num2, char operation) {
    switch(operation) {
        case '&': // Bitwise AND
            printf("Bitwise AND of %d and %d is: %d\n", num1, num2, num1 & num2);
            break;
        case '|': // Bitwise OR
            printf("Bitwise OR of %d and %d is: %d\n", num1, num2, num1 | num2);
            break;
        case '^': // Bitwise XOR
            printf("Bitwise XOR of %d and %d is: %d\n", num1, num2, num1 ^ num2);
            break;
        case '~': // Bitwise NOT
            printf("Bitwise NOT of %d is: %d\n", num1, ~num1);
            break;
        case '<<': // Bitwise Left Shift
            printf("Bitwise Left Shift of %d by %d is: %d\n", num1, num2, num1 << num2);
            break;
        case '>>': // Bitwise Right Shift
            printf("Bitwise Right Shift of %d by %d is: %d\n", num1, num2, num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    int num1, num2;
    char operation;

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the operation to perform (+, -, *, /, &, |, ^, ~, <<, >>): ");
    scanf(" %c", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}