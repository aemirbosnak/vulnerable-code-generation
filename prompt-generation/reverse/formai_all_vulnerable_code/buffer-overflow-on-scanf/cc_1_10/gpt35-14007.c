//FormAI DATASET v1.0 Category: Color Code Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hexToDec(char hexDigit); // Function to convert one hexadecimal digit to decimal
int hexToR(char* hex); // Function to convert hexadecimal R value to decimal
int hexToG(char* hex); // Function to convert hexadecimal G value to decimal
int hexToB(char* hex); // Function to convert hexadecimal B value to decimal
void printColorCode(int r, int g, int b); // Function to print the RGB and HEX color codes

int main() {
    char hex[7]; // Array to hold the hexadecimal color code
    int r, g, b; // Integers to hold the R, G, B values

    printf("Enter a hexadecimal color code (including the # symbol): ");
    scanf("%s", hex);

    // Check if user entered a valid color code
    if (strlen(hex) != 7 || hex[0] != '#') {
        printf("Invalid color code.\n");
        return 1;
    }

    // Convert the hexadecimal color code to RGB values
    r = hexToR(hex);
    g = hexToG(hex);
    b = hexToB(hex);

    // Print the RGB and HEX color codes
    printColorCode(r, g, b);

    return 0;
}

// Function to convert one hexadecimal digit to decimal
int hexToDec(char hexDigit) {
    if (hexDigit >= '0' && hexDigit <= '9') { // If digit is between '0' and '9'
        return hexDigit - '0';
    }
    else if (hexDigit >= 'A' && hexDigit <= 'F') { // If digit is between 'A' and 'F'
        return hexDigit - 'A' + 10;
    }
    else if (hexDigit >= 'a' && hexDigit <= 'f') { // If digit is between 'a' and 'f' (lowercase)
        return hexDigit - 'a' + 10;
    }
    else { // Invalid digit
        printf("Invalid digit in color code.\n");
        exit(1);
    }
}

// Function to convert hexadecimal R value to decimal
int hexToR(char* hex) {
    char temp[3]; // Array to hold the R value in hexadecimal format
    temp[0] = hex[1];
    temp[1] = hex[2];
    temp[2] = '\0'; // Null terminator to make it a valid string

    return hexToDec(temp[0]) * 16 + hexToDec(temp[1]); // Convert the two digits to decimal and multiply by 16
}

// Function to convert hexadecimal G value to decimal
int hexToG(char* hex) {
    char temp[3]; // Array to hold the G value in hexadecimal format
    temp[0] = hex[3];
    temp[1] = hex[4];
    temp[2] = '\0'; // Null terminator to make it a valid string

    return hexToDec(temp[0]) * 16 + hexToDec(temp[1]); // Convert the two digits to decimal and multiply by 16
}

// Function to convert hexadecimal B value to decimal
int hexToB(char* hex) {
    char temp[3]; // Array to hold the B value in hexadecimal format
    temp[0] = hex[5];
    temp[1] = hex[6];
    temp[2] = '\0'; // Null terminator to make it a valid string

    return hexToDec(temp[0]) * 16 + hexToDec(temp[1]); // Convert the two digits to decimal and multiply by 16
}

// Function to print the RGB and HEX color codes
void printColorCode(int r, int g, int b) {
    printf("RGB color code: %d,%d,%d\n", r, g, b);
    printf("HEX color code: #%02X%02X%02X\n", r, g, b); // Print the HEX code with leading zeros if necessary
}