//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB color to hex format
void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to convert hex color to RGB format
void hexToRgb(char *hex, int *r, int *g, int *b) {
    if (strlen(hex)!= 7 || hex[0]!= '#') {
        *r = *g = *b = 0;
        return;
    }

    hex += 1; // skip '#' character

    int n = strlen(hex);
    *r = hexToInt(hex, n);
    *g = hexToInt(hex + 2, n);
    *b = hexToInt(hex + 4, n);
}

// Function to convert hex character to integer
int hexToInt(char *hex, int n) {
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = (val << 4) + (hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val = (val << 4) + (hex[i] - 'A' + 10);
        } else {
            return 0; // invalid hex character
        }
    }
    return val;
}

// Function to print color in RGB format
void printRgb(int r, int g, int b) {
    printf("RGB: %d, %d, %d\n", r, g, b);
}

// Function to print color in hex format
void printHex(char *hex) {
    printf("HEX: %s\n", hex);
}

// Main function
int main() {
    char input[100];
    char *hex;
    int r, g, b;

    printf("Enter a color in RGB format (e.g. 255, 255, 255): ");
    scanf("%s", input);

    // Convert RGB to hex
    hexToRgb(input, &r, &g, &b);
    rgbToHex(r, g, b, hex);

    // Print results
    printf("You entered the color: ");
    printRgb(r, g, b);
    printf("\nThe color in hex format is: ");
    printHex(hex);

    return 0;
}