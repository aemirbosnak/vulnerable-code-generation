//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define NUM_BITS 32

void print_binary(unsigned int num) {
    int i;
    for (i = 0; i < NUM_BITS; i++) {
        printf("%d", (num & (1 << i)) >> i);
    }
}

int main() {
    unsigned int num1 = 0b10101010;
    unsigned int num2 = 0b01010101;

    printf("Binary representation of num1: ");
    print_binary(num1);
    printf("\n");

    printf("Binary representation of num2: ");
    print_binary(num2);
    printf("\n");

    unsigned int result = num1 | num2;
    printf("OR operation result: ");
    print_binary(result);
    printf("\n");

    result = num1 & num2;
    printf("AND operation result: ");
    print_binary(result);
    printf("\n");

    result = num1 ^ num2;
    printf("XOR operation result: ");
    print_binary(result);
    printf("\n");

    result = ~num1;
    printf("NOT operation result: ");
    print_binary(result);
    printf("\n");

    result = num1 << 2;
    printf("Left shift operation result: ");
    print_binary(result);
    printf("\n");

    result = num1 >> 2;
    printf("Right shift operation result: ");
    print_binary(result);
    printf("\n");

    return 0;
}