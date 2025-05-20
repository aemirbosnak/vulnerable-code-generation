//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

// Function to print the binary representation of a given number
void print_binary(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Function to perform bitwise operations on two numbers
void bit_operations(unsigned int num1, unsigned int num2, char operation) {
    switch (operation) {
        case '&': // Bitwise AND
            printf("Result: %u\n", num1 & num2);
            break;
        case '|': // Bitwise OR
            printf("Result: %u\n", num1 | num2);
            break;
        case '^': // Bitwise XOR
            printf("Result: %u\n", num1 ^ num2);
            break;
        case '~': // Bitwise NOT
            printf("Result: %u\n", ~num1);
            break;
        case '<<': // Left shift
            printf("Result: %u\n", num1 << num2);
            break;
        case '>>': // Right shift
            printf("Result: %u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    // Declare variables
    unsigned int num1, num2;
    char operation;

    // Get user input for two numbers and an operation
    printf("Enter two numbers (in decimal): ");
    scanf("%u %u", &num1, &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);

    // Perform bitwise operations
    bit_operations(num1, num2, operation);

    return 0;
}