//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to hold the binary number and its decimal equivalent
struct binary_number {
    uint8_t binary[8];
    int decimal;
};

// Function to convert binary to decimal
struct binary_number binary_to_decimal(uint8_t binary[8]) {
    struct binary_number result;
    int i;

    // Initialize result.binary with the input binary array
    for (i = 0; i < 8; i++) {
        result.binary[i] = binary[i];
    }

    // Calculate the decimal equivalent
    for (i = 0; i < 8; i++) {
        result.decimal += (result.binary[i] - '0') * (1 << (7 - i));
    }

    return result;
}

// Function to convert decimal to binary
struct binary_number decimal_to_binary(int decimal) {
    struct binary_number result;
    int i;

    // Initialize result.binary with a zero array
    for (i = 0; i < 8; i++) {
        result.binary[i] = '0';
    }

    // Calculate the binary equivalent
    while (decimal > 0) {
        result.binary[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }

    return result;
}

int main() {
    // Example usage of the functions
    uint8_t binary[8] = {1, 0, 1, 1, 0, 1, 1, 1};
    struct binary_number bin = binary_to_decimal(binary);
    printf("Decimal: %d\n", bin.decimal);

    struct binary_number dec = decimal_to_binary(12);
    uint8_t binary_result[8];
    for (int i = 0; i < 8; i++) {
        binary_result[i] = dec.binary[i];
    }
    printf("Binary: %s\n", binary_result);

    return 0;
}