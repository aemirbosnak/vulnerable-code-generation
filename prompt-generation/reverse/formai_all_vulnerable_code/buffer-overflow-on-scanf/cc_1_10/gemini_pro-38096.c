//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n) {
    // Allocate memory for the binary string
    char *binaryString = malloc(33);

    // Initialize the binary string to all zeros
    memset(binaryString, '0', 32);
    binaryString[32] = '\0';

    // Iterate through the bits of the binary string from right to left
    int i = 31;
    while (n > 0) {
        // If the least significant bit of n is 1, set the corresponding bit in the binary string to 1
        if (n % 2 == 1) {
            binaryString[i] = '1';
        }

        // Shift n to the right by 1 bit
        n >>= 1;

        // Decrement i
        i--;
    }

    // Return the binary string
    return binaryString;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binaryString) {
    // Initialize the decimal number to 0
    int decimalNumber = 0;

    // Iterate through the bits of the binary string from left to right
    int i = 0;
    while (binaryString[i] != '\0') {
        // If the current bit is 1, add 2^i to the decimal number
        if (binaryString[i] == '1') {
            decimalNumber += (1 << i);
        }

        // Increment i
        i++;
    }

    // Return the decimal number
    return decimalNumber;
}

int main() {
    // Get the decimal number from the user
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    // Convert the decimal number to binary
    char *binaryString = decimalToBinary(decimalNumber);

    // Print the binary string
    printf("The binary representation of %d is: %s\n", decimalNumber, binaryString);

    // Convert the binary string to decimal
    int convertedDecimalNumber = binaryToDecimal(binaryString);

    // Print the converted decimal number
    printf("The decimal representation of %s is: %d\n", binaryString, convertedDecimalNumber);

    // Free the memory allocated for the binary string
    free(binaryString);

    return 0;
}