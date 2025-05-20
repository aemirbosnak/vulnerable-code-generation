//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the RGB values of a color
typedef struct {
    int red;
    int green;
    int blue;
} RGB;

// Function to convert a hex color code to an RGB struct
RGB hex_to_rgb(char *hex) {
    RGB rgb;
    sscanf(hex, "%2x%2x%2x", &rgb.red, &rgb.green, &rgb.blue);
    return rgb;
}

// Function to convert an RGB struct to a hex color code
char *rgb_to_hex(RGB rgb) {
    char *hex = malloc(7);
    sprintf(hex, "#%02x%02x%02x", rgb.red, rgb.green, rgb.blue);
    return hex;
}

// Function to print the RGB values of a color
void print_rgb(RGB rgb) {
    printf("Red: %d\nGreen: %d\nBlue: %d\n", rgb.red, rgb.green, rgb.blue);
}

// Function to print the hex color code of a color
void print_hex(char *hex) {
    printf("Hex: %s\n", hex);
}

// Main function
int main() {
    // Get the hex color code from the user
    char hex[7];
    printf("Enter the hex color code: ");
    scanf("%s", hex);

    // Convert the hex color code to an RGB struct
    RGB rgb = hex_to_rgb(hex);

    // Print the RGB values of the color
    printf("RGB values:\n");
    print_rgb(rgb);

    // Convert the RGB struct to a hex color code
    char *new_hex = rgb_to_hex(rgb);

    // Print the hex color code of the color
    printf("Hex color code:\n");
    print_hex(new_hex);

    // Free the allocated memory
    free(new_hex);

    return 0;
}