//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} color_code;

// Create an array of color codes
color_code color_codes[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 165, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128}
};

// Get the number of color codes
int num_color_codes = sizeof(color_codes) / sizeof(color_code);

// Get the color code for a given name
color_code *get_color_code(char *name) {
    for (int i = 0; i < num_color_codes; i++) {
        if (strcmp(name, color_codes[i].name) == 0) {
            return &color_codes[i];
        }
    }
    return NULL;
}

// Print the color code for a given name
void print_color_code(char *name) {
    color_code *color_code = get_color_code(name);
    if (color_code != NULL) {
        printf("The color code for %s is (%d, %d, %d)\n", name, color_code->red, color_code->green, color_code->blue);
    } else {
        printf("Invalid color name: %s\n", name);
    }
}

// Convert a color code to a hex string
char *color_code_to_hex(color_code *color_code) {
    char *hex_string = malloc(7);
    sprintf(hex_string, "#%02X%02X%02X", color_code->red, color_code->green, color_code->blue);
    return hex_string;
}

// Print the hex string for a given color name
void print_hex_string(char *name) {
    color_code *color_code = get_color_code(name);
    if (color_code != NULL) {
        char *hex_string = color_code_to_hex(color_code);
        printf("The hex string for %s is %s\n", name, hex_string);
        free(hex_string);
    } else {
        printf("Invalid color name: %s\n", name);
    }
}

// Main function
int main() {
    // Get the color name from the user
    char color_name[256];
    printf("Enter the color name: ");
    scanf("%s", color_name);

    // Print the color code and hex string for the given color name
    print_color_code(color_name);
    print_hex_string(color_name);

    return 0;
}