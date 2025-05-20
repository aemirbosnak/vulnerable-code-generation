//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 32
#define MAX_OUTPUT_SIZE 32

// Structure to store binary, decimal, and hexadecimal representations of a number
typedef struct {
    uint8_t binary[MAX_INPUT_SIZE];
    int decimal;
    uint16_t hexadecimal;
} num_repr_t;

// Function to convert binary to decimal
void binary_to_decimal(uint8_t binary[MAX_INPUT_SIZE], int *decimal) {
    int i;
    *decimal = 0;
    for (i = 0; i < MAX_INPUT_SIZE; i++) {
        *decimal += (binary[i] - '0') * pow(2, MAX_INPUT_SIZE - i - 1);
    }
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal, uint8_t binary[MAX_INPUT_SIZE]) {
    int i;
    for (i = 0; i < MAX_INPUT_SIZE; i++) {
        binary[i] = decimal % 2 == 0 ? '0' : '1';
        decimal /= 2;
    }
}

// Function to convert binary to hexadecimal
void binary_to_hexadecimal(uint8_t binary[MAX_INPUT_SIZE], uint16_t *hexadecimal) {
    int i;
    *hexadecimal = 0;
    for (i = 0; i < MAX_INPUT_SIZE; i++) {
        *hexadecimal += (binary[i] - '0') << (4 * (MAX_INPUT_SIZE - i - 1));
    }
}

// Function to convert hexadecimal to binary
void hexadecimal_to_binary(uint16_t hexadecimal, uint8_t binary[MAX_INPUT_SIZE]) {
    int i;
    for (i = 0; i < MAX_INPUT_SIZE; i++) {
        binary[i] = hexadecimal % 16 == 0 ? '0' : '1';
        hexadecimal /= 16;
    }
}

int main() {
    num_repr_t num;
    int decimal;
    uint16_t hexadecimal;
    uint8_t binary[MAX_INPUT_SIZE];

    // Ask user for input
    printf("Enter a number (binary, decimal, or hexadecimal): ");
    scanf("%s", num.binary);

    // Convert input to decimal
    binary_to_decimal(num.binary, &decimal);
    printf("Decimal: %d\n", decimal);

    // Convert input to hexadecimal
    binary_to_hexadecimal(num.binary, &hexadecimal);
    printf("Hexadecimal: %04x\n", hexadecimal);

    // Convert hexadecimal to binary
    hexadecimal_to_binary(hexadecimal, binary);
    printf("Binary: %s\n", binary);

    return 0;
}