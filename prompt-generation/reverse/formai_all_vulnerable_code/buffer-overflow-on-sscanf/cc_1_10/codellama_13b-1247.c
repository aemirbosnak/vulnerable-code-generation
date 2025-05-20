//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: configurable
// color_code_converter.c
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a color
typedef struct {
    int red;
    int green;
    int blue;
} Color;

// Define a function to convert a color from RGB to HEX
void rgb_to_hex(Color color) {
    // Convert the color to HEX
    char hex[8];
    sprintf(hex, "#%02X%02X%02X", color.red, color.green, color.blue);

    // Print the HEX code
    printf("HEX code: %s\n", hex);
}

// Define a function to convert a color from HEX to RGB
void hex_to_rgb(char *hex) {
    // Convert the HEX code to RGB
    int red, green, blue;
    sscanf(hex, "#%02X%02X%02X", &red, &green, &blue);

    // Print the RGB values
    printf("RGB values: (%d, %d, %d)\n", red, green, blue);
}

int main(int argc, char **argv) {
    // Check if the user has provided a color code
    if (argc < 2) {
        printf("Usage: color_code_converter <color_code>\n");
        return 1;
    }

    // Get the color code from the command line arguments
    char *color_code = argv[1];

    // Check if the color code is in RGB format
    if (strlen(color_code) == 7 && color_code[0] == '#') {
        // Convert the color code to RGB
        hex_to_rgb(color_code);
    } else {
        // Convert the color code to HEX
        Color color;
        sscanf(color_code, "(%d, %d, %d)", &color.red, &color.green, &color.blue);
        rgb_to_hex(color);
    }

    return 0;
}