//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: genius
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

// Function to convert binary to decimal
uint32_t binary_to_decimal(uint32_t num) {
    uint32_t result = 0;
    while (num > 0) {
        result *= 2;
        result += (num % 2) ? 1 : 0;
        num /= 2;
    }
    return result;
}

// Function to convert decimal to binary
uint32_t decimal_to_binary(uint32_t num) {
    uint32_t result = 0;
    while (num > 0) {
        result *= 2;
        result += (num % 2) ? 1 : 0;
        num /= 2;
    }
    return result;
}

int main() {
    // Get input from user
    uint32_t num;
    printf("Enter a number (0-255): ");
    scanf("%u", &num);

    // Convert number to binary
    uint32_t binary = decimal_to_binary(num);

    // Print binary representation
    printf("Binary representation of %u: ", num);
    for (int i = 0; i < 32; i++) {
        printf("%d", (binary >> i) & 1);
        if (i % 4 == 3) {
            printf(" ");
        }
    }

    // Get input from user again
    num = 0;
    printf("Enter a number (0-255): ");
    scanf("%u", &num);

    // Convert number to decimal
    uint32_t decimal = binary_to_decimal(binary);

    // Print decimal representation
    printf("Decimal representation of %u: %u\n", num, decimal);

    return 0;
}