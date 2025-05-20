//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int length = strlen(binary);

    // Iterate over the binary string from right to left
    for (int i = length - 1; i >= 0; i--) {
        // If the current character is '1', add 2^power to the decimal value
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        // Increment the power for the next iteration
        power++;
    }

    return decimal;
}

// Function to convert decimal to binary
void decimalToBinary(int decimal, char* binary) {
    int power = 0;

    // Initialize the binary string with leading zeros
    for (int i = 0; i < 8; i++) {
        binary[i] = '0';
    }

    // Iterate over the decimal value from right to left
    while (decimal > 0) {
        // If the remainder is 1, add '1' to the binary string
        if (decimal % 2 == 1) {
            binary[power] = '1';
        } else {
            binary[power] = '0';
        }
        // Increment the power for the next iteration
        power++;
        // Divide the decimal value by 2 for the next iteration
        decimal /= 2;
    }
}

int main() {
    char binary[9];
    int decimal;

    // Prompt the user to enter a binary number
    printf("Enter a binary number: ");
    scanf("%s", binary);

    // Convert the binary number to decimal
    decimal = binaryToDecimal(binary);

    // Convert the decimal number to binary
    decimalToBinary(decimal, binary);

    // Print the results
    printf("Binary: %s\n", binary);
    printf("Decimal: %d\n", decimal);

    return 0;
}