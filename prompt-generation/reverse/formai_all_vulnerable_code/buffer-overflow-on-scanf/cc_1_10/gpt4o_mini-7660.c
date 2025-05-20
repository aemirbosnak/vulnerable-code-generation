//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 32 // Maximum number of bits for display

// Function prototypes
void displayBits(uint32_t num);
uint32_t bitwiseAND(uint32_t a, uint32_t b);
uint32_t bitwiseOR(uint32_t a, uint32_t b);
uint32_t bitwiseXOR(uint32_t a, uint32_t b);
uint32_t bitwiseNOT(uint32_t a);
uint32_t leftShift(uint32_t a, int shift);
uint32_t rightShift(uint32_t a, int shift);

int main() {
    uint32_t a, b, result;
    int shift;

    printf("Enter first number (decimal): ");
    if (scanf("%u", &a) != 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    printf("Enter second number (decimal): ");
    if (scanf("%u", &b) != 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }

    printf("\nBitwise Operations:\n");
    printf("a = ");
    displayBits(a);
    printf("b = ");
    displayBits(b);

    printf("\na AND b:\n");
    result = bitwiseAND(a, b);
    displayBits(result);

    printf("\na OR b:\n");
    result = bitwiseOR(a, b);
    displayBits(result);

    printf("\na XOR b:\n");
    result = bitwiseXOR(a, b);
    displayBits(result);

    printf("\nNOT a:\n");
    result = bitwiseNOT(a);
    displayBits(result);

    printf("\nNOT b:\n");
    result = bitwiseNOT(b);
    displayBits(result);

    printf("\nEnter number of bits to shift for left shift operation: ");
    if (scanf("%d", &shift) != 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }
    result = leftShift(a, shift);
    printf("\na left shifted by %d:\n", shift);
    displayBits(result);

    printf("\nEnter number of bits to shift for right shift operation: ");
    if (scanf("%d", &shift) != 1) {
        fprintf(stderr, "Invalid input!\n");
        return EXIT_FAILURE;
    }
    result = rightShift(a, shift);
    printf("\na right shifted by %d:\n", shift);
    displayBits(result);

    return EXIT_SUCCESS;
}

void displayBits(uint32_t num) {
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        if (num & (1U << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf(" (Decimal: %u)\n", num);
}

uint32_t bitwiseAND(uint32_t a, uint32_t b) {
    return a & b;
}

uint32_t bitwiseOR(uint32_t a, uint32_t b) {
    return a | b;
}

uint32_t bitwiseXOR(uint32_t a, uint32_t b) {
    return a ^ b;
}

uint32_t bitwiseNOT(uint32_t a) {
    return ~a;
}

uint32_t leftShift(uint32_t a, int shift) {
    return a << shift;
}

uint32_t rightShift(uint32_t a, int shift) {
    return a >> shift;
}