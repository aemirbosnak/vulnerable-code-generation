//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>

// Bitwise operators
#define AND &
#define OR |
#define XOR ^
#define NOT ~
#define LSHIFT <<
#define RSHIFT >>

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    unsigned int mask = 1 << 31;
    while (mask > 0) {
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
}

int main() {
    unsigned int num1 = 0x12345678;
    unsigned int num2 = 0x87654321;

    // Bitwise AND operation
    unsigned int result1 = num1 AND num2;
    printf("Bitwise AND: ");
    print_binary(result1);
    printf("\n");

    // Bitwise OR operation
    unsigned int result2 = num1 OR num2;
    printf("Bitwise OR: ");
    print_binary(result2);
    printf("\n");

    // Bitwise XOR operation
    unsigned int result3 = num1 XOR num2;
    printf("Bitwise XOR: ");
    print_binary(result3);
    printf("\n");

    // Bitwise NOT operation
    unsigned int result4 = NOT num1;
    printf("Bitwise NOT: ");
    print_binary(result4);
    printf("\n");

    // Left shift operation
    unsigned int result5 = num1 LSHIFT 4;
    printf("Left shift by 4: ");
    print_binary(result5);
    printf("\n");

    // Right shift operation
    unsigned int result6 = num1 RSHIFT 4;
    printf("Right shift by 4: ");
    print_binary(result6);
    printf("\n");

    return 0;
}