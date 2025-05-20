//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: systematic
#include <stdio.h>

void printBinary(int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
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

int leftShift(int a, int shift) {
    return a << shift;
}

int rightShift(int a, int shift) {
    return a >> shift;
}

int main() {
    int num1, num2, shiftAmount;
    
    printf("Enter two integers:\n");
    printf("Integer 1: ");
    scanf("%d", &num1);
    printf("Integer 2: ");
    scanf("%d", &num2);
    
    printf("\n--- Bitwise Operations ---\n");
    
    printf("Number 1: ");
    printBinary(num1);
    printf("Number 2: ");
    printBinary(num2);
    
    printf("\nBitwise AND (num1 & num2): ");
    int andResult = bitwiseAND(num1, num2);
    printBinary(andResult);
    
    printf("Bitwise OR (num1 | num2): ");
    int orResult = bitwiseOR(num1, num2);
    printBinary(orResult);
    
    printf("Bitwise XOR (num1 ^ num2): ");
    int xorResult = bitwiseXOR(num1, num2);
    printBinary(xorResult);
    
    printf("Bitwise NOT (~num1): ");
    int notResultA = bitwiseNOT(num1);
    printBinary(notResultA);
    
    printf("Bitwise NOT (~num2): ");
    int notResultB = bitwiseNOT(num2);
    printBinary(notResultB);
    
    printf("Enter number of bits to shift: ");
    scanf("%d", &shiftAmount);
    
    printf("Left Shift (num1 << %d): ", shiftAmount);
    int leftShiftResult = leftShift(num1, shiftAmount);
    printBinary(leftShiftResult);
    
    printf("Right Shift (num1 >> %d): ", shiftAmount);
    int rightShiftResult = rightShift(num1, shiftAmount);
    printBinary(rightShiftResult);
    
    printf("Left Shift (num2 << %d): ", shiftAmount);
    leftShiftResult = leftShift(num2, shiftAmount);
    printBinary(leftShiftResult);
    
    printf("Right Shift (num2 >> %d): ", shiftAmount);
    rightShiftResult = rightShift(num2, shiftAmount);
    printBinary(rightShiftResult);
    
    return 0;
}