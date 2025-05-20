//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Function to print binary representation of a number
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
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    switch (operation) {
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
        case's':
            printf("Bitwise shift left: ");
            printf("%u\n", num1 << 1);
            break;
        case 'S':
            printf("Bitwise shift right: ");
            printf("%u\n", num1 >> 1);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main() {
    // Prompt user for input
    char operation;
    printf("Enter bitwise operation (A for AND, O for OR, X for XOR, N for NOT, S for shift left, s for shift right): ");
    scanf("%c", &operation);

    // Prompt user for numbers
    unsigned int num1, num2;
    printf("Enter first number: ");
    scanf("%u", &num1);
    printf("Enter second number: ");
    scanf("%u", &num2);

    // Print binary representation of numbers
    printf("Binary representation of %u: ", num1);
    print_binary(num1);
    printf("Binary representation of %u: ", num2);
    print_binary(num2);

    // Perform bitwise operations
    bitwise_operations(num1, num2, operation);

    return 0;
}