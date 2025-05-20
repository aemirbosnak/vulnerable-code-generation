//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

#define BIT_SIZE 32

void printBinary(int n) {
    for (int i = BIT_SIZE - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int bitwiseAnd(int a, int b) {
    return a & b;
}

int bitwiseOr(int a, int b) {
    return a | b;
}

int bitwiseXor(int a, int b) {
    return a ^ b;
}

int bitwiseNot(int a) {
    return ~a;
}

int leftShift(int a, int shift) {
    return a << shift;
}

int rightShift(int a, int shift) {
    return a >> shift;
}

void demonstrateBitwiseOperations(int a, int b) {
    printf("Inputs:\n");
    printf("A = ");
    printBinary(a);
    printf("\nB = ");
    printBinary(b);
    printf("\n\n");

    printf("Bitwise AND (A & B):\n");
    printBinary(bitwiseAnd(a, b));
    printf("\n\n");

    printf("Bitwise OR (A | B):\n");
    printBinary(bitwiseOr(a, b));
    printf("\n\n");

    printf("Bitwise XOR (A ^ B):\n");
    printBinary(bitwiseXor(a, b));
    printf("\n\n");

    printf("Bitwise NOT (~A):\n");
    printBinary(bitwiseNot(a));
    printf("\n");

    printf("Bitwise NOT (~B):\n");
    printBinary(bitwiseNot(b));
    printf("\n\n");

    for (int i = 1; i <= 5; i++) {
        printf("Left Shift A (A << %d):\n", i);
        printBinary(leftShift(a, i));
        printf("\n");

        printf("Right Shift A (A >> %d):\n", i);
        printBinary(rightShift(a, i));
        printf("\n");
        
        printf("Left Shift B (B << %d):\n", i);
        printBinary(leftShift(b, i));
        printf("\n");

        printf("Right Shift B (B >> %d):\n", i);
        printBinary(rightShift(b, i));
        printf("\n");
    }
}

int main() {
    int a, b;

    printf("Enter two integers (0 to 4294967295): ");
    scanf("%d %d", &a, &b);

    if (a < 0 || b < 0) {
        printf("Please enter non-negative integers only.\n");
        return 1;
    }

    printf("\nDemonstrating bitwise operations:\n");
    demonstrateBitwiseOperations(a, b);

    return 0;
}