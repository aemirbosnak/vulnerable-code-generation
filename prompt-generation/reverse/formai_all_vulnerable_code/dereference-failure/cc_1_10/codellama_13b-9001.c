//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: portable
/*
 * C Color Code Converter
 *
 * Convert between different color code formats.
 *
 * Written in a portable style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Struct to represent a color code
typedef struct {
    char* name;
    int r;
    int g;
    int b;
} color_t;

// Array of color codes
color_t color_codes[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"cyan", 0, 255, 255},
    {"magenta", 255, 0, 255},
};

// Function to convert a color code from one format to another
void convert_color_code(char* input, char* output, int output_format) {
    // Parse the input color code
    int r, g, b;
    if (sscanf(input, "%d,%d,%d", &r, &g, &b) != 3) {
        fprintf(stderr, "Invalid input color code\n");
        exit(1);
    }

    // Convert the color code to the desired format
    switch (output_format) {
        case 0:
            // Convert to hexadecimal
            sprintf(output, "%02x%02x%02x", r, g, b);
            break;
        case 1:
            // Convert to decimal
            sprintf(output, "%d,%d,%d", r, g, b);
            break;
        case 2:
            // Convert to RGB
            sprintf(output, "rgb(%d,%d,%d)", r, g, b);
            break;
        default:
            fprintf(stderr, "Invalid output format\n");
            exit(1);
    }
}

int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_color_code output_format\n", argv[0]);
        exit(1);
    }

    // Get the input and output formats
    char* input = argv[1];
    int output_format = atoi(argv[2]);

    // Convert the color code
    char output[MAX_INPUT_SIZE];
    convert_color_code(input, output, output_format);

    // Print the converted color code
    printf("%s\n", output);

    return 0;
}