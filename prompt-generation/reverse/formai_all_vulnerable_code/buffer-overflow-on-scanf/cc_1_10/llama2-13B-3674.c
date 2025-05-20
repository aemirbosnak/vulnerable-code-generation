//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: accurate
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define BINARY_DIGITS 8
#define BINARY_MAX_VALUE (1 << BINARY_DIGITS) - 1

// Function to convert decimal to binary
void decimal_to_binary(int decimal, char *binary) {
    int i = 0;
    while (decimal != 0) {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0';
}

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++) {
        decimal *= 2;
        if (binary[i] == '1') {
            decimal += 1;
        }
    }
    return decimal;
}

int main() {
    int decimal, binary_length;
    char binary[BINARY_DIGITS];

    // Ask user for decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Calculate binary length
    binary_length = 0;
    while (decimal != 0) {
        binary_length++;
        decimal /= 2;
    }

    // Convert decimal to binary
    decimal_to_binary(decimal, binary);

    // Print binary
    printf("Binary representation of %d: %s\n", decimal, binary);

    // Ask user for binary string
    printf("Enter a binary string (max %d digits): ", BINARY_MAX_VALUE);
    char binary_input[BINARY_MAX_VALUE];
    scanf("%s", binary_input);

    // Convert binary to decimal
    int decimal_output = binary_to_decimal(binary_input);

    // Print decimal
    printf("Decimal representation of %s: %d\n", binary_input, decimal_output);

    return 0;
}