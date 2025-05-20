//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_LENGTH 100

// Function to convert a hexadecimal string to uppercase
void hexToUpper(char* hex) {
    int i = 0;
    while (hex[i]) {
        hex[i] = toupper(hex[i]);
        i++;
    }
}

// Function to convert a hexadecimal string to decimal
int hexToDec(char* hex) {
    int dec = 0;
    int i = 0;
    while (hex[i]) {
        if (isdigit(hex[i])) {
            dec = dec * 16 + hex[i] - '0';
        } else if (isalpha(hex[i])) {
            dec = dec * 16 + hex[i] - 'A' + 10;
        } else {
            return -1; // Invalid character
        }
        i++;
    }
    return dec;
}

// Function to validate a hexadecimal string
int validateHex(char* hex) {
    int i = 0;
    while (hex[i]) {
        if (!isxdigit(hex[i])) {
            return 0; // Invalid character
        }
        i++;
    }
    return 1; // Valid hexadecimal string
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char* hex) {
    int i = 0;
    while (dec > 0) {
        hex[i++] = (dec % 16 < 10)? dec % 16 + '0' : dec % 16 + 'A' - 10;
        dec /= 16;
    }
    hex[i] = '\0';
    hexToUpper(hex);
}

int main() {
    char hex[MAX_HEX_LENGTH];
    int dec;

    // Get hexadecimal input from user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Validate hexadecimal input
    if (!validateHex(hex)) {
        printf("Error: Invalid hexadecimal input.\n");
        return 1;
    }

    // Convert hexadecimal to decimal
    dec = hexToDec(hex);
    if (dec == -1) {
        printf("Error: Invalid hexadecimal input.\n");
        return 1;
    }

    // Convert decimal to hexadecimal
    decToHex(dec, hex);

    // Print result
    printf("Decimal: %d\n", dec);
    printf("Hexadecimal: %s\n", hex);

    return 0;
}