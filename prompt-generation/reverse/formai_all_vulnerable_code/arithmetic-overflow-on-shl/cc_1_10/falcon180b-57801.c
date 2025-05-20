//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: random
#include <stdio.h>

#define BIT_WIDTH 32

void print_binary(unsigned int num) {
    unsigned int mask = 1 << (BIT_WIDTH - 1);
    while (mask) {
        printf("%u", num & mask? 1 : 0);
        mask >>= 1;
    }
}

int main() {
    unsigned int num1 = 0b10101010;
    unsigned int num2 = 0b01010101;

    printf("Number 1 in binary: ");
    print_binary(num1);
    printf("\n");

    printf("Number 2 in binary: ");
    print_binary(num2);
    printf("\n");

    // Bitwise AND
    unsigned int result_and = num1 & num2;
    printf("Bitwise AND: ");
    print_binary(result_and);
    printf("\n");

    // Bitwise OR
    unsigned int result_or = num1 | num2;
    printf("Bitwise OR: ");
    print_binary(result_or);
    printf("\n");

    // Bitwise XOR
    unsigned int result_xor = num1 ^ num2;
    printf("Bitwise XOR: ");
    print_binary(result_xor);
    printf("\n");

    // Bitwise NOT
    unsigned int result_not = ~num1;
    printf("Bitwise NOT: ");
    print_binary(result_not);
    printf("\n");

    // Bitwise left shift
    unsigned int result_left_shift = num1 << 4;
    printf("Bitwise left shift by 4: ");
    print_binary(result_left_shift);
    printf("\n");

    // Bitwise right shift
    unsigned int result_right_shift = num1 >> 4;
    printf("Bitwise right shift by 4: ");
    print_binary(result_right_shift);
    printf("\n");

    return 0;
}