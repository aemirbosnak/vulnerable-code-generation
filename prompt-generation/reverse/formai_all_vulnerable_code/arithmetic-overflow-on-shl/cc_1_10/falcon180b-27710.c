//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Function to print binary representation of a number
void print_binary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }
    char binary[33]; // Maximum 32 bits + null terminator
    int i = 31;
    binary[i] = '\0';
    while (num > 0) {
        binary[--i] = (num & 1) + '0';
        num >>= 1;
    }
    printf("%s", binary);
}

// Function to perform bitwise operations on two numbers
void bitwise_operations(int num1, int num2) {
    // AND operation
    printf("AND Operation:\n");
    int result = num1 & num2;
    printf("Result: ");
    print_binary(result);
    printf("\n");

    // OR operation
    printf("OR Operation:\n");
    result = num1 | num2;
    printf("Result: ");
    print_binary(result);
    printf("\n");

    // XOR operation
    printf("XOR Operation:\n");
    result = num1 ^ num2;
    printf("Result: ");
    print_binary(result);
    printf("\n");

    // Left shift operation
    printf("Left Shift Operation:\n");
    result = num1 << 2;
    printf("Result: ");
    print_binary(result);
    printf("\n");

    // Right shift operation
    printf("Right Shift Operation:\n");
    result = num1 >> 2;
    printf("Result: ");
    print_binary(result);
    printf("\n");
}

int main() {
    int num1, num2;

    // Get input from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Perform bitwise operations
    bitwise_operations(num1, num2);

    return 0;
}