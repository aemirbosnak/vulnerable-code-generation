//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

void printBits(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; --i) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
    putchar('\n');
}

int bitwiseAND(int a, int b) {
    return a & b;
}

int bitwiseOR(int a, int b) {
    return a | b;
}

int bitwiseXOR(int a, int b) {
    return a ^ b;
}

int bitwiseComplement(int a) {
    return ~a;
}

int bitwiseLeftShift(int a, int positions) {
    return a << positions;
}

int bitwiseRightShift(int a, int positions) {
    return a >> positions;
}

void demonstrateBitwiseOperations(int a, int b) {
    printf("Initial Values:\n");
    printf("A = %d; B = %d\n", a, b);

    printf("\nBitwise AND:\n");
    int andResult = bitwiseAND(a, b);
    printf("%d AND %d = %d\n", a, b, andResult);
    printBits(a);
    printBits(b);
    printf("Result (AND): ");
    printBits(andResult);

    printf("\nBitwise OR:\n");
    int orResult = bitwiseOR(a, b);
    printf("%d OR %d = %d\n", a, b, orResult);
    printf("Result (OR): ");
    printBits(orResult);
    
    printf("\nBitwise XOR:\n");
    int xorResult = bitwiseXOR(a, b);
    printf("%d XOR %d = %d\n", a, b, xorResult);
    printf("Result (XOR): ");
    printBits(xorResult);

    printf("\nBitwise Complement:\n");
    int complementA = bitwiseComplement(a);
    int complementB = bitwiseComplement(b);
    printf("Complement of %d = %d\n", a, complementA);
    printf("Complement of %d = %d\n", b, complementB);
    printf("Complement (A): ");
    printBits(complementA);
    printf("Complement (B): ");
    printBits(complementB);

    printf("\nBitwise Left Shift:\n");
    int leftShiftA = bitwiseLeftShift(a, 1);
    int leftShiftB = bitwiseLeftShift(b, 1);
    printf("%d << 1 = %d\n", a, leftShiftA);
    printf("%d << 1 = %d\n", b, leftShiftB);
    printf("Left Shift Result (A): ");
    printBits(leftShiftA);
    printf("Left Shift Result (B): ");
    printBits(leftShiftB);

    printf("\nBitwise Right Shift:\n");
    int rightShiftA = bitwiseRightShift(a, 1);
    int rightShiftB = bitwiseRightShift(b, 1);
    printf("%d >> 1 = %d\n", a, rightShiftA);
    printf("%d >> 1 = %d\n", b, rightShiftB);
    printf("Right Shift Result (A): ");
    printBits(rightShiftA);
    printf("Right Shift Result (B): ");
    printBits(rightShiftB);
}

int main() {
    int a, b;

    printf("Enter the first integer (A): ");
    scanf("%d", &a);
    printf("Enter the second integer (B): ");
    scanf("%d", &b);

    demonstrateBitwiseOperations(a, b);
    return 0;
}