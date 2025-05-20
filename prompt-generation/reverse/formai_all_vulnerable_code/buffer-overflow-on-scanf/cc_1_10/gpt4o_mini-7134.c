//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEX_LENGTH 6
#define RGB_LENGTH 3

// Function to convert Hexadecimal color to RGB
void hexToRGB(const char *hex, int *r, int *g, int *b) {
    if (hex[0] == '#') {
        hex++; // Skip the '#' character
    }

    if (strlen(hex) != HEX_LENGTH) {
        fprintf(stderr, "Invalid Hex Color Code: %s\n", hex);
        exit(EXIT_FAILURE);
    }

    *r = (int) strtol(hex, NULL, 16) >> 16;
    *g = (int) strtol(hex, NULL, 16) >> 8 & 0xFF;
    *b = (int) strtol(hex, NULL, 16) & 0xFF;
}

// Function to convert RGB to Hexadecimal color
void rgbToHex(int r, int g, int b, char *hex) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        fprintf(stderr, "RGB values must be between 0 and 255.\n");
        exit(EXIT_FAILURE);
    }
    
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

// Function to validate a Hex color code
int isValidHex(const char *hex) {
    if (hex[0] == '#') {
        hex++; // Skip the '#' character
    }
    return (strlen(hex) == HEX_LENGTH && strspn(hex, "0123456789ABCDEFabcdef") == HEX_LENGTH);
}

// Function to display the color as an RGB tuple
void displayColor(int r, int g, int b) {
    printf("RGB Color: (%d, %d, %d)\n", r, g, b);
}

// Main function
int main() {
    char hexColor[HEX_LENGTH + 2];  // Buffer for hex color code
    int r, g, b;
    
    printf("Enter a Hexadecimal color code (e.g., #FF5733): ");
    scanf("%s", hexColor);

    // Validate the hex color code
    if (!isValidHex(hexColor)) {
        fprintf(stderr, "Invalid Hexadecimal color code format!\n");
        return EXIT_FAILURE;
    }

    // Convert the Hex code to RGB
    hexToRGB(hexColor, &r, &g, &b);
    displayColor(r, g, b);

    // Prepare a new Hex color buffer to convert back from RGB
    char newHex[HEX_LENGTH + 2];
    rgbToHex(r, g, b, newHex);
    
    printf("Converted back to Hexadecimal color code: %s\n", newHex);

    return EXIT_SUCCESS;
}