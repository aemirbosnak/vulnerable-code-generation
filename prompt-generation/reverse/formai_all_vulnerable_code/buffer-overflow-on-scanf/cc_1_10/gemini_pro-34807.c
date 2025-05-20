//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: systematic
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

// Define an array of color codes
color_code color_codes[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255}
};

// Get the number of color codes
int num_color_codes = sizeof(color_codes) / sizeof(color_codes[0]);

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

    if (color_code == NULL) {
        printf("Invalid color name: %s\n", name);
        return;
    }

    printf("Color code for %s: (%d, %d, %d)\n", name, color_code->red, color_code->green, color_code->blue);
}

int main() {
    // Get the color name from the user
    char color_name[256];
    printf("Enter the color name: ");
    scanf("%s", color_name);

    // Print the color code for the given name
    print_color_code(color_name);

    return 0;
}