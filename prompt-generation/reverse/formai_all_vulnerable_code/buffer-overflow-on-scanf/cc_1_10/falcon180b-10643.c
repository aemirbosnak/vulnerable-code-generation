//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void convertBinaryToDecimal(char *binary, int binaryLength, int *decimal);
void convertDecimalToBinary(int decimal, char *binary, int binaryLength);

int main() {
    char binary[100];
    int decimal;
    int binaryLength;

    // Get binary input from user
    printf("Enter a binary number (up to 100 bits): ");
    scanf("%s", binary);
    binaryLength = strlen(binary);

    // Validate binary input
    for (int i = 0; i < binaryLength; i++) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            printf("Error: Invalid binary input.\n");
            return 1;
        }
    }

    // Convert binary to decimal
    convertBinaryToDecimal(binary, binaryLength, &decimal);

    // Display decimal output
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}

// Function to convert binary to decimal
void convertBinaryToDecimal(char *binary, int binaryLength, int *decimal) {
    int power = 0;
    int decimalValue = 0;

    // Calculate decimal value
    for (int i = binaryLength - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimalValue += pow(2, power);
        }
        power++;
    }

    *decimal = decimalValue;
}

// Function to convert decimal to binary
void convertDecimalToBinary(int decimal, char *binary, int binaryLength) {
    int remainder;

    // Convert decimal to binary
    for (int i = binaryLength - 1; i >= 0; i--) {
        remainder = decimal % 2;
        binary[i] = remainder + '0';
        decimal /= 2;
    }
}