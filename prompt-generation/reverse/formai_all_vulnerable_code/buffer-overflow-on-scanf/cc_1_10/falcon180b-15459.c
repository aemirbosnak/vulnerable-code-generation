//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define BIT_COUNT 8
#define BIT_SHIFT 3

// function to print binary representation of a number
void print_binary(unsigned int num) {
    char binary[BIT_COUNT + 1] = {0};
    int i = BIT_COUNT - 1;
    while (num > 0) {
        binary[i] = (num & 1) + '0';
        num >>= 1;
        i--;
    }
    printf("%s\n", binary);
}

// function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    switch (operation) {
        case '&':
            printf("Bitwise AND: ");
            print_binary(num1 & num2);
            break;
        case '|':
            printf("Bitwise OR: ");
            print_binary(num1 | num2);
            break;
        case '^':
            printf("Bitwise XOR: ");
            print_binary(num1 ^ num2);
            break;
        case '~':
            printf("Bitwise NOT: ");
            print_binary(~num1);
            break;
        case '<<':
            printf("Bitwise Left Shift: ");
            print_binary(num1 << BIT_SHIFT);
            break;
        case '>>':
            printf("Bitwise Right Shift: ");
            print_binary(num1 >> BIT_SHIFT);
            break;
        default:
            printf("Invalid operation\n");
            break;
    }
}

int main() {
    unsigned int num1, num2;
    char operation;

    // prompt user for input
    printf("Enter two numbers in binary format (separated by space): ");
    scanf("%u %u", &num1, &num2);
    printf("Enter the operation you want to perform (AND, OR, XOR, NOT, Left Shift, Right Shift): ");
    scanf(" %c", &operation);

    // perform bitwise operation and print results
    bitwise_operations(num1, num2, operation);

    return 0;
}