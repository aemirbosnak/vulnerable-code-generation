//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: modular
#include <stdio.h>

// Function prototypes
void printBinary(unsigned int num);
unsigned int bitwiseAND(unsigned int a, unsigned int b);
unsigned int bitwiseOR(unsigned int a, unsigned int b);
unsigned int bitwiseXOR(unsigned int a, unsigned int b);
unsigned int bitwiseNOT(unsigned int num);
unsigned int leftShift(unsigned int num, int positions);
unsigned int rightShift(unsigned int num, int positions);

int main() {
    unsigned int a, b;
    int positions;

    printf("Enter first unsigned integer: ");
    scanf("%u", &a);
    printf("Enter second unsigned integer: ");
    scanf("%u", &b);
    
    printf("\nBitwise Operations:\n");
    printf("a: ");
    printBinary(a);
    printf("b: ");
    printBinary(b);

    // Bitwise AND
    unsigned int andResult = bitwiseAND(a, b);
    printf("\na & b: ");
    printBinary(andResult);

    // Bitwise OR
    unsigned int orResult = bitwiseOR(a, b);
    printf("\na | b: ");
    printBinary(orResult);

    // Bitwise XOR
    unsigned int xorResult = bitwiseXOR(a, b);
    printf("\na ^ b: ");
    printBinary(xorResult);

    // Bitwise NOT
    unsigned int notResult = bitwiseNOT(a);
    printf("\n~a: ");
    printBinary(notResult);
    
    // Left Shift
    printf("\nEnter number of positions to left shift: ");
    scanf("%d", &positions);
    unsigned int leftShiftResult = leftShift(a, positions);
    printf("\na << %d: ", positions);
    printBinary(leftShiftResult);
    
    // Right Shift
    printf("\nEnter number of positions to right shift: ");
    scanf("%d", &positions);
    unsigned int rightShiftResult = rightShift(a, positions);
    printf("\na >> %d: ", positions);
    printBinary(rightShiftResult);
    
    return 0;
}

// Function to print binary representation
void printBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit);
    }
    printf(" (%u)\n", num);
}

// Function for bitwise AND
unsigned int bitwiseAND(unsigned int a, unsigned int b) {
    return a & b;
}

// Function for bitwise OR
unsigned int bitwiseOR(unsigned int a, unsigned int b) {
    return a | b;
}

// Function for bitwise XOR
unsigned int bitwiseXOR(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function for bitwise NOT
unsigned int bitwiseNOT(unsigned int num) {
    return ~num;
}

// Function for left shift
unsigned int leftShift(unsigned int num, int positions) {
    return num << positions;
}

// Function for right shift
unsigned int rightShift(unsigned int num, int positions) {
    return num >> positions;
}