//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 16 // Number of bits to demonstrate bitwise operations

// Function declarations
void printBits(int n);
int setBit(int n, int pos);
int clearBit(int n, int pos);
int toggleBit(int n, int pos);
int checkBit(int n, int pos);
int countSetBits(int n);
int getTwoComplement(int n);

int main() {
    int num, pos;
    
    // Input a number from the user
    printf("Enter a number (in decimal): ");
    scanf("%d", &num);
    
    // Display the original number in binary
    printf("Original number in binary: ");
    printBits(num);

    // Example of setting a bit
    printf("\nEnter the bit position to set (0-%d): ", MAX_SIZE - 1);
    scanf("%d", &pos);
    num = setBit(num, pos);
    printf("After setting bit at position %d: ", pos);
    printBits(num);
    
    // Example of clearing a bit
    printf("\nEnter the bit position to clear (0-%d): ", MAX_SIZE - 1);
    scanf("%d", &pos);
    num = clearBit(num, pos);
    printf("After clearing bit at position %d: ", pos);
    printBits(num);
    
    // Example of toggling a bit
    printf("\nEnter the bit position to toggle (0-%d): ", MAX_SIZE - 1);
    scanf("%d", &pos);
    num = toggleBit(num, pos);
    printf("After toggling bit at position %d: ", pos);
    printBits(num);

    // Example of checking a bit
    printf("\nEnter the bit position to check (0-%d): ", MAX_SIZE - 1);
    scanf("%d", &pos);
    if (checkBit(num, pos)) {
        printf("Bit at position %d is set.\n", pos);
    } else {
        printf("Bit at position %d is not set.\n", pos);
    }

    // Count how many bits are set
    int setBitsCount = countSetBits(num);
    printf("Total set bits in the number: %d\n", setBitsCount);

    // Get the two's complement of the number
    int twoComplement = getTwoComplement(num);
    printf("Two's complement of the number: ");
    printBits(twoComplement);
    
    return 0;
}

// Function to print bits of a number
void printBits(int n) {
    for (int i = MAX_SIZE - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

// Function to set a bit at a given position
int setBit(int n, int pos) {
    return n | (1 << pos);
}

// Function to clear a bit at a given position
int clearBit(int n, int pos) {
    return n & ~(1 << pos);
}

// Function to toggle a bit at a given position
int toggleBit(int n, int pos) {
    return n ^ (1 << pos);
}

// Function to check if a bit at a given position is set
int checkBit(int n, int pos) {
    return (n >> pos) & 1;
}

// Function to count the number of set bits
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to get the two's complement of a number
int getTwoComplement(int n) {
    return ~n + 1;
}