//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: decentralized
/*
 * Color Code Converter
 *
 * This program converts a color code from one format to another.
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>

// Struct to represent a color
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color_t;

// Function to convert a color code from RGB to Hex
void rgb_to_hex(color_t rgb, char* hex) {
    // Convert RGB to Hex
    sprintf(hex, "#%02X%02X%02X", rgb.red, rgb.green, rgb.blue);
}

// Function to convert a color code from Hex to RGB
void hex_to_rgb(char* hex, color_t* rgb) {
    // Convert Hex to RGB
    rgb->red = (unsigned char) strtol(hex, NULL, 16);
    rgb->green = (unsigned char) strtol(hex + 2, NULL, 16);
    rgb->blue = (unsigned char) strtol(hex + 4, NULL, 16);
}

int main() {
    // Define the color code to convert
    color_t color = {255, 0, 0}; // Red

    // Convert the color code to Hex
    char hex[8];
    rgb_to_hex(color, hex);

    // Print the Hex color code
    printf("Hex color code: %s\n", hex);

    // Convert the Hex color code back to RGB
    color_t rgb;
    hex_to_rgb(hex, &rgb);

    // Print the RGB color code
    printf("RGB color code: %d, %d, %d\n", rgb.red, rgb.green, rgb.blue);

    return 0;
}