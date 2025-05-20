//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is a power of 2
int isPowerOfTwo(int num) {
    if (num <= 0)
        return 0;
    return (num & (num - 1)) == 0;
}

// Function to count the number of set bits in a given number
int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

// Function to reverse the bits of a given number
int reverseBits(int num) {
    int reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed |= (num & (1 << i)) << (31 - i);
    }
    return reversed;
}

// Function to set a specific bit in a given number
int setBit(int num, int position) {
    return num | (1 << position);
}

// Function to clear a specific bit in a given number
int clearBit(int num, int position) {
    return num & ~(1 << position);
}

// Function to toggle a specific bit in a given number
int toggleBit(int num, int position) {
    return num ^ (1 << position);
}

int main() {
    int num = 0b10101010101010101010101010101010;
    int pos = 3;

    // Check if the number is a power of 2
    printf("Is %d a power of 2? %s\n", num, isPowerOfTwo(num)? "Yes" : "No");

    // Count the number of set bits in the number
    printf("Number of set bits in %d: %d\n", num, countSetBits(num));

    // Reverse the bits of the number
    printf("Reversed bits of %d: %d\n", num, reverseBits(num));

    // Set a specific bit in the number
    printf("Setting bit %d in %d: %d\n", pos, num, setBit(num, pos));

    // Clear a specific bit in the number
    printf("Clearing bit %d in %d: %d\n", pos, num, clearBit(num, pos));

    // Toggle a specific bit in the number
    printf("Toggling bit %d in %d: %d\n", pos, num, toggleBit(num, pos));

    return 0;
}