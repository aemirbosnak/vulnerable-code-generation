//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a color
typedef struct {
    int red;
    int green;
    int blue;
} Color;

// Function to convert a color to a hex string
char *color_to_hex(Color color) {
    char *hex_string = malloc(7);
    sprintf(hex_string, "#%02x%02x%02x", color.red, color.green, color.blue);
    return hex_string;
}

// Function to convert a hex string to a color
Color hex_to_color(char *hex_string) {
    Color color;
    sscanf(hex_string, "#%02x%02x%02x", &color.red, &color.green, &color.blue);
    return color;
}

// Function to convert a color to an RGB string
char *color_to_rgb(Color color) {
    char *rgb_string = malloc(11);
    sprintf(rgb_string, "rgb(%d, %d, %d)", color.red, color.green, color.blue);
    return rgb_string;
}

// Function to convert an RGB string to a color
Color rgb_to_color(char *rgb_string) {
    Color color;
    sscanf(rgb_string, "rgb(%d, %d, %d)", &color.red, &color.green, &color.blue);
    return color;
}

// Function to print the usage of the program
void print_usage() {
    printf("Usage: color_converter <input> <output>\n");
    printf("Where <input> is the input color in hex or RGB format, and <output> is the output color format (hex or RGB).\n");
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    // Get the input color
    char *input_color = argv[1];

    // Get the output color format
    char *output_format = argv[2];

    // Convert the input color to a Color struct
    Color color;
    if (input_color[0] == '#') {
        color = hex_to_color(input_color);
    } else {
        color = rgb_to_color(input_color);
    }

    // Convert the Color struct to the output color format
    char *output_color;
    if (strcmp(output_format, "hex") == 0) {
        output_color = color_to_hex(color);
    } else if (strcmp(output_format, "rgb") == 0) {
        output_color = color_to_rgb(color);
    } else {
        print_usage();
        return 1;
    }

    // Print the output color
    printf("%s\n", output_color);

    // Free the allocated memory
    free(output_color);

    return 0;
}