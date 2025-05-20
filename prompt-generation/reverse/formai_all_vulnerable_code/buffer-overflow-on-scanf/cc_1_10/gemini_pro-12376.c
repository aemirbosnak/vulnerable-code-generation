//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom binary converter function
char *binConvert(unsigned int num) {
    // Allocate memory for the binary representation
    char *binary = malloc(33 * sizeof(char));
    int i = 0;

    // Iterate through the bits of the integer, starting from the least significant bit
    while (num > 0) {
        // Get the least significant bit
        int bit = num & 1;

        // Convert the bit to a character ('0' or '1')
        binary[i++] = bit + '0';

        // Shift the integer to the right by 1 bit
        num >>= 1;
    }

    // Terminate the binary representation with a null character
    binary[i] = '\0';

    // Reverse the binary representation
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    // Return the binary representation
    return binary;
}

int main() {
    // Variables for user input and binary representation
    unsigned int number;
    char *binary;

    // Prompt the user to enter a decimal number
    printf("Enter a decimal number: ");
    scanf("%u", &number);

    // Convert the decimal number to binary using the custom function
    binary = binConvert(number);

    // Print the binary representation
    printf("Binary representation: %s\n", binary);

    // Free the memory allocated for the binary representation
    free(binary);

    return 0;
}