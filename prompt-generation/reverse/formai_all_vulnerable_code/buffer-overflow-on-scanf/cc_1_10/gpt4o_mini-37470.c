//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>

void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) {
            printf(" "); // For better readability
        }
    }
    printf("\n");
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

unsigned int leftShift(unsigned int a, unsigned int shift) {
    return a << shift;
}

unsigned int rightShift(unsigned int a, unsigned int shift) {
    return a >> shift;
}

void demonstrateBitwiseOperations(unsigned int a, unsigned int b) {
    printf("Working with A = %u (%#X) and B = %u (%#X)\n", a, a, b, b);
    
    printf("\n--- Bitwise AND ---\n");
    unsigned int andResult = bitwiseAND(a, b);
    printf("%u & %u = %u\n", a, b, andResult);
    printf("Binary representation: ");
    printBinary(andResult);

    printf("\n--- Bitwise OR ---\n");
    unsigned int orResult = bitwiseOR(a, b);
    printf("%u | %u = %u\n", a, b, orResult);
    printf("Binary representation: ");
    printBinary(orResult);

    printf("\n--- Bitwise XOR ---\n");
    unsigned int xorResult = bitwiseXOR(a, b);
    printf("%u ^ %u = %u\n", a, b, xorResult);
    printf("Binary representation: ");
    printBinary(xorResult);

    printf("\n--- Bitwise NOT ---\n");
    unsigned int notA = bitwiseNOT(a);
    unsigned int notB = bitwiseNOT(b);
    printf("~%u = %u\n", a, notA);
    printf("Binary representation of ~%u: ", a);
    printBinary(notA);
    
    printf("~%u = %u\n", b, notB);
    printf("Binary representation of ~%u: ", b);
    printBinary(notB);

    printf("\n--- Left Shift ---\n");
    unsigned int leftShiftResult = leftShift(a, 2);
    printf("%u << 2 = %u\n", a, leftShiftResult);
    printf("Binary representation: ");
    printBinary(leftShiftResult);

    printf("\n--- Right Shift ---\n");
    unsigned int rightShiftResult = rightShift(b, 2);
    printf("%u >> 2 = %u\n", b, rightShiftResult);
    printf("Binary representation: ");
    printBinary(rightShiftResult);
}

int main() {
    unsigned int a, b;

    printf("Enter two unsigned integers (A and B): ");
    if (scanf("%u %u", &a, &b) != 2) {
        printf("Invalid input. Please enter two unsigned integers.\n");
        return 1;
    }

    demonstrateBitwiseOperations(a, b);

    return 0;
}