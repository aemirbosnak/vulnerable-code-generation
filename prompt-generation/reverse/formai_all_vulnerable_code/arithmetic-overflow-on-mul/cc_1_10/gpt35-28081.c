//FormAI DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary = 0, base = 1;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    printf("Binary: %d\n", binary);
}

// Function to convert binary to decimal
void binaryToDecimal(int binary) {
    int decimal = 0, base = 1;

    while (binary > 0) {
        int digit = binary % 10;
        decimal += digit * base;
        binary /= 10;
        base *= 2;
    }

    printf("Decimal: %d\n", decimal);
}

int main() {
    int a = 60; // 00111100 in binary
    int b = 13; // 00001101 in binary

    // Bitwise AND
    int c = a & b; // 00001100 in binary
    printf("Bitwise AND: %d\n", c);

    // Bitwise OR
    int d = a | b; // 00111101 in binary
    printf("Bitwise OR: %d\n", d);

    // Bitwise XOR
    int e = a ^ b; // 00110001 in binary
    printf("Bitwise XOR: %d\n", e);

    // Bitwise NOT
    int f = ~a; // 11000011 in binary (assuming 8-bit integers)
    printf("Bitwise NOT: %d\n", f);

    // Left shift
    int g = a << 2; // 11110000 in binary
    printf("Left shift: %d\n", g);

    // Right shift
    int h = a >> 2; // 00001111 in binary
    printf("Right shift: %d\n", h);

    printf("\n");

    printf("Decimal to binary conversion:\n");
    decimalToBinary(128);
    decimalToBinary(255);
    decimalToBinary(1024);

    printf("\n");

    printf("Binary to decimal conversion:\n");
    binaryToDecimal(10101);
    binaryToDecimal(11111);
    binaryToDecimal(11000100);

    return 0;
}