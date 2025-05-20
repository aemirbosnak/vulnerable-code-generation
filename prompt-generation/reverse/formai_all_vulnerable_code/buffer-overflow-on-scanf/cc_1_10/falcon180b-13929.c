//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal to RGB
void hexToRgb(char *hex, int *r, int *g, int *b) {
    if (strlen(hex)!= 7) {
        printf("Invalid hexadecimal color code.\n");
        exit(1);
    }

    // Convert hexadecimal to decimal values
    int hexVal = 0;
    for (int i = 0; i < 6; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            hexVal += hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            hexVal += hex[i] - 'A' + 10;
        } else {
            printf("Invalid hexadecimal color code.\n");
            exit(1);
        }
    }

    // Convert decimal values to RGB
    *r = (hexVal >> 16) & 0xFF;
    *g = (hexVal >> 8) & 0xFF;
    *b = hexVal & 0xFF;
}

// Function to convert RGB to hexadecimal
void rgbToHex(int r, int g, int b, char *hex) {
    sprintf(hex, "#%02X%02X%02X", r, g, b);
}

int main() {
    char hex[8];
    int r, g, b;

    // Get user input
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);

    // Convert hexadecimal to RGB
    hexToRgb(hex, &r, &g, &b);

    // Convert RGB to hexadecimal
    char rgbHex[8];
    rgbToHex(r, g, b, rgbHex);

    // Print the results
    printf("Hexadecimal color code: #%s\n", hex);
    printf("RGB color code: #%s\n", rgbHex);

    return 0;
}