//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: visionary
// A Cosmic Odyssey of Bitwise Dimensions

#include <stdio.h>

// Macro-dimensions for binary manipulation
#define BITMASK(bit) (1 << (bit))
#define BITCHECK(num, bit) ((num) & BITMASK(bit))
#define BITSET(num, bit) ((num) |= BITMASK(bit))
#define BITCLEAR(num, bit) ((num) &= ~BITMASK(bit))
#define BITFLIP(num, bit) ((num) ^= BITMASK(bit))

// A celestial dance of bitwise wonders
void bitwise_cosmos(int num) {
    printf("Binary Genesis: %d\n", num);

    // Unmasking the hidden realms (Bit Checking)
    for (int bit = 0; bit < 32; bit++) {
        if (BITCHECK(num, bit)) {
            printf("Bit %d: Awakened from slumber\n", bit);
        } else {
            printf("Bit %d: Resting in the void\n", bit);
        }
    }

    // Celestial Transformation (Bitwise Operations)
    printf("\nBitwise Metamorphosis:\n");

    // Setting a cosmic beacon (Bit Setting)
    int set_bit = 5;
    printf("Setting bit %d\n", set_bit);
    num = BITSET(num, set_bit);
    printf("Binary newState: %d\n", num);

    // Extinguishing a stellar flame (Bit Clearing)
    int clear_bit = 2;
    printf("Clearing bit %d\n", clear_bit);
    num = BITCLEAR(num, clear_bit);
    printf("Binary newState: %d\n", num);

    // Inverting the cosmic balance (Bit Flipping)
    int flip_bit = 7;
    printf("Flipping bit %d\n", flip_bit);
    num = BITFLIP(num, flip_bit);
    printf("Binary newState: %d\n", num);
}

int main() {
    // The celestial tapestry of bitwise wonders
    printf("Welcome to the Bitwise Cosmos!\n");

    // Summoning the cosmic entity
    int celestial_number = 0b10101100;

    printf("\nOriginal Entity: %d\n", celestial_number);

    // Embarking on the bitwise odyssey
    bitwise_cosmos(celestial_number);

    return 0;
}