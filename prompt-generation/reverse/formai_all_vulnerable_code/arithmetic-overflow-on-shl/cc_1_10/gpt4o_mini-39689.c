//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayBits(unsigned int num);
unsigned int bitwiseAND(unsigned int a, unsigned int b);
unsigned int bitwiseOR(unsigned int a, unsigned int b);
unsigned int bitwiseXOR(unsigned int a, unsigned int b);
unsigned int bitwiseNOT(unsigned int a);
unsigned int leftShift(unsigned int num, int shift);
unsigned int rightShift(unsigned int num, int shift);
unsigned int swapNibbles(unsigned int num);


int main() {
    unsigned int a, b, result;
    int shift;
    
    printf("Enter two unsigned integers (a and b): ");
    scanf("%u %u", &a, &b);

    printf("\nBitwise Operations:\n");
    printf("A = ");
    displayBits(a);
    printf("B = ");
    displayBits(b);

    result = bitwiseAND(a, b);
    printf("A AND B = ");
    displayBits(result);

    result = bitwiseOR(a, b);
    printf("A OR B = ");
    displayBits(result);

    result = bitwiseXOR(a, b);
    printf("A XOR B = ");
    displayBits(result);

    result = bitwiseNOT(a);
    printf("NOT A = ");
    displayBits(result);

    result = bitwiseNOT(b);
    printf("NOT B = ");
    displayBits(result);

    printf("\nLeft Shift A by how many positions? ");
    scanf("%d", &shift);
    result = leftShift(a, shift);
    printf("A << %d = ", shift);
    displayBits(result);

    printf("\nRight Shift A by how many positions? ");
    scanf("%d", &shift);
    result = rightShift(a, shift);
    printf("A >> %d = ", shift);
    displayBits(result);

    printf("\nSwapping nibbles of A:\n");
    result = swapNibbles(a);
    printf("Swapped A = ");
    displayBits(result);

    return 0;
}

// Function to display bits of a number
void displayBits(unsigned int num) {
    unsigned int mask = 1 << (sizeof(num) * 8 - 1);
    for (int i = 0; i < sizeof(num) * 8; i++) {
        putchar((num & mask) ? '1' : '0');
        mask >>= 1;
        if (i % 4 == 3) // For better readability
            putchar(' ');
    }
    printf("\n");
}

// Bitwise AND operation
unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

// Bitwise OR operation
unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

// Bitwise XOR operation
unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Bitwise NOT operation
unsigned int bitwiseNOT(unsigned int a) {
    return ~a;
}

// Left shift operation
unsigned int leftShift(unsigned int num, int shift) {
    return num << shift;
}

// Right shift operation
unsigned int rightShift(unsigned int num, int shift) {
    return num >> shift;
}

// Function to swap nibbles
unsigned int swapNibbles(unsigned int num) {
    return ((num & 0x0F) << 4) | ((num & 0xF0) >> 4);
}