//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to validate if a string is a valid hex color code
int isValidHexColorCode(char* str) {
    int len = strlen(str);
    if (len!= 7) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a hex color code to RGB
void hexToRgb(char* hex, int* rgb) {
    rgb[0] = strtol(hex, NULL, 16);
    rgb[1] = strtol(&hex[2], NULL, 16);
    rgb[2] = strtol(&hex[4], NULL, 16);
}

// Function to convert RGB to a hex color code
void rgbToHex(int* rgb, char* hex) {
    sprintf(hex, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
}

int main() {
    char input[100];
    int rgb[3];

    // Prompt user for input
    printf("Enter a hex color code: ");
    scanf("%s", input);

    // Validate input
    if (!isValidHexColorCode(input)) {
        printf("Invalid hex color code\n");
        return 0;
    }

    // Convert hex to RGB
    hexToRgb(input, rgb);

    // Convert RGB to hex
    char hexCode[10];
    rgbToHex(rgb, hexCode);

    // Print results
    printf("Hex color code: %s\n", input);
    printf("RGB color code: %d, %d, %d\n", rgb[0], rgb[1], rgb[2]);
    printf("Hex color code (converted from RGB): #%s\n", hexCode);

    return 0;
}