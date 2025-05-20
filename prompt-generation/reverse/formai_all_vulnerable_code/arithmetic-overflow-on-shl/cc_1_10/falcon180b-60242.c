//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Function to print binary representation of a number
void print_binary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main() {
    uint32_t num1 = 0x12345678;
    uint32_t num2 = 0x87654321;

    // Bitwise AND operation
    uint32_t result1 = num1 & num2;
    printf("Bitwise AND: ");
    print_binary(result1);
    printf("\n");

    // Bitwise OR operation
    uint32_t result2 = num1 | num2;
    printf("Bitwise OR: ");
    print_binary(result2);
    printf("\n");

    // Bitwise XOR operation
    uint32_t result3 = num1 ^ num2;
    printf("Bitwise XOR: ");
    print_binary(result3);
    printf("\n");

    // Left shift operation
    uint32_t result4 = num1 << 4;
    printf("Left shift by 4: ");
    print_binary(result4);
    printf("\n");

    // Right shift operation
    uint32_t result5 = num1 >> 4;
    printf("Right shift by 4: ");
    print_binary(result5);
    printf("\n");

    // Bitwise NOT operation
    uint32_t result6 = ~num1;
    printf("Bitwise NOT: ");
    print_binary(result6);
    printf("\n");

    return 0;
}