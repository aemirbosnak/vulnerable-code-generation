//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, and, or, xor, not, shift;
    char operation;

    // Get user input for numbers and operation
    printf("Enter two integers and an operation (+, -, *, /): ");
    scanf("%d %d %c", &num1, &num2, &operation);

    // Perform operation using bitwise operators
    switch(operation) {
        case '+':
            and = num1 & num2;
            or = num1 | num2;
            xor = num1 ^ num2;
            not = ~num1;
            shift = num1 << 2; // left shift by 2 bits
            printf("AND: %d\nOR: %d\nXOR: %d\nNOT: %d\nShift: %d\n", and, or, xor, not, shift);
            break;
        case '-':
            and = num1 & ~num2;
            or = num1 | ~num2;
            xor = num1 ^ ~num2;
            not = ~(num1 & num2);
            shift = num1 >> 2; // right shift by 2 bits
            printf("AND: %d\nOR: %d\nXOR: %d\nNOT: %d\nShift: %d\n", and, or, xor, not, shift);
            break;
        case '*':
            and = num1 & num2;
            or = num1 | num2;
            xor = num1 ^ num2;
            not = ~num1;
            shift = num1 << 2; // left shift by 2 bits
            printf("AND: %d\nOR: %d\nXOR: %d\nNOT: %d\nShift: %d\n", and, or, xor, not, shift);
            break;
        case '/':
            and = num1 & num2;
            or = num1 | num2;
            xor = num1 ^ num2;
            not = ~num1;
            shift = num1 << 2; // left shift by 2 bits
            printf("AND: %d\nOR: %d\nXOR: %d\nNOT: %d\nShift: %d\n", and, or, xor, not, shift);
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}