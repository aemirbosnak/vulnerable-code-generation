//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int a = 0x12345678;
    unsigned int b = 0x97531aec;
    unsigned int c = 0x89abcdef;

    // Bitwise AND
    printf("Bitwise AND (a & b): %x\n", a & b);

    // Bitwise OR
    printf("Bitwise OR (a | b): %x\n", a | b);

    // Bitwise XOR
    printf("Bitwise XOR (a ^ b): %x\n", a ^ b);

    // Bitwise NOT
    printf("Bitwise NOT (~a): %x\n", ~a);

    // Bitwise left shift
    printf("Bitwise left shift (a << 2): %x\n", a << 2);

    // Bitwise right shift
    printf("Bitwise right shift (a >> 2): %x\n", a >> 2);

    // Bitwise rotate left
    printf("Bitwise rotate left (a << 2 | a >> (32 - 2)): %x\n", a << 2 | a >> (32 - 2));

    // Bitwise rotate right
    printf("Bitwise rotate right (a >> 2 | a << (32 - 2)): %x\n", a >> 2 | a << (32 - 2));

    // Check if a bit is set
    printf("Is bit 0 in a set? (a & 1): %d\n", a & 1);

    // Set a bit
    a |= 1;
    printf("Set bit 0 in a: %x\n", a);

    // Clear a bit
    a &= ~1;
    printf("Clear bit 0 in a: %x\n", a);

    // Toggle a bit
    a ^= 1;
    printf("Toggle bit 0 in a: %x\n", a);

    // Count number of set bits
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i)) {
            count++;
        }
    }
    printf("Number of set bits in a: %d\n", count);

    // Find the position of the least significant set bit
    int lsb = 0;
    while (!(a & (1 << lsb))) {
        lsb++;
    }
    printf("Position of the least significant set bit in a: %d\n", lsb);

    // Find the position of the most significant set bit
    int msb = 31;
    while (!(a & (1 << msb))) {
        msb--;
    }
    printf("Position of the most significant set bit in a: %d\n", msb);

    // Extract a field of bits
    unsigned int field = (a & ((1 << 8) - 1)) << 4;
    printf("Extracted field from a: %x\n", field);

    // Insert a field of bits
    a = (a & ~((1 << 8) - 1)) | (field >> 4);
    printf("Inserted field into a: %x\n", a);

    // Reverse the order of bits in a
    unsigned int reversed = 0;
    for (int i = 0; i < 32; i++) {
        if (a & (1 << i)) {
            reversed |= 1 << (31 - i);
        }
    }
    printf("Reversed order of bits in a: %x\n", reversed);

    return 0;
}