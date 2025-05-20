//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayBits(unsigned int n);
void bitManipulation(unsigned int num1, unsigned int num2);
void toggleBit(unsigned int *num, int pos);
void setBit(unsigned int *num, int pos);
void clearBit(unsigned int *num, int pos);

int main() {
    unsigned int num1, num2, result;
    
    printf("Enter two unsigned integers:\n");
    scanf("%u %u", &num1, &num2);
    
    printf("Bitwise operations between %u and %u:\n", num1, num2);
    printf("Num1 in binary: ");
    displayBits(num1);
    
    printf("Num2 in binary: ");
    displayBits(num2);
    
    bitManipulation(num1, num2);
    
    // Additional demonstration of bit manipulation functions
    printf("\nDemonstrating bit manipulation functions:\n");
    printf("Original number 1: %u\n", num1);
    
    // Toggle the second bit (0-indexed)
    toggleBit(&num1, 1);
    printf("After toggling bit 1: %u\n", num1);
    
    // Set the 3rd bit
    setBit(&num1, 3);
    printf("After setting bit 3: %u\n", num1);
    
    // Clear the 2nd bit
    clearBit(&num1, 2);
    printf("After clearing bit 2: %u\n", num1);
    
    return 0;
}

void displayBits(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void bitManipulation(unsigned int num1, unsigned int num2) {
    unsigned int andResult = num1 & num2;
    unsigned int orResult = num1 | num2;
    unsigned int xorResult = num1 ^ num2;
    unsigned int notResult1 = ~num1;
    unsigned int notResult2 = ~num2;

    printf("AND operation (%u & %u): %u\n", num1, num2, andResult);
    printf("OR operation (%u | %u): %u\n", num1, num2, orResult);
    printf("XOR operation (%u ^ %u): %u\n", num1, num2, xorResult);
    printf("NOT operation (~%u): %u\n", num1, notResult1);
    printf("NOT operation (~%u): %u\n", num2, notResult2);
}

void toggleBit(unsigned int *num, int pos) {
    *num ^= (1 << pos);
}

void setBit(unsigned int *num, int pos) {
    *num |= (1 << pos);
}

void clearBit(unsigned int *num, int pos) {
    *num &= ~(1 << pos);
}