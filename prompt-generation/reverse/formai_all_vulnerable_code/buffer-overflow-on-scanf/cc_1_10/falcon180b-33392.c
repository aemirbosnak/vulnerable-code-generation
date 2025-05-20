//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the binary representation of a number
void print_binary(unsigned int num) {
    unsigned int mask = 1 << 31;

    while(mask > 0) {
        if(num & mask) {
            printf("1");
        } else {
            printf("0");
        }

        mask >>= 1;
    }
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    switch(operation) {
        case '&':
            printf("Bitwise AND: ");
            printf("%u\n", num1 & num2);
            break;

        case '|':
            printf("Bitwise OR: ");
            printf("%u\n", num1 | num2);
            break;

        case '^':
            printf("Bitwise XOR: ");
            printf("%u\n", num1 ^ num2);
            break;

        case '~':
            printf("Bitwise NOT: ");
            printf("%u\n", ~num1);
            break;

        case '<<':
            printf("Bitwise Left Shift: ");
            printf("%u\n", num1 << num2);
            break;

        case '>>':
            printf("Bitwise Right Shift: ");
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

    // Get input from user
    printf("Enter the first number: ");
    scanf("%u", &num1);

    printf("Enter the second number: ");
    scanf("%u", &num2);

    printf("Enter the operation (AND, OR, XOR, NOT, Left Shift, Right Shift): ");
    scanf(" %c", &operation);

    // Perform bitwise operations
    bitwise_operations(num1, num2, operation);

    // Print the binary representation of the numbers
    printf("\n");
    printf("Binary representation of %u: ", num1);
    print_binary(num1);

    printf("\n");
    printf("Binary representation of %u: ", num2);
    print_binary(num2);

    return 0;
}