//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BITS 32

void print_binary(unsigned int num) {
    char binary[NUM_BITS + 1];
    memset(binary, '0', NUM_BITS);
    binary[NUM_BITS] = '\0';
    int i = NUM_BITS - 1;
    while (num > 0) {
        binary[i] = '1';
        num--;
        i--;
    }
    printf("%s\n", binary);
}

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Bitwise OR operation
    unsigned int result = num1 | num2;
    printf("Bitwise OR: ");
    print_binary(result);

    // Bitwise AND operation
    result = num1 & num2;
    printf("Bitwise AND: ");
    print_binary(result);

    // Bitwise XOR operation
    result = num1 ^ num2;
    printf("Bitwise XOR: ");
    print_binary(result);

    // Bitwise NOT operation
    result = ~num1;
    printf("Bitwise NOT: ");
    print_binary(result);

    // Left shift operation
    result = num1 << 3;
    printf("Left shift by 3: ");
    print_binary(result);

    // Right shift operation
    result = num1 >> 3;
    printf("Right shift by 3: ");
    print_binary(result);

    return 0;
}