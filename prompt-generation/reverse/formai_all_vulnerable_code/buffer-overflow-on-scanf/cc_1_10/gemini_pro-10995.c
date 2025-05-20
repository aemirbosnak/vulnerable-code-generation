//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert hexadecimal color code to RGB values
void hex_to_rgb(char *hex, unsigned char *r, unsigned char *g, unsigned char *b) {
    // Check if the hex string is valid
    if (strlen(hex) != 7 || hex[0] != '#') {
        printf("Invalid hex color code: %s\n", hex);
        exit(1);
    }

    // Convert the hex digits to decimal values
    int r_hex = (hex[1] - '0') * 16 + (hex[2] - '0');
    int g_hex = (hex[3] - '0') * 16 + (hex[4] - '0');
    int b_hex = (hex[5] - '0') * 16 + (hex[6] - '0');

    // Check if the decimal values are within the valid range (0-255)
    if (r_hex < 0 || r_hex > 255 || g_hex < 0 || g_hex > 255 || b_hex < 0 || b_hex > 255) {
        printf("Invalid hex color code: %s\n", hex);
        exit(1);
    }

    // Set the RGB values
    *r = (unsigned char)r_hex;
    *g = (unsigned char)g_hex;
    *b = (unsigned char)b_hex;
}

// Function to convert RGB values to hexadecimal color code
void rgb_to_hex(unsigned char r, unsigned char g, unsigned char b, char *hex) {
    // Check if the RGB values are within the valid range (0-255)
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        printf("Invalid RGB values: %d, %d, %d\n", r, g, b);
        exit(1);
    }

    // Convert the RGB values to hexadecimal digits
    int r_hex = r / 16;
    int g_hex = g / 16;
    int b_hex = b / 16;

    // Convert the hexadecimal digits to characters
    char r_char = r_hex < 10 ? r_hex + '0' : r_hex + 'A' - 10;
    char g_char = g_hex < 10 ? g_hex + '0' : g_hex + 'A' - 10;
    char b_char = b_hex < 10 ? b_hex + '0' : b_hex + 'A' - 10;

    // Set the hexadecimal color code
    sprintf(hex, "#%c%c%c%c%c%c", r_char, r_char, g_char, g_char, b_char, b_char);
}

// Function to print the RGB values and hexadecimal color code
void print_color(unsigned char r, unsigned char g, unsigned char b, char *hex) {
    printf("RGB values: (%d, %d, %d)\n", r, g, b);
    printf("Hexadecimal color code: %s\n", hex);
}

int main() {
    // Create a buffer to store the hexadecimal color code
    char hex[8];

    // Get the hexadecimal color code from the user
    printf("Enter a hexadecimal color code: ");
    scanf("%s", hex);

    // Convert the hexadecimal color code to RGB values
    unsigned char r, g, b;
    hex_to_rgb(hex, &r, &g, &b);

    // Print the RGB values and hexadecimal color code
    print_color(r, g, b, hex);

    // Convert the RGB values back to hexadecimal color code
    rgb_to_hex(r, g, b, hex);

    // Print the RGB values and hexadecimal color code again
    print_color(r, g, b, hex);

    return 0;
}