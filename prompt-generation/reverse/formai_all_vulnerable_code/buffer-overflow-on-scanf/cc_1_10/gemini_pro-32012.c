//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Color code database
typedef struct color_code {
    char *name;
    int red;
    int green;
    int blue;
} color_code;

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
    {"gray", 128, 128, 128},
    {"pink", 255, 192, 203},
    {"teal", 0, 128, 128}
};

// Get the number of color codes in the database
int get_num_color_codes() {
    return sizeof(color_codes) / sizeof(color_codes[0]);
}

// Get the color code for a given name
color_code *get_color_code(char *name) {
    for (int i = 0; i < get_num_color_codes(); i++) {
        if (strcmp(name, color_codes[i].name) == 0) {
            return &color_codes[i];
        }
    }

    return NULL;
}

// Print the color code for a given name
void print_color_code(char *name) {
    color_code *color_code = get_color_code(name);
    if (color_code == NULL) {
        printf("Invalid color name: %s\n", name);
    } else {
        printf("Color code for %s: %d, %d, %d\n", name, color_code->red, color_code->green, color_code->blue);
    }
}

// Main function
int main() {
    // Get the color name from the user
    char color_name[100];
    printf("Enter the color name: ");
    scanf("%s", color_name);

    // Print the color code for the given name
    print_color_code(color_name);

    return 0;
}