//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal color code to RGB
void hexToRGB(char* hex, int* r, int* g, int* b) {
    // Convert each hexadecimal digit to its corresponding decimal value
    int i = 0;
    for (; i < 3; i++) {
        int digit = (hex[i] - '0') * 16 + (hex[i+1] - '0');
        *r += digit;
        if (i == 1) {
            *g += digit * 2;
        } else {
            *b += digit * 4;
        }
    }
}

// Function to convert RGB color code to hexadecimal
char* rgbToHex(int r, int g, int b) {
    char hex[3];
    hex[0] = (r < 16)? '0' + r : 'a' - 10 + r;
    hex[1] = (g < 16)? '0' + g : 'a' - 10 + g;
    hex[2] = (b < 16)? '0' + b : 'a' - 10 + b;
    return hex;
}

int main() {
    char hex[3];
    int r, g, b;

    // Prompt user for input
    printf("Enter a hexadecimal color code (e.g., #FFF): ");
    scanf("%s", hex);

    // Convert hexadecimal to RGB
    hexToRGB(hex, &r, &g, &b);

    // Print RGB values
    printf("RGB values: (%d, %d, %d)\n", r, g, b);

    // Prompt user for output
    printf("Enter an RGB color code (e.g., 255, 0, 0): ");
    scanf("%d %d %d", &r, &g, &b);

    // Convert RGB to hexadecimal
    char* hexRGB = rgbToHex(r, g, b);

    // Print hexadecimal color code
    printf("Hexadecimal color code: %s\n", hexRGB);

    // Free memory
    free(hexRGB);

    return 0;
}