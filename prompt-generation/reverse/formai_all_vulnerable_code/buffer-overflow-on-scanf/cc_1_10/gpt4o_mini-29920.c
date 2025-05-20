//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: high level of detail
#include <stdio.h>

// Define constants for bit operations
#define BIT_LENGTH 8

// Function to display binary representation of a number
void printBinary(unsigned int num) {
    for (int i = BIT_LENGTH - 1; i >= 0; i--) {
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit);
    }
}

// Function to set a specific bit
unsigned int setBit(unsigned int num, int bitPosition) {
    return num | (1 << bitPosition);
}

// Function to clear a specific bit
unsigned int clearBit(unsigned int num, int bitPosition) {
    return num & ~(1 << bitPosition);
}

// Function to toggle a specific bit
unsigned int toggleBit(unsigned int num, int bitPosition) {
    return num ^ (1 << bitPosition);
}

// Function to check if a specific bit is set
int isBitSet(unsigned int num, int bitPosition) {
    return (num >> bitPosition) & 1;
}

// Function to count the number of set bits
int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to perform bitwise AND operation
unsigned int bitwiseAnd(unsigned int a, unsigned int b) {
    return a & b;
}

// Function to perform bitwise OR operation
unsigned int bitwiseOr(unsigned int a, unsigned int b) {
    return a | b;
}

// Function to perform bitwise XOR operation
unsigned int bitwiseXor(unsigned int a, unsigned int b) {
    return a ^ b;
}

// Function to demonstrate bitwise operations
void bitwiseOperationsDemo() {
    unsigned int num1, num2;

    printf("Enter two integers (in decimal): ");
    scanf("%u %u", &num1, &num2);

    printf("\nBitwise Operations on %u and %u:\n", num1, num2);
    
    printf("Binary Representation:\n");
    printf("Num1: ");
    printBinary(num1);
    printf("\nNum2: ");
    printBinary(num2);
    
    printf("\nBitwise AND: %u\n", bitwiseAnd(num1, num2));
    printf("Binary: ");
    printBinary(bitwiseAnd(num1, num2));

    printf("\nBitwise OR: %u\n", bitwiseOr(num1, num2));
    printf("Binary: ");
    printBinary(bitwiseOr(num1, num2));

    printf("\nBitwise XOR: %u\n", bitwiseXor(num1, num2));
    printf("Binary: ");
    printBinary(bitwiseXor(num1, num2));

    // Setting bit
    int bitToSet;
    printf("\nEnter bit position (0-7) to set in num1: ");
    scanf("%d", &bitToSet);
    num1 = setBit(num1, bitToSet);
    printf("Num1 after setting bit %d: %u\n", bitToSet, num1);
    printf("Binary: ");
    printBinary(num1);

    // Clearing bit
    int bitToClear;
    printf("\nEnter bit position (0-7) to clear in num1: ");
    scanf("%d", &bitToClear);
    num1 = clearBit(num1, bitToClear);
    printf("Num1 after clearing bit %d: %u\n", bitToClear, num1);
    printf("Binary: ");
    printBinary(num1);

    // Toggling bit
    int bitToToggle;
    printf("\nEnter bit position (0-7) to toggle in num1: ");
    scanf("%d", &bitToToggle);
    num1 = toggleBit(num1, bitToToggle);
    printf("Num1 after toggling bit %d: %u\n", bitToToggle, num1);
    printf("Binary: ");
    printBinary(num1);

    // Check if bit is set
    int bitToCheck;
    printf("\nEnter bit position (0-7) to check if set in num1: ");
    scanf("%d", &bitToCheck);
    if (isBitSet(num1, bitToCheck)) {
        printf("Bit %d is set in num1.\n", bitToCheck);
    } else {
        printf("Bit %d is NOT set in num1.\n", bitToCheck);
    }

    // Count set bits
    int setBitsCount = countSetBits(num1);
    printf("Total set bits in num1: %d\n", setBitsCount);
}

int main() {
    bitwiseOperationsDemo();
    return 0;
}