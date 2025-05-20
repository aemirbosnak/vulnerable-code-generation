//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    int i = 31;
    while (i >= 0) {
        if (num & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
        i--;
    }
    printf("\n");
}

int main() {
    unsigned int num1 = 0b10101010;
    unsigned int num2 = 0b01110101;

    // Bitwise OR operation
    unsigned int result1 = num1 | num2;
    printf("Bitwise OR operation:\n");
    print_binary(num1);
    print_binary(num2);
    print_binary(result1);

    // Bitwise AND operation
    unsigned int result2 = num1 & num2;
    printf("\nBitwise AND operation:\n");
    print_binary(num1);
    print_binary(num2);
    print_binary(result2);

    // Bitwise XOR operation
    unsigned int result3 = num1 ^ num2;
    printf("\nBitwise XOR operation:\n");
    print_binary(num1);
    print_binary(num2);
    print_binary(result3);

    // Bitwise NOT operation
    unsigned int result4 = ~num1;
    printf("\nBitwise NOT operation:\n");
    print_binary(num1);
    print_binary(result4);

    // Left shift operation
    unsigned int result5 = num1 << 2;
    printf("\nLeft shift operation:\n");
    print_binary(num1);
    print_binary(result5);

    // Right shift operation
    unsigned int result6 = num1 >> 2;
    printf("\nRight shift operation:\n");
    print_binary(num1);
    print_binary(result6);

    return 0;
}