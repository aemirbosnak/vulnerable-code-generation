//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Define the binary digits and their corresponding ASCII characters
#define BINARY_DIGITS "0123456789"
#define ASCII_CHARS " !@#$%^&*()_-+"

// Define the conversion functions
void binary_to_ascii(uint8_t binary[], char ascii[]);
void ascii_to_binary(char ascii[], uint8_t binary[]);

int main() {
    // Declare the binary and ASCII arrays
    uint8_t binary[10];
    char ascii[10];

    // Set the binary array with some test data
    binary[0] = 0b10101010;
    binary[1] = 0b11001001;
    binary[2] = 0b10010010;
    binary[3] = 0b10100100;
    binary[4] = 0b10001001;
    binary[5] = 0b10101000;
    binary[6] = 0b10010000;
    binary[7] = 0b10100001;
    binary[8] = 0b10000100;
    binary[9] = 0b10100010;

    // Convert the binary array to ASCII
    binary_to_ascii(binary, ascii);

    // Print the ASCII string
    printf("%s\n", ascii);

    // Convert the ASCII string back to binary
    ascii_to_binary(ascii, binary);

    // Print the binary array
    printf("%s\n", binary);

    return 0;
}

// Function to convert binary to ASCII
void binary_to_ascii(uint8_t binary[], char ascii[]) {
    int i;
    for (i = 0; i < 10; i++) {
        // Iterate through the binary array
        if (binary[i] & 0b10000000) {
            // If the bit is set, add the corresponding ASCII character
            ascii[i] = ASCII_CHARS[binary[i] & 0b1111111];
        } else {
            // If the bit is clear, add a space
            ascii[i] = ' ';
        }
    }
}

// Function to convert ASCII to binary
void ascii_to_binary(char ascii[], uint8_t binary[]) {
    int i;
    for (i = 0; i < 10; i++) {
        // Iterate through the ASCII array
        if (ascii[i] == ' ') {
            // If the character is a space, set the corresponding bit in the binary array to 0
            binary[i] &= ~0b10000000;
        } else {
            // If the character is a valid ASCII character, set the corresponding bit in the binary array to 1
            binary[i] |= (ascii[i] - '0') << (8 - i);
        }
    }
}