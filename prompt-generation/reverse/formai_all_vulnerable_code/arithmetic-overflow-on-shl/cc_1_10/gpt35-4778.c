//FormAI DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>

// Bitwise function to convert decimal to binary
void decimalToBinary(int n) {
    int mask = 1 << 31; // Initialize the mask to 10000000 00000000 00000000 00000000
    printf("%d in binary is: ", n);
    for (int i = 0; i < 32; i++) {
        if (n & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1; // Right shift the mask by 1 bit
    }
    printf("\n");
}

int main() {
    int a = 47, b = 29;

    printf("a = %d, b = %d\n", a, b);
    decimalToBinary(a);
    decimalToBinary(b);

    // Bitwise AND
    int andResult = a & b;
    printf("Bitwise AND: a & b = %d\n", andResult);
    decimalToBinary(andResult);

    // Bitwise OR
    int orResult = a | b;
    printf("Bitwise OR: a | b = %d\n", orResult);
    decimalToBinary(orResult);

    // Bitwise XOR
    int xorResult = a ^ b;
    printf("Bitwise XOR: a ^ b = %d\n", xorResult);
    decimalToBinary(xorResult);

    // Bitwise NOT
    int notResult = ~a;
    printf("Bitwise NOT: ~a = %d\n", notResult);
    decimalToBinary(notResult);

    // Bitwise left shift
    int leftShiftResult = a << 2;
    printf("Bitwise Left Shift: a << 2 = %d\n", leftShiftResult);
    decimalToBinary(leftShiftResult);

    // Bitwise right shift
    int rightShiftResult = b >> 3;
    printf("Bitwise Right Shift: b >> 3 = %d\n", rightShiftResult);
    decimalToBinary(rightShiftResult);

    return 0;
}