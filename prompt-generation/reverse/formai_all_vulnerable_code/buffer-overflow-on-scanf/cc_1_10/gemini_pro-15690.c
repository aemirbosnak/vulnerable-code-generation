//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BINARY_DIGITS 8

// Prints the binary representation of a number
void print_binary(uint8_t number) {
    for (int i = BINARY_DIGITS - 1; i >= 0; i--) {
        // Check if the bit is set
        if ((number >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

// Converts a binary string to an integer
uint8_t binary_to_int(char *binary_string) {
    uint8_t number = 0;
    int length = strlen(binary_string);
    
    // Iterate over the binary string
    for (int i = 0; i < length; i++) {
        // Check if the bit is set
        if (binary_string[i] == '1') {
            // Set the corresponding bit in the number
            number |= (1 << (BINARY_DIGITS - i - 1));
        }
    }

    return number;
}

int main() {
    // Get the input number
    uint8_t number;
    printf("Enter a number (0-255): ");
    scanf("%hhu", &number);

    // Print the binary representation of the number
    printf("Binary representation: ");
    print_binary(number);
    printf("\n");

    // Get the binary string
    char binary_string[BINARY_DIGITS + 1];
    printf("Enter a binary string (8 bits): ");
    scanf("%s", binary_string);

    // Convert the binary string to an integer
    uint8_t converted_number = binary_to_int(binary_string);

    // Print the converted number
    printf("Converted number: %hhu\n", converted_number);

    return 0;
}