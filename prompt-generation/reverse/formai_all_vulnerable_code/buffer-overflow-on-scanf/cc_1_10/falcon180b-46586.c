//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100

// Function to print the binary representation of a number
void print_binary(unsigned int num) {
    char binary[33];
    sprintf(binary, "%32b", num);
    printf("%s\n", binary);
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    switch(operation) {
        case '&': // Bitwise AND
            printf("Bitwise AND: ");
            printf("%u\n", num1 & num2);
            break;
        case '|': // Bitwise OR
            printf("Bitwise OR: ");
            printf("%u\n", num1 | num2);
            break;
        case '^': // Bitwise XOR
            printf("Bitwise XOR: ");
            printf("%u\n", num1 ^ num2);
            break;
        case '~': // Bitwise NOT
            printf("Bitwise NOT: ");
            printf("%u\n", ~num1);
            break;
        case '<<': // Left shift
            printf("Left shift: ");
            printf("%u\n", num1 << num2);
            break;
        case '>>': // Right shift
            printf("Right shift: ");
            printf("%u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation!\n");
            break;
    }
}

int main() {
    unsigned int num1, num2;
    char operation;

    // Prompt user for input
    printf("Enter two unsigned integers: ");
    scanf("%u %u", &num1, &num2);
    printf("Enter the operation to perform (+, -, *, /, &, |, ^, ~, <<, >>): ");
    scanf(" %c", &operation);

    // Perform bitwise operations
    bitwise_operations(num1, num2, operation);

    // Print binary representation of numbers and result
    printf("Binary representation of num1: ");
    print_binary(num1);
    printf("Binary representation of num2: ");
    print_binary(num2);

    return 0;
}