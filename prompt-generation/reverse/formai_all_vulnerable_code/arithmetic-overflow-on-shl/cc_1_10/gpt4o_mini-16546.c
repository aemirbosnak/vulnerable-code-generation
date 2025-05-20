//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>

void printBinary(int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
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

int bitwiseNOT(int a) {
    return ~a;
}

int leftShift(int a, int n) {
    return a << n;
}

int rightShift(int a, int n) {
    return a >> n;
}

int main() {
    int num1, num2, result;
    int shiftBits;

    printf("Bitwise Operations Demonstration\n");
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    printf("You entered: %d and %d\n", num1, num2);

    printf("\nBinary Representation:\n");
    printf("Num1: ");
    printBinary(num1);
    printf("Num2: ");
    printBinary(num2);

    printf("\nBitwise Operations:\n");
    
    result = bitwiseAND(num1, num2);
    printf("Bitwise AND (Num1 & Num2): ");
    printBinary(result);
    
    result = bitwiseOR(num1, num2);
    printf("Bitwise OR (Num1 | Num2): ");
    printBinary(result);
    
    result = bitwiseXOR(num1, num2);
    printf("Bitwise XOR (Num1 ^ Num2): ");
    printBinary(result);
    
    result = bitwiseNOT(num1);
    printf("Bitwise NOT (~Num1): ");
    printBinary(result);
    
    result = bitwiseNOT(num2);
    printf("Bitwise NOT (~Num2): ");
    printBinary(result);

    printf("\nShifts:\n");
    printf("Enter number of bits to shift left or right: ");
    scanf("%d", &shiftBits);
    
    result = leftShift(num1, shiftBits);
    printf("Left Shift (Num1 << %d): ", shiftBits);
    printBinary(result);
    
    result = rightShift(num1, shiftBits);
    printf("Right Shift (Num1 >> %d): ", shiftBits);
    printBinary(result);

    result = leftShift(num2, shiftBits);
    printf("Left Shift (Num2 << %d): ", shiftBits);
    printBinary(result);
    
    result = rightShift(num2, shiftBits);
    printf("Right Shift (Num2 >> %d): ", shiftBits);
    printBinary(result);

    printf("\nBits in common (AND): ");
    for (int i = 0; i < sizeof(num1) * 8; i++) {
        if ((num1 & (1 << i)) && (num2 & (1 << i))) {
            printf("%d ", i);
        }
    }
    printf("\n");

    printf("Morphism of Bitwise Operations between Num1 and Num2:\n");
    printf("Num1 with Num2 Masked by AND: ");
    printBinary(num1 & num2);
    
    printf("Num1 and Num2 Combined via OR: ");
    printBinary(num1 | num2);

    printf("\nFinal Thoughts:\n");
    printf("Understanding bitwise operations is crucial for efficient low-level programming.\n");
    printf("They are used in graphics, networking, and systems programming.\n");
    printf("Keep practicing these concepts to enhance your coding skills!\n");

    return 0;
}