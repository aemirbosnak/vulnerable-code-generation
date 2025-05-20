//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>

#define BIT_SET(var, bit) ((var) |= (1 << (bit)))
#define BIT_CLEAR(var, bit) ((var) &= ~(1 << (bit)))
#define BIT_TOGGLE(var, bit) ((var) ^= (1 << (bit)))
#define BIT_CHECK(var, bit) ((var) & (1 << (bit)))

// Function to print the binary representation of a number
void print_binary(int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main() {
    int num1 = 0b10101010;
    int num2 = 0b11110000;

    // Bitwise AND operation
    int result1 = num1 & num2;
    printf("Bitwise AND: ");
    print_binary(result1);
    printf("\n");

    // Bitwise OR operation
    int result2 = num1 | num2;
    printf("Bitwise OR: ");
    print_binary(result2);
    printf("\n");

    // Bitwise XOR operation
    int result3 = num1 ^ num2;
    printf("Bitwise XOR: ");
    print_binary(result3);
    printf("\n");

    // Bitwise NOT operation
    int result4 = ~num1;
    printf("Bitwise NOT: ");
    print_binary(result4);
    printf("\n");

    // Bitwise left shift operation
    int result5 = num1 << 3;
    printf("Bitwise left shift: ");
    print_binary(result5);
    printf("\n");

    // Bitwise right shift operation
    int result6 = num1 >> 3;
    printf("Bitwise right shift: ");
    print_binary(result6);
    printf("\n");

    return 0;
}