//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

// Define the maximum number of digits in the binary representation.
#define MAX_DIGITS 32

// Define the base of the binary number system.
#define BASE 2

// Define the number of bits in a byte.
#define BITS_PER_BYTE 8

// Convert a decimal number to its binary representation.
uint8_t* decimal_to_binary(uint32_t decimal) {
    // Allocate memory for the binary representation.
    uint8_t* binary = malloc(MAX_DIGITS / BITS_PER_BYTE);

    // Initialize the binary representation to 0.
    for (int i = 0; i < MAX_DIGITS / BITS_PER_BYTE; i++) {
        binary[i] = 0;
    }

    // Convert the decimal number to its binary representation.
    int index = 0;
    while (decimal > 0) {
        binary[index++] = decimal % BASE;
        decimal /= BASE;
    }

    // Return the binary representation.
    return binary;
}

// Print the binary representation of a number.
void print_binary(uint8_t* binary) {
    // Print the binary representation in reverse order.
    for (int i = MAX_DIGITS / BITS_PER_BYTE - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    // Print a newline character.
    printf("\n");
}

// Main function.
int main(void) {
    // Get the decimal number from the user.
    printf("Enter a decimal number: ");
    uint32_t decimal;
    scanf("%u", &decimal);

    // Convert the decimal number to its binary representation.
    uint8_t* binary = decimal_to_binary(decimal);

    // Print the binary representation of the number.
    printf("The binary representation of %u is: ", decimal);
    print_binary(binary);

    // Free the memory allocated for the binary representation.
    free(binary);

    return 0;
}