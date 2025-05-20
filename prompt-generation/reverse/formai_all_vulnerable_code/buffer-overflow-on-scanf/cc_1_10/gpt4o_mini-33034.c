//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: accurate
#include <stdio.h>

// Function prototypes
void displayBits(unsigned int num);
unsigned int bitwiseAnd(unsigned int a, unsigned int b);
unsigned int bitwiseOr(unsigned int a, unsigned int b);
unsigned int bitwiseXor(unsigned int a, unsigned int b);
unsigned int bitwiseNot(unsigned int a);
unsigned int leftShift(unsigned int num, int shift);
unsigned int rightShift(unsigned int num, int shift);

int main() {
    unsigned int num1, num2;
    int shiftAmount;

    printf("Enter two unsigned integers (num1 and num2): ");
    scanf("%u %u", &num1, &num2);

    printf("\nBitwise Operations on %u and %u:\n", num1, num2);
    
    printf("Bitwise AND:\n");
    displayBits(num1);
    displayBits(num2);
    printf("Result: %u\n", bitwiseAnd(num1, num2));
    displayBits(bitwiseAnd(num1, num2));

    printf("\nBitwise OR:\n");
    displayBits(num1);
    displayBits(num2);
    printf("Result: %u\n", bitwiseOr(num1, num2));
    displayBits(bitwiseOr(num1, num2));

    printf("\nBitwise XOR:\n");
    displayBits(num1);
    displayBits(num2);
    printf("Result: %u\n", bitwiseXor(num1, num2));
    displayBits(bitwiseXor(num1, num2));

    printf("\nBitwise NOT of num1:\n");
    displayBits(num1);
    printf("Result: %u\n", bitwiseNot(num1));
    displayBits(bitwiseNot(num1));

    printf("\nBitwise NOT of num2:\n");
    displayBits(num2);
    printf("Result: %u\n", bitwiseNot(num2));
    displayBits(bitwiseNot(num2));

    printf("\nEnter number and shift amount for left shift: ");
    scanf("%u %d", &num1, &shiftAmount);
    printf("\nLeft Shift %u by %d:\n", num1, shiftAmount);
    displayBits(num1);
    printf("Result: %u\n", leftShift(num1, shiftAmount));
    displayBits(leftShift(num1, shiftAmount));

    printf("\nEnter number and shift amount for right shift: ");
    scanf("%u %d", &num1, &shiftAmount);
    printf("\nRight Shift %u by %d:\n", num1, shiftAmount);
    displayBits(num1);
    printf("Result: %u\n", rightShift(num1, shiftAmount));
    displayBits(rightShift(num1, shiftAmount));

    return 0;
}

void displayBits(unsigned int num) {
    printf("Bits: ");
    for(int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%u", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Adding spaces for better readability
    }
    printf("\n");
}

unsigned int bitwiseAnd(unsigned int a, unsigned int b) {
    return a & b;
}

unsigned int bitwiseOr(unsigned int a, unsigned int b) {
    return a | b;
}

unsigned int bitwiseXor(unsigned int a, unsigned int b) {
    return a ^ b;
}

unsigned int bitwiseNot(unsigned int a) {
    return ~a;
}

unsigned int leftShift(unsigned int num, int shift) {
    return num << shift;
}

unsigned int rightShift(unsigned int num, int shift) {
    return num >> shift;
}