//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct color_code {
    char *name;
    char *hex_code;
} color_code;

// Define an array of color codes
color_code color_codes[] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"}
};

// Define the number of color codes
#define NUM_COLOR_CODES (sizeof(color_codes) / sizeof(color_code))

// Get the color code from the user
void get_color_code(char *color_code) {
    printf("Enter the color code: ");
    scanf("%s", color_code);
}

// Print the color name for the given color code
void print_color_name(char *color_code) {
    int i;

    for (i = 0; i < NUM_COLOR_CODES; i++) {
        if (strcmp(color_code, color_codes[i].hex_code) == 0) {
            printf("The color name is: %s\n", color_codes[i].name);
            return;
        }
    }

    printf("Invalid color code\n");
}

// Print the color code for the given color name
void print_color_code(char *color_name) {
    int i;

    for (i = 0; i < NUM_COLOR_CODES; i++) {
        if (strcmp(color_name, color_codes[i].name) == 0) {
            printf("The color code is: %s\n", color_codes[i].hex_code);
            return;
        }
    }

    printf("Invalid color name\n");
}

// Main function
int main() {
    char color_code[10];
    char color_name[10];

    // Get the color code from the user
    get_color_code(color_code);

    // Print the color name for the given color code
    print_color_name(color_code);

    // Get the color name from the user
    get_color_code(color_name);

    // Print the color code for the given color name
    print_color_code(color_name);

    return 0;
}