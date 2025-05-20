//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: satisfied
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Define the maximum number of bytes to convert
#define MAX_BYTES 1024

// Define the base and destination types
typedef enum {
    BASE_DECIMAL = 10,
    BASE_HEXADECIMAL = 16,
    BASE_OCTAL = 8,
    BASE_BINARY = 2
} base_t;

// Define the conversion functions
void decimal_to_binary(uint8_t *binary, uint32_t decimal) {
    uint32_t remainder = decimal % 2;
    binary[0] = remainder + '0';
    decimal /= 2;
    for (int i = 1; i < 32; i++) {
        remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
    }
}

void hexadecimal_to_binary(uint8_t *binary, uint32_t hexadecimal) {
    uint32_t remainder = hexadecimal % 16;
    binary[0] = remainder + '0';
    hexadecimal /= 16;
    for (int i = 1; i < 32; i++) {
        remainder = hexadecimal % 16;
        binary[i] = remainder + '0';
        hexadecimal /= 16;
    }
}

void octal_to_binary(uint8_t *binary, uint32_t octal) {
    uint32_t remainder = octal % 8;
    binary[0] = remainder + '0';
    octal /= 8;
    for (int i = 1; i < 32; i++) {
        remainder = octal % 8;
        binary[i] = remainder + '0';
        octal /= 8;
    }
}

void binary_to_decimal(uint8_t *binary, uint32_t *decimal) {
    *decimal = 0;
    for (int i = 0; i < 32; i++) {
        *decimal *= 2;
        *decimal += binary[i] - '0';
    }
}

void binary_to_hexadecimal(uint8_t *binary, uint32_t *hexadecimal) {
    *hexadecimal = 0;
    for (int i = 0; i < 32; i++) {
        *hexadecimal *= 16;
        *hexadecimal += binary[i] - '0';
    }
}

int main() {
    // Define the input and output buffers
    uint8_t binary[MAX_BYTES];
    uint32_t decimal, hexadecimal;

    // Ask the user for the input
    printf("Enter a decimal number: ");
    scanf("%lu", &decimal);

    // Convert the decimal number to binary
    decimal_to_binary(binary, decimal);

    // Print the binary representation
    printf("Binary: %s\n", binary);

    // Ask the user if they want to convert to hexadecimal
    printf("Do you want to convert to hexadecimal? (y/n): ");
    char input;
    scanf(" %c", &input);

    // Convert the binary to hexadecimal if requested
    if (input == 'y') {
        hexadecimal_to_binary(binary, decimal);
        printf("Hexadecimal: %s\n", binary);
    }

    // Ask the user if they want to convert to octal
    printf("Do you want to convert to octal? (y/n): ");
    char input2;
    scanf(" %c", &input2);

    // Convert the binary to octal if requested
    if (input2 == 'y') {
        octal_to_binary(binary, decimal);
        printf("Octal: %s\n", binary);
    }

    // Ask the user if they want to convert back to decimal
    printf("Do you want to convert back to decimal? (y/n): ");
    char input3;
    scanf(" %c", &input3);

    // Convert the binary back to decimal if requested
    if (input3 == 'y') {
        binary_to_decimal(binary, &decimal);
        printf("Decimal: %lu\n", decimal);
    }

    return 0;
}