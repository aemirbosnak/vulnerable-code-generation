//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid hexadecimal number
int isHex(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a hexadecimal number to decimal
int hexToDec(char* hex) {
    int dec = 0;
    int len = strlen(hex);
    for (int i = 0; i < len; i++) {
        if (isdigit(hex[i])) {
            dec = dec * 16 + hex[i] - '0';
        } else {
            dec = dec * 16 + hex[i] - 'A' + 10;
        }
    }
    return dec;
}

// Function to convert a decimal number to hexadecimal
void decToHex(int dec, char* hex) {
    char buffer[20];
    snprintf(buffer, sizeof(buffer), "%X", dec);
    strcpy(hex, buffer);
}

int main() {
    char input[100];
    char output[20];

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    // Validate input
    if (!isHex(input)) {
        printf("Invalid hexadecimal number\n");
        return 0;
    }

    // Convert hexadecimal to decimal
    int dec = hexToDec(input);

    // Convert decimal to hexadecimal
    decToHex(dec, output);

    printf("Hexadecimal: %s\nDecimal: %d\n", input, dec);

    return 0;
}