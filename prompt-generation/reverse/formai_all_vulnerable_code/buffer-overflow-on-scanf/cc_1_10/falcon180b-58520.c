//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    int i = 0;
    while (num > 0) {
        printf("%d", num % 2);
        num /= 2;
        i++;
        if (i == 8) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    printf("\nBitwise operations:\n");
    switch (operation) {
        case '&':
            printf("num1 & num2 = %u\n", num1 & num2);
            break;
        case '|':
            printf("num1 | num2 = %u\n", num1 | num2);
            break;
        case '^':
            printf("num1 ^ num2 = %u\n", num1 ^ num2);
            break;
        case '~':
            printf("~num1 = %u\n", ~num1);
            break;
        case '<<':
            printf("num1 << 2 = %u\n", num1 << 2);
            break;
        case '>>':
            printf("num1 >> 2 = %u\n", num1 >> 2);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main() {
    unsigned int num1, num2;

    // Get user input for numbers
    printf("Enter two unsigned integers: ");
    scanf("%u %u", &num1, &num2);

    // Print binary representation of numbers
    printf("\nBinary representation of num1: ");
    print_binary(num1);
    printf("\nBinary representation of num2: ");
    print_binary(num2);

    // Perform bitwise operations
    char operation;
    printf("\nEnter the operation you want to perform (and, or, xor, not, left shift, right shift): ");
    scanf(" %c", &operation);
    bitwise_operations(num1, num2, operation);

    return 0;
}