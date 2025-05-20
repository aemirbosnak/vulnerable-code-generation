//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define BITS 8
#define MAX_VALUE ((1 << BITS) - 1)
#define MIN_VALUE 0

void set_bit(int *value, int bit) {
    *value |= (1 << bit);
}

void clear_bit(int *value, int bit) {
    *value &= ~(1 << bit);
}

void toggle_bit(int *value, int bit) {
    *value ^= (1 << bit);
}

int get_bit(int value, int bit) {
    return (value >> bit) & 1;
}

int count_bits(int value) {
    int count = 0;
    while (value > 0) {
        count += (value & 1);
        value >>= 1;
    }
    return count;
}

int main() {
    int value = 0;

    printf("Enter a value (0-255): ");
    scanf("%d", &value);

    if (value < MIN_VALUE || value > MAX_VALUE) {
        printf("Invalid input.\n");
        return 1;
    }

    int bit_position = 0;
    printf("Enter the bit position: ");
    scanf("%d", &bit_position);

    if (bit_position < 0 || bit_position >= BITS) {
        printf("Invalid bit position.\n");
        return 1;
    }

    set_bit(&value, bit_position);
    printf("Value after setting bit: %d\n", value);

    clear_bit(&value, bit_position);
    printf("Value after clearing bit: %d\n", value);

    toggle_bit(&value, bit_position);
    printf("Value after toggling bit: %d\n", value);

    int bit_value = get_bit(value, bit_position);
    printf("Bit value at position %d: %d\n", bit_position, bit_value);

    int num_bits = count_bits(value);
    printf("Number of set bits: %d\n", num_bits);

    return 0;
}