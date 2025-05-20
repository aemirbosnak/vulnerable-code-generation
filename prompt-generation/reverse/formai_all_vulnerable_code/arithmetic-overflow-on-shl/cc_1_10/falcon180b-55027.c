//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to convert binary to decimal
int binary_to_decimal(char *binary) {
    int decimal = 0;
    int power = 0;

    // Iterate over each character in the binary string
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        // Check if the character is a digit
        if (is_digit(binary[i])) {
            // Calculate the decimal value of the digit
            decimal += (binary[i] - '0') * pow(2, power);
            // Increase the power for the next digit
            power++;
        } else {
            // If the character is not a digit, return -1 to indicate an error
            return -1;
        }
    }

    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[MAX_LENGTH];
    int index = 0;

    // Iterate over each power of 2
    for (int i = 31; i >= 0; i--) {
        // Check if the power of 2 is greater than or equal to the decimal value
        if (decimal >= (1 << i)) {
            // Add a 1 to the binary string
            binary[index++] = '1';
            // Subtract the power of 2 from the decimal value
            decimal -= (1 << i);
        } else {
            // Add a 0 to the binary string
            binary[index++] = '0';
        }
    }

    // Add a null terminator to the binary string
    binary[index] = '\0';

    // Print the binary string
    printf("Binary: %s\n", binary);
}

// Main function to prompt the user for input and call the appropriate conversion function
int main() {
    char input[MAX_LENGTH];
    int decimal;

    // Prompt the user for input
    printf("Enter a binary number: ");
    scanf("%s", input);

    // Convert the binary input to decimal
    decimal = binary_to_decimal(input);

    // Check if the conversion was successful
    if (decimal == -1) {
        printf("Invalid binary input.\n");
        return 1;
    }

    // Convert the decimal value to binary
    decimal_to_binary(decimal);

    return 0;
}