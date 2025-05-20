//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: multivariable
#include <stdio.h>

void printBinary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Space every 4 bits for readability
    }
}

void bitwiseOperations(int a, int b) {
    int andResult = a & b;
    int orResult = a | b;
    int xorResult = a ^ b;
    int notA = ~a;
    int notB = ~b;
    int leftShiftA = a << 1;  // Shift left by 1
    int leftShiftB = b << 1;  // Shift left by 1
    int rightShiftA = a >> 1; // Shift right by 1
    int rightShiftB = b >> 1; // Shift right by 1

    printf("Bitwise Operations:\n");
    printf("A = %d (%08X)  |  B = %d (%08X)\n", a, a, b, b);
    
    printf("AND Result: A & B = %d (%08X)\n", andResult, andResult);
    printf("OR Result: A | B = %d (%08X)\n", orResult, orResult);
    printf("XOR Result: A ^ B = %d (%08X)\n", xorResult, xorResult);
    printf("NOT A: ~A = %d (%08X)\n", notA, notA);
    printf("NOT B: ~B = %d (%08X)\n", notB, notB);
    printf("Left Shift A: A << 1 = %d (%08X)\n", leftShiftA, leftShiftA);
    printf("Left Shift B: B << 1 = %d (%08X)\n", leftShiftB, leftShiftB);
    printf("Right Shift A: A >> 1 = %d (%08X)\n", rightShiftA, rightShiftA);
    printf("Right Shift B: B >> 1 = %d (%08X)\n", rightShiftB, rightShiftB);
}

int main() {
    int x, y;
    printf("Enter two integer values:\n");
    printf("Value of x: ");
    scanf("%d", &x);
    printf("Value of y: ");
    scanf("%d", &y);

    printf("\nBinary representation:\n");
    printf("x in binary: ");
    printBinary(x);
    printf("\ny in binary: ");
    printBinary(y);

    bitwiseOperations(x, y);

    // Display bits for a range of operations to demonstrate flows
    printf("\nDemonstrating chaining of bitwise operations:\n");

    int flag = 0b101010; // Binary flag
    int mask = 0b010101; // Mask to manipulate the bits
    
    printf("Initial flag: %d (%08X)\n", flag, flag);
    printf("Mask: %d (%08X)\n", mask, mask);
    
    int newFlag = flag & mask; // And with mask
    printf("Flag after AND with Mask: %d (%08X)\n", newFlag, newFlag);
    
    newFlag = newFlag | 0b000011; // Add some bits
    printf("Flag after OR with '3': %d (%08X)\n", newFlag, newFlag);
    
    newFlag = newFlag ^ 0b111111; // Toggle all bits
    printf("Flag after XOR with '63': %d (%08X)\n", newFlag, newFlag);
    
    newFlag = ~newFlag; // NOT operation
    printf("Flag after NOT: %d (%08X)\n", newFlag, newFlag);
    
    newFlag = newFlag << 2; // Left shift
    printf("Flag after left shift by 2: %d (%08X)\n", newFlag, newFlag);
    
    newFlag = newFlag >> 1; // Right shift
    printf("Flag after right shift by 1: %d (%08X)\n", newFlag, newFlag);

    return 0;
}