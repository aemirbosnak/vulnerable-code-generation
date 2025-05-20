//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>

int hexToInt(char hex);
int hexToDecimal(char hex[], int length);
void decimalToRGB(int decimal, int *red, int *green, int *blue);
void printColor(int red, int green, int blue);

int main() {
    char hex[7];
    int decimal, red, green, blue;

    // Prompt user for hexadecimal color code
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);

    // Convert hexadecimal to decimal
    decimal = hexToDecimal(hex, 6);

    // Convert decimal to RGB values
    decimalToRGB(decimal, &red, &green, &blue);

    // Print RGB values
    printColor(red, green, blue);

    return 0;
}

// Recursive function to convert hexadecimal to decimal
int hexToDecimal(char hex[], int length) {
    // Base case
    if (length == 0) {
        return 0;
    }

    int decimal = hexToInt(hex[length - 1]) * powerOf16(6 - length);
    return decimal + hexToDecimal(hex, length - 1);
}

// Helper function to convert hex character to integer value
int hexToInt(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0';
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10;
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10;
    }
}

// Helper function to calculate power of 16 recursively
int powerOf16(int exponent) {
    if (exponent == 0) {
        return 1;
    }

    return 16 * powerOf16(exponent - 1);
}

// Function to convert decimal to RGB values
void decimalToRGB(int decimal, int *red, int *green, int *blue) {
    *red = (decimal >> 16) & 0xFF;
    *green = (decimal >> 8) & 0xFF;
    *blue = decimal & 0xFF;
}

// Function to print RGB values in the console
void printColor(int red, int green, int blue) {
    printf("RGB values are: (%d, %d, %d)\n", red, green, blue);
}