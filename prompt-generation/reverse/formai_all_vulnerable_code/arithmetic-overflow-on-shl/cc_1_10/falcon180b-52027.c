//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_BITS 32

typedef struct {
    unsigned int num_bits;
    unsigned int num_ones;
} BitField;

// Function to initialize a bit field
void init_bitfield(BitField* bf, unsigned int num_bits) {
    bf->num_bits = num_bits;
    bf->num_ones = 0;
}

// Function to set a bit in a bit field
void set_bit(BitField* bf, unsigned int bit_pos) {
    if (bit_pos >= bf->num_bits) {
        printf("Error: Bit position out of range.\n");
        exit(1);
    }
    bf->num_ones++;
}

// Function to check if a bit is set in a bit field
int is_bit_set(BitField* bf, unsigned int bit_pos) {
    if (bit_pos >= bf->num_bits) {
        printf("Error: Bit position out of range.\n");
        exit(1);
    }
    return (bf->num_ones & (1 << bit_pos))!= 0;
}

// Function to count the number of set bits in a bit field
int count_bits(BitField* bf) {
    return bf->num_ones;
}

// Function to print the contents of a bit field
void print_bitfield(BitField* bf) {
    printf("Bit field (%d bits):\n", bf->num_bits);
    for (int i = 0; i < bf->num_bits; i++) {
        if (is_bit_set(bf, i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\nNumber of set bits: %d\n", count_bits(bf));
}

// Function to generate a random bit field with a given number of set bits
void generate_random_bitfield(BitField* bf, unsigned int num_set_bits) {
    init_bitfield(bf, MAX_NUM_BITS);
    srand(time(NULL));
    for (int i = 0; i < num_set_bits; i++) {
        int bit_pos = rand() % bf->num_bits;
        set_bit(bf, bit_pos);
    }
}

int main() {
    BitField bf;
    generate_random_bitfield(&bf, 10);
    print_bitfield(&bf);
    return 0;
}