//Code Llama-13B DATASET v1.0 Category: Binary Converter ; Style: systematic
// A simple C binary converter program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
    int i, len, decimal = 0;

    // Get the length of the binary string
    len = strlen(binary);

    // Iterate over the binary string and calculate the decimal value
    for (i = 0; i < len; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, len - i - 1);
        }
    }

    return decimal;
}

// Function to convert decimal to binary
char *decimal_to_binary(int decimal) {
    int i, binary_len = 0;
    char *binary = NULL;

    // Calculate the length of the binary string
    while (decimal > 0) {
        decimal /= 2;
        binary_len++;
    }

    // Allocate memory for the binary string
    binary = (char *)malloc(binary_len + 1);

    // Iterate over the binary string and calculate the decimal value
    for (i = 0; i < binary_len; i++) {
        binary[i] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Add a null terminator to the binary string
    binary[binary_len] = '\0';

    return binary;
}

// Main function
int main() {
    char *binary = "1010";
    int decimal = 10;

    // Convert binary to decimal
    decimal = binary_to_decimal(binary);
    printf("Binary to decimal: %d\n", decimal);

    // Convert decimal to binary
    binary = decimal_to_binary(decimal);
    printf("Decimal to binary: %s\n", binary);

    return 0;
}