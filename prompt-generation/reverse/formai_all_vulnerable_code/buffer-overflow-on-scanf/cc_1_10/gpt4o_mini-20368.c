//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include <stdio.h>

// Function to display binary representation of an integer
void printBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        putchar((num & (1U << i)) ? '1' : '0');
    }
    putchar('\n');
}

// Function to set a specific bit
unsigned int setBit(unsigned int num, int bitPosition) {
    return num | (1U << bitPosition);
}

// Function to clear a specific bit
unsigned int clearBit(unsigned int num, int bitPosition) {
    return num & ~(1U << bitPosition);
}

// Function to toggle a specific bit
unsigned int toggleBit(unsigned int num, int bitPosition) {
    return num ^ (1U << bitPosition);
}

// Function to check if a specific bit is set
int isBitSet(unsigned int num, int bitPosition) {
    return (num & (1U << bitPosition)) != 0;
}

// Function to count the number of set bits (Hamming Weight)
int countSetBits(unsigned int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to reverse the bits of an integer
unsigned int reverseBits(unsigned int num) {
    unsigned int reversed = 0;
    for (int i = 0; i < sizeof(num) * 8; i++) {
        reversed <<= 1;
        reversed |= (num & 1);
        num >>= 1;
    }
    return reversed;
}

int main() {
    unsigned int number = 0, bitPosition;

    printf("Enter a number (unsigned integer): ");
    scanf("%u", &number);

    printf("Original number in binary: ");
    printBinary(number);
    
    // Setting a bit example
    printf("Enter bit position to set (0-31): ");
    scanf("%u", &bitPosition);
    number = setBit(number, bitPosition);
    printf("After setting bit %u: ", bitPosition);
    printBinary(number);
    
    // Clearing a bit example
    printf("Enter bit position to clear (0-31): ");
    scanf("%u", &bitPosition);
    number = clearBit(number, bitPosition);
    printf("After clearing bit %u: ", bitPosition);
    printBinary(number);
    
    // Toggling a bit example
    printf("Enter bit position to toggle (0-31): ");
    scanf("%u", &bitPosition);
    number = toggleBit(number, bitPosition);
    printf("After toggling bit %u: ", bitPosition);
    printBinary(number);
    
    // Checking if a bit is set
    printf("Enter bit position to check (0-31): ");
    scanf("%u", &bitPosition);
    printf("Is bit %u set? %s\n", bitPosition, isBitSet(number, bitPosition) ? "Yes" : "No");
    
    // Counting set bits
    int count = countSetBits(number);
    printf("Number of set bits: %d\n", count);
    
    // Reversing bits
    unsigned int reversed = reverseBits(number);
    printf("Reversed number in binary: ");
    printBinary(reversed);

    // Final output of all operations
    printf("Final modified number: %u\n", number);
    printf("Final reversed number: %u\n", reversed);
    
    return 0;
}