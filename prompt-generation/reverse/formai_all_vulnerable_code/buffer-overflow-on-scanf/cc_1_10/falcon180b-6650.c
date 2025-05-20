//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function to print the binary representation of a number
void print_binary(unsigned int num, int size) {
    char binary[33];
    int i;

    for (i = 0; i < size; i++) {
        binary[i] = '0' + (num & 1);
        num >>= 1;
    }

    printf("%s\n", binary);
}

// Define a function to perform bitwise operations on two numbers
void bitwise_operations(unsigned int num1, unsigned int num2, int operation) {
    switch (operation) {
        case 1: // AND operation
            printf("AND operation: %d\n", num1 & num2);
            break;
        case 2: // OR operation
            printf("OR operation: %d\n", num1 | num2);
            break;
        case 3: // XOR operation
            printf("XOR operation: %d\n", num1 ^ num2);
            break;
        case 4: // Left shift operation
            printf("Left shift operation: %d\n", num1 << num2);
            break;
        case 5: // Right shift operation
            printf("Right shift operation: %d\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    unsigned int num1, num2;
    int operation, size;

    // Get user input for two numbers and the operation to perform
    printf("Enter the first number: ");
    scanf("%u", &num1);

    printf("Enter the second number: ");
    scanf("%u", &num2);

    printf("Enter the operation to perform:\n");
    printf("1. AND\n");
    printf("2. OR\n");
    printf("3. XOR\n");
    printf("4. Left shift\n");
    printf("5. Right shift\n");
    scanf("%d", &operation);

    // Get user input for the number of bits to display
    printf("Enter the number of bits to display: ");
    scanf("%d", &size);

    // Print the binary representation of the two numbers
    printf("Binary representation of %d:\n", num1);
    print_binary(num1, size);

    printf("Binary representation of %d:\n", num2);
    print_binary(num2, size);

    // Perform the selected bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}