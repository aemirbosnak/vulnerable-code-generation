//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: expert-level
#include <stdio.h>
#include <stdint.h>

// Function prototypes
void printBinary(unsigned int n);
unsigned int setBit(unsigned int n, unsigned int k);
unsigned int clearBit(unsigned int n, unsigned int k);
unsigned int toggleBit(unsigned int n, unsigned int k);
unsigned int countSetBits(unsigned int n);
unsigned int isPowerOfTwo(unsigned int n);

int main() {
    unsigned int num = 0;
    unsigned int bitIndex = 0;
    
    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Binary representation of %u: ", num);
    printBinary(num);

    printf("Enter the bit index to set (0-31): ");
    scanf("%u", &bitIndex);
    num = setBit(num, bitIndex);
    printf("After setting bit %u, new value: %u\n", bitIndex, num);
    printBinary(num);

    printf("Enter the bit index to clear (0-31): ");
    scanf("%u", &bitIndex);
    num = clearBit(num, bitIndex);
    printf("After clearing bit %u, new value: %u\n", bitIndex, num);
    printBinary(num);

    printf("Enter the bit index to toggle (0-31): ");
    scanf("%u", &bitIndex);
    num = toggleBit(num, bitIndex);
    printf("After toggling bit %u, new value: %u\n", bitIndex, num);
    printBinary(num);

    printf("The number of set bits in %u is: %u\n", num, countSetBits(num));

    if (isPowerOfTwo(num))
        printf("%u is a power of two.\n", num);
    else
        printf("%u is not a power of two.\n", num);

    return 0;
}

void printBinary(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        unsigned int bit = (n >> i) & 1;
        printf("%u", bit);
        if (i % 4 == 0) {
            printf(" ");  // Insert space for readability
        }
    }
    printf("\n");
}

unsigned int setBit(unsigned int n, unsigned int k) {
    return n | (1 << k);
}

unsigned int clearBit(unsigned int n, unsigned int k) {
    return n & ~(1 << k);
}

unsigned int toggleBit(unsigned int n, unsigned int k) {
    return n ^ (1 << k);
}

unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1; // Add the least significant bit
        n >>= 1;        // Shift right to process the next bit
    }
    return count;
}

unsigned int isPowerOfTwo(unsigned int n) {
    if (n == 0) return 0; // 0 is not a power of two
    return (n & (n - 1)) == 0; // Check if there's only one bit set
}