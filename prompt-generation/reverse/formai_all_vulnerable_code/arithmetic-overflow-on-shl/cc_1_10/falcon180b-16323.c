//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print binary representation of a number
void print_binary(int num) {
    int i = 1;
    while (num > 0) {
        printf("%d", num & 1);
        num >>= 1;
    }
}

int main() {
    int num1, num2, result;

    // Taking input from user
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    // Performing bitwise operations
    result = num1 & num2;
    printf("\nBitwise AND: ");
    print_binary(result);

    result = num1 | num2;
    printf("\nBitwise OR: ");
    print_binary(result);

    result = num1 ^ num2;
    printf("\nBitwise XOR: ");
    print_binary(result);

    result = num1 << 2;
    printf("\nLeft shift by 2: ");
    print_binary(result);

    result = num1 >> 2;
    printf("\nRight shift by 2: ");
    print_binary(result);

    // Bitwise manipulation of a number
    int num3 = 0b10101010;
    printf("\nOriginal number: ");
    print_binary(num3);

    num3 = num3 ^ 0b11110000;
    printf("\nAfter XOR with 0b11110000: ");
    print_binary(num3);

    num3 = num3 & 0b10101010;
    printf("\nAfter AND with 0b10101010: ");
    print_binary(num3);

    num3 = num3 | 0b00101010;
    printf("\nAfter OR with 0b00101010: ");
    print_binary(num3);

    return 0;
}