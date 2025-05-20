//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BINARY_LENGTH 100

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int i = 0;
    while (decimal != 0) {
        binary[i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }
    binary[i] = '\0';
}

// Function to convert binary to decimal
int binaryToDecimal(const char* binary) {
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++) {
        decimal += (binary[i] - '0') * pow(2, i);
    }
    return decimal;
}

int main() {
    // Declare variables
    int decimal, i;
    char binary[BINARY_LENGTH];

    // Prompt user for decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    decimalToBinary(decimal, binary);

    // Print binary
    printf("Binary: %s\n", binary);

    // Prompt user for binary number
    printf("Enter a binary number: ");
    char binaryInput[BINARY_LENGTH];
    scanf("%s", binaryInput);

    // Convert binary to decimal
    int decimalOutput = binaryToDecimal(binaryInput);

    // Print decimal
    printf("Decimal: %d\n", decimalOutput);

    return 0;
}