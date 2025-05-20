//FormAI DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdint.h>

uint32_t setBit(uint32_t n, int pos) {
    // This function sets bit at position pos to 1
    return n | (1 << pos);
}

uint32_t clearBit(uint32_t n, int pos) {
    // This function sets bit at position pos to 0
    return n & (~(1 << pos));
}

int getBit(uint32_t n, int pos) {
    // This function returns the value of bit at position pos
    return ((n & (1 << pos)) != 0);
}

uint32_t updateBit(uint32_t n, int pos, int val) {
    // This function updates bit at position pos with value val
    uint32_t mask = ~(1 << pos);
    return (n & mask) | (val << pos);
}

int main() {
    // Declare a variable to store the number
    uint32_t num = 0xABCDEF12;
  
    // Set the bit at position 4 to 1
    num = setBit(num, 4);
    printf("Bit at position 4 set: 0x%X\n", num);

    // Clear the bit at position 7
    num = clearBit(num, 7);
    printf("Bit at position 7 cleared: 0x%X\n", num);
    
    // Get the value of bit at position 10
    int bitVal = getBit(num, 10);
    printf("Value of bit at position 10: %d\n", bitVal);

    // Update the bit at position 15 with value 1
    num = updateBit(num, 15, 1);
    printf("Bit at position 15 updated: 0x%X\n", num);

    // Update the bit at position 31 with value 0
    num = updateBit(num, 31, 0);
    printf("Bit at position 31 updated: 0x%X\n", num);

    return 0;
}