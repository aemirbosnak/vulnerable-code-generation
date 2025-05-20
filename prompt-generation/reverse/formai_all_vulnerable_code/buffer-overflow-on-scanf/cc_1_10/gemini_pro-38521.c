//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct color_code {
    char *name;
    int red;
    int green;
    int blue;
} color_code;

// Define an array of color codes
color_code colors[] = {
    {"black",   0,   0,   0},
    {"white", 255, 255, 255},
    {"red",   255,   0,   0},
    {"green",   0, 255,   0},
    {"blue",    0,   0, 255},
    {"yellow", 255, 255,   0},
    {"magenta", 255,   0, 255},
    {"cyan",    0, 255, 255},
    {"gray",  128, 128, 128},
    {"maroon", 128,   0,   0},
    {"olive",  128, 128,   0},
    {"purple", 128,   0, 128},
    {"teal",    0, 128, 128},
    {"navy",    0,   0, 128}
};

// Define the number of color codes
#define NUM_COLORS (sizeof(colors) / sizeof(color_code))

// Function to convert a color name to a color code
color_code *color_code_from_name(char *name) {
    for (int i = 0; i < NUM_COLORS; i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return &colors[i];
        }
    }

    return NULL;
}

// Function to convert a color code to a color name
char *color_name_from_code(color_code *code) {
    for (int i = 0; i < NUM_COLORS; i++) {
        if (code->red == colors[i].red && code->green == colors[i].green && code->blue == colors[i].blue) {
            return colors[i].name;
        }
    }

    return NULL;
}

// Function to print a color code
void color_code_print(color_code *code) {
    printf("Color Code: (%d, %d, %d)\n", code->red, code->green, code->blue);
}

// Function to test the color code converter
int main() {
    // Get a color name from the user
    char name[256];
    printf("Enter a color name: ");
    scanf("%s", name);

    // Convert the color name to a color code
    color_code *code = color_code_from_name(name);

    // If the color code is valid, print it
    if (code != NULL) {
        color_code_print(code);
    } else {
        printf("Invalid color name\n");
    }

    return 0;
}