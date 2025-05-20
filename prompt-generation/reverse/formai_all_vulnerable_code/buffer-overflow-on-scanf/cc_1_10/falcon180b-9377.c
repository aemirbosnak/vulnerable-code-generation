//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a binary digit (0 or 1)
int is_binary(char c) {
    return (c == '0' || c == '1');
}

// Function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int len = strlen(binary);

    // Iterate through each character in the binary string
    for (int i = 0; i < len; i++) {
        if (!is_binary(binary[i])) {
            // If the character is not a binary digit, return an error
            printf("Invalid binary input.\n");
            return -1;
        }

        // Calculate the decimal value of the binary digit
        int digit = binary[i] - '0';

        // Add the digit to the decimal value
        decimal += digit * (int)pow(2, power);

        // Increment the power for the next digit
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimal_to_binary(int decimal) {
    char binary[33];
    int i = 0;

    // Iterate through each digit in the binary representation of the decimal
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Reverse the binary string
    for (int j = 0; j < i / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[i - j - 1];
        binary[i - j - 1] = temp;
    }

    // Add leading zeros if necessary
    while (i < 8) {
        binary[i++] = '0';
    }

    // Print the binary string
    printf("Binary: %s\n", binary);
}

int main() {
    char binary[33];
    int decimal;

    // Prompt the user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert the binary input to decimal
    decimal = binary_to_decimal(binary);

    // If the input was invalid, exit the program
    if (decimal == -1) {
        return 1;
    }

    // Convert the decimal number to binary
    decimal_to_binary(decimal);

    return 0;
}