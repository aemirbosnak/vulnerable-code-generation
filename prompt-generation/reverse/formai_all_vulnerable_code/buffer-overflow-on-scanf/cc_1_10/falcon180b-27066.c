//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define a function to print binary representation of a number
void printBinary(unsigned int num) {
    int i;
    for (i = 0; i < 32; i++) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Define a function to perform bitwise operations
void bitwiseOps(int op, unsigned int num1, unsigned int num2) {
    switch (op) {
        case 1: // Bitwise AND
            printf("Bitwise AND: ");
            printf("Result: %u\n", num1 & num2);
            break;
        case 2: // Bitwise OR
            printf("Bitwise OR: ");
            printf("Result: %u\n", num1 | num2);
            break;
        case 3: // Bitwise XOR
            printf("Bitwise XOR: ");
            printf("Result: %u\n", num1 ^ num2);
            break;
        case 4: // Bitwise NOT
            printf("Bitwise NOT: ");
            printf("Result: %u\n", ~num1);
            break;
        case 5: // Left shift
            printf("Left shift: ");
            printf("Result: %u\n", num1 << num2);
            break;
        case 6: // Right shift
            printf("Right shift: ");
            printf("Result: %u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main() {
    int choice, op;
    unsigned int num1, num2;

    // Get user choice for operation
    printf("Enter the operation you want to perform:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left shift\n");
    printf("6. Right shift\n");
    scanf("%d", &choice);

    // Get user choice for operation
    printf("Enter the operation you want to perform:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Left shift\n");
    printf("6. Right shift\n");
    scanf("%d", &op);

    // Get user input for numbers
    printf("Enter the first number:\n");
    scanf("%u", &num1);
    printf("Enter the second number:\n");
    scanf("%u", &num2);

    // Perform bitwise operation and print result
    bitwiseOps(op, num1, num2);

    return 0;
}