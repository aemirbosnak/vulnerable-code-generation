//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 32

void displayBinary(unsigned int num) {
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        putchar((num & (1U << i)) ? '1' : '0');
    }
    putchar('\n');
}

unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

unsigned int bitwiseNOT(unsigned int a) {
    return ~a;
}

unsigned int leftShift(unsigned int a, int positions) {
    return a << positions;
}

unsigned int rightShift(unsigned int a, int positions) {
    return a >> positions;
}

void calculateBitwiseOperations(unsigned int a, unsigned int b) {
    printf("First Number (A): ");
    displayBinary(a);
    printf("Second Number (B): ");
    displayBinary(b);

    printf("Bitwise AND (A & B): ");
    displayBinary(bitwiseAND(a, b));

    printf("Bitwise OR (A | B): ");
    displayBinary(bitwiseOR(a, b));

    printf("Bitwise XOR (A ^ B): ");
    displayBinary(bitwiseXOR(a, b));

    printf("Bitwise NOT (~A): ");
    displayBinary(bitwiseNOT(a));

    printf("Left Shift (A << 1): ");
    displayBinary(leftShift(a, 1));

    printf("Right Shift (A >> 1): ");
    displayBinary(rightShift(a, 1));
}

unsigned int toggleBit(unsigned int num, int bitPosition) {
    return num ^ (1U << bitPosition);
}

void toggleAllBits(unsigned int *num) {
    *num = bitwiseNOT(*num);
}

int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

unsigned int createMask(int bitPosition) {
    return 1U << bitPosition;
}

void printSetBitsInfo(unsigned int num) {
    printf("Set Bits Information:\n");
    for (int i = 0; i < MAX_BITS; i++) {
        if (num & (1U << i)) {
            printf("Bit %d is set.\n", i);
        }
    }
}

int main() {
    unsigned int a, b;

    printf("Enter two unsigned integers: ");
    if (scanf("%u %u", &a, &b) != 2) {
        fprintf(stderr, "Invalid input.\n");
        return EXIT_FAILURE;
    }

    printf("\nCalculating bitwise operations...\n");
    calculateBitwiseOperations(a, b);

    unsigned int toggled = toggleBit(a, 5);
    printf("\nToggled Bit 5 of A (%u): ", a);
    displayBinary(toggled);

    printf("Before toggling all bits of A: ");
    displayBinary(a);
    toggleAllBits(&a);
    printf("After toggling all bits of A: ");
    displayBinary(a);
    
    printf("\nCount of set bits in the original B: %d\n", countSetBits(b));

    unsigned int mask = createMask(3);
    printf("Mask for bit position 3 (1 << 3): ");
    displayBinary(mask);
    printf("Result of ANDing B with mask: ");
    displayBinary(bitwiseAND(b, mask));

    printSetBitsInfo(b);
    
    return EXIT_SUCCESS;
}