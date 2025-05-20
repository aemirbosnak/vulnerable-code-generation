//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define BINARY_WIDTH 8
#define BINARY_CHAR '0'

typedef struct {
    uint8_t num_digits;
    uint8_t digits[BINARY_WIDTH];
} binary_t;

binary_t bin_from_dec(uint32_t dec) {
    binary_t bin;
    bin.num_digits = 0;
    while (dec > 0) {
        bin.digits[bin.num_digits] = dec % 2 ? BINARY_CHAR : '1';
        dec /= 2;
        bin.num_digits++;
    }
    return bin;
}

uint32_t dec_from_bin(binary_t bin) {
    uint32_t dec = 0;
    for (int i = 0; i < bin.num_digits; i++) {
        dec *= 2;
        dec += (bin.digits[i] - '0') << (BINARY_WIDTH - i - 1);
    }
    return dec;
}

int main() {
    binary_t bin;
    uint32_t dec;

    // Example usage:
    bin = bin_from_dec(123);
    printf("Binary: %s\n", bin.digits);
    dec = dec_from_bin(bin);
    printf("Decimal: %d\n", dec);

    // Test cases:
    bin = bin_from_dec(456);
    printf("Binary: %s\n", bin.digits);
    dec = dec_from_bin(bin);
    printf("Decimal: %d\n", dec);

    bin = bin_from_dec(101010);
    printf("Binary: %s\n", bin.digits);
    dec = dec_from_bin(bin);
    printf("Decimal: %d\n", dec);

    return 0;
}