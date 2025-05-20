//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to print the binary representation of a number
void print_binary(unsigned int num) {
    char binary[33];
    int i = 0;
    while (num > 0) {
        binary[i++] = (num % 2) + '0';
        num /= 2;
    }
    binary[i] = '\0';
    printf("%s\n", binary);
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, int operation) {
    unsigned int result = 0;

    switch (operation) {
        case 0: // Bitwise AND
            result = num1 & num2;
            break;
        case 1: // Bitwise OR
            result = num1 | num2;
            break;
        case 2: // Bitwise XOR
            result = num1 ^ num2;
            break;
        case 3: // Bitwise NOT (complement)
            result = ~num1;
            break;
        case 4: // Left shift
            result = num1 << num2;
            break;
        case 5: // Right shift
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation!\n");
            exit(1);
    }

    printf("Result: ");
    print_binary(result);
}

int main() {
    unsigned int num1, num2;
    int operation;

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%u", &num1);
    printf("Enter the second number: ");
    scanf("%u", &num2);
    printf("Enter the operation (0: AND, 1: OR, 2: XOR, 3: NOT, 4: Left shift, 5: Right shift): ");
    scanf("%d", &operation);

    // Perform bitwise operation
    bitwise_operations(num1, num2, operation);

    return 0;
}