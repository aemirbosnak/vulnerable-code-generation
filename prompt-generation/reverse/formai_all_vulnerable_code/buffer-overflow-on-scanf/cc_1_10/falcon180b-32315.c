//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    if (num == 0) {
        printf("0");
        return;
    }
    char bin[33];
    int i = 31;
    bin[i--] = '\0';
    while (num > 0) {
        bin[i--] = (num & 1) + '0';
        num >>= 1;
    }
    printf("%s", bin);
}

// Function to perform bitwise operations
void bitwise_operations(unsigned int num1, unsigned int num2, char operation) {
    switch (operation) {
        case '&':
            printf("Bitwise AND: ");
            printf("Result: %u\n", num1 & num2);
            break;
        case '|':
            printf("Bitwise OR: ");
            printf("Result: %u\n", num1 | num2);
            break;
        case '^':
            printf("Bitwise XOR: ");
            printf("Result: %u\n", num1 ^ num2);
            break;
        case '~':
            printf("Bitwise NOT: ");
            printf("Result: %u\n", ~num1);
            break;
        case '<<':
            printf("Left shift: ");
            printf("Result: %u\n", num1 << num2);
            break;
        case '>>':
            printf("Right shift: ");
            printf("Result: %u\n", num1 >> num2);
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

int main() {
    unsigned int num1, num2;
    char operation;

    // Get input from user
    printf("Enter first number: ");
    if (scanf("%u", &num1)!= 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter second number: ");
    if (scanf("%u", &num2)!= 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter operation (+, -, *, /, ^, &, |, <<, >>): ");
    if (scanf(" %c", &operation)!= 1) {
        printf("Invalid input.\n");
        return 1;
    }

    // Perform bitwise operations
    bitwise_operations(num1, num2, operation);

    return 0;
}