//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_LENGTH 20
#define MAX_RGB_VALUE 255

// Struct to hold RGB color values
typedef struct {
    int red;
    int green;
    int blue;
} RGBColor;

// Function to validate hex color code
int isValidHex(const char *hex) {
    if (hex[0] != '#' || strlen(hex) != 7) {
        return 0; // Not a valid hex color code
    }
    for (int i = 1; i < 7; i++) {
        if (!isxdigit(hex[i])) {
            return 0; // Invalid character found
        }
    }
    return 1;
}

// Function to convert hex color code to RGB
RGBColor hexToRGB(const char *hex) {
    RGBColor rgb;
    sscanf(hex + 1, "%02x%02x%02x", &rgb.red, &rgb.green, &rgb.blue);
    return rgb;
}

// Function to convert RGB to hex color code
void rgbToHex(RGBColor rgb, char *hex) {
    sprintf(hex, "#%02x%02x%02x", rgb.red, rgb.green, rgb.blue);
}

// Function to print RGB values
void printRGB(RGBColor rgb) {
    printf("RGB: (%d, %d, %d)\n", rgb.red, rgb.green, rgb.blue);
}

// Function to print hex color code
void printHex(const char *hex) {
    printf("Hex: %s\n", hex);
}

// Function to convert user input color format and display
void colorConverter(const char *inputColor) {
    char hex[MAX_COLOR_LENGTH]; // Buffer to store hex representation
    RGBColor rgb;

    // Check if input is a valid hex
    if (isValidHex(inputColor)) {
        rgb = hexToRGB(inputColor);
        printRGB(rgb);
    } else {
        // Assume input is RGB if it's not hex, check the format
        int red, green, blue;
        if (sscanf(inputColor, "%d,%d,%d", &red, &green, &blue) == 3) {
            // Validate RGB values
            if (red < 0 || red > MAX_RGB_VALUE || 
                green < 0 || green > MAX_RGB_VALUE || 
                blue < 0 || blue > MAX_RGB_VALUE) {
                printf("Invalid RGB values. Values should be between 0 and 255.\n");
                return;
            }
            rgb.red = red;
            rgb.green = green;
            rgb.blue = blue;
            rgbToHex(rgb, hex);
            printHex(hex);
        } else {
            printf("Invalid color format. Use hex (#RRGGBB) or RGB (R,G,B).\n");
        }
    }
}

// Main program to run the color conversion
int main() {
    char colorInput[MAX_COLOR_LENGTH];

    printf("Welcome to the Color Code Converter!\n");
    printf("Enter a color in hex format (e.g., #1a2b3c) or RGB format (e.g., 26,43,60): ");
    
    // Get user input
    if (fgets(colorInput, sizeof(colorInput), stdin)) {
        // Remove trailing newline character if present
        colorInput[strcspn(colorInput, "\n")] = 0;
        colorConverter(colorInput);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}