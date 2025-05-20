//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>

void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        putchar((n & (1 << i)) ? '1' : '0');
        if (i % 4 == 0) {
            putchar(' '); // for better readability
        }
    }
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

int main() {
    unsigned int num1, num2;
    int shiftPositions;

    printf("Welcome to the Bitwise Operations Explorer!\n");
    printf("Let's investigate how bitwise operations work in C.\n\n");

    printf("Enter the first number (unsigned integer): ");
    scanf("%u", &num1);
    printf("Enter the second number (unsigned integer): ");
    scanf("%u", &num2);
    
    printf("\nLet's see the binary representation:\n");
    printf("First number (%u): ", num1);
    printBinary(num1);
    printf("\nSecond number (%u): ", num2);
    printBinary(num2);
    
    printf("\n\nBitwise AND: %u\n", bitwiseAND(num1, num2));
    printf("Binary: ");
    printBinary(bitwiseAND(num1, num2));
    
    printf("\nBitwise OR: %u\n", bitwiseOR(num1, num2));
    printf("Binary: ");
    printBinary(bitwiseOR(num1, num2));
    
    printf("\nBitwise XOR: %u\n", bitwiseXOR(num1, num2));
    printf("Binary: ");
    printBinary(bitwiseXOR(num1, num2));
    
    printf("\nBitwise NOT of the first number: %u\n", bitwiseNOT(num1));
    printf("Binary: ");
    printBinary(bitwiseNOT(num1));
    
    printf("Bitwise NOT of the second number: %u\n", bitwiseNOT(num2));
    printf("Binary: ");
    printBinary(bitwiseNOT(num2));
    
    printf("\nNow, let's explore shifting!\n");
    printf("How many positions do you want to shift? ");
    scanf("%d", &shiftPositions);
    
    printf("\nLeft shift of first number (%u): %u\n", num1, leftShift(num1, shiftPositions));
    printf("Binary: ");
    printBinary(leftShift(num1, shiftPositions));

    printf("\nRight shift of first number (%u): %u\n", num1, rightShift(num1, shiftPositions));
    printf("Binary: ");
    printBinary(rightShift(num1, shiftPositions));
    
    printf("\nLeft shift of second number (%u): %u\n", num2, leftShift(num2, shiftPositions));
    printf("Binary: ");
    printBinary(leftShift(num2, shiftPositions));

    printf("\nRight shift of second number (%u): %u\n", num2, rightShift(num2, shiftPositions));
    printf("Binary: ");
    printBinary(rightShift(num2, shiftPositions));

    printf("\n\nThanks for exploring bitwise operations with me! Enjoy coding!\n");
    
    return 0;
}