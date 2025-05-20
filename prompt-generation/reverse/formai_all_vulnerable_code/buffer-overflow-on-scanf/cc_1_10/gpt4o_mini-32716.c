//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal, char *hex) {
    int index = 0;
    int remainder;

    // Edge case for 0
    if (decimal == 0) {
        strcpy(hex, "0");
        return;
    }

    // Process the decimal number until it becomes 0
    while (decimal != 0) {
        remainder = decimal % 16;

        // Convert remainder to appropriate hexadecimal character
        if (remainder < 10) {
            hex[index] = remainder + '0';
        } else {
            hex[index] = remainder - 10 + 'A';
        }
        
        index++;
        decimal = decimal / 16;
    }

    // Adding null terminator at the end
    hex[index] = '\0';

    // Reverse the string to get the correct hexadecimal representation
    for (int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - 1 - i];
        hex[index - 1 - i] = temp;
    }
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const char *hex) {
    int decimal = 0;
    int base = 1; // Base for hex is 16
    int len = strlen(hex);

    for (int i = len - 1; i >= 0; i--) {
        // Handle digits and letters in the hex string
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 'a' + 10) * base;
        } else {
            fprintf(stderr, "Invalid hexadecimal character detected: %c\n", hex[i]);
            return -1;
        }
        base *= 16;
    }
    
    return decimal;
}

// Main function
int main() {
    char hex[20]; // Buffer to hold the hexadecimal representation
    int decimal;
    char hexInput[20]; // Buffer for user input in hexadecimal format

    // Decimal to Hexadecimal Conversion
    printf("Enter a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);

    decimalToHexadecimal(decimal, hex);
    printf("Decimal: %d => Hexadecimal: %s\n", decimal, hex);

    // Hexadecimal to Decimal Conversion
    printf("Enter a hexadecimal number to convert to decimal: ");
    scanf("%s", hexInput);

    int decimalOutput = hexadecimalToDecimal(hexInput);
    
    if (decimalOutput != -1) {
        printf("Hexadecimal: %s => Decimal: %d\n", hexInput, decimalOutput);
    }

    return 0;
}