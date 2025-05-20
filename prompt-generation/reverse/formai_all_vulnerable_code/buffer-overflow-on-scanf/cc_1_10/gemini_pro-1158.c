//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color code struct
typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} ColorCode;

// Array of color codes
ColorCode colors[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 128, 0},
    {"purple", 128, 0, 255},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"darkgray", 64, 64, 64},
    {"lightgray", 192, 192, 192},
    {"pink", 255, 192, 203},
    {"turquoise", 48, 213, 200},
    {"gold", 255, 215, 0},
    {"silver", 192, 192, 192},
    {"maroon", 128, 0, 0},
    {"olive", 128, 128, 0},
    {"navy", 0, 0, 128},
    {"teal", 0, 128, 128},
    {"lime", 0, 255, 0},
    {"aqua", 0, 255, 255},
    {"fuchsia", 255, 0, 255},
    {"beige", 245, 245, 220},
    {"chocolate", 210, 105, 30},
    {"coral", 255, 127, 80},
    {"indigo", 75, 0, 130},
    {"lavender", 230, 230, 250},
    {"mintcream", 245, 255, 250},
    {"peachpuff", 255, 218, 185},
    {"peru", 205, 133, 63},
    {"plum", 221, 160, 221},
    {"salmon", 250, 128, 114},
    {"seagreen", 46, 139, 87},
    {"tan", 210, 180, 140},
    {"thistle", 216, 191, 216},
    {"violet", 238, 130, 238},
    {"wheat", 245, 222, 179}
};

// Number of colors
int num_colors = sizeof(colors) / sizeof(colors[0]);

// Get color code by name
ColorCode *get_color_code(char *name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

// Print color code
void print_color_code(ColorCode *color) {
    printf("Name: %s\n", color->name);
    printf("Red: %d\n", color->red);
    printf("Green: %d\n", color->green);
    printf("Blue: %d\n", color->blue);
}

int main() {
    // Get color name from user
    char name[256];
    printf("Enter color name: ");
    scanf("%s", name);

    // Get color code by name
    ColorCode *color = get_color_code(name);

    // Check if color code was found
    if (color == NULL) {
        printf("Color not found.\n");
    } else {
        // Print color code
        print_color_code(color);
    }

    return 0;
}