//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 8

void print_binary(int num) {
    for (int i = NUM_BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    int num1, num2, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // AND operation
    result = num1 & num2;
    printf("AND operation result: ");
    print_binary(result);
    printf("\n");

    // OR operation
    result = num1 | num2;
    printf("OR operation result: ");
    print_binary(result);
    printf("\n");

    // XOR operation
    result = num1 ^ num2;
    printf("XOR operation result: ");
    print_binary(result);
    printf("\n");

    // Left shift operation
    result = num1 << 3;
    printf("Left shift operation result: ");
    print_binary(result);
    printf("\n");

    // Right shift operation
    result = num1 >> 2;
    printf("Right shift operation result: ");
    print_binary(result);
    printf("\n");

    // Complement operation
    result = ~num1;
    printf("Complement operation result: ");
    print_binary(result);
    printf("\n");

    return 0;
}