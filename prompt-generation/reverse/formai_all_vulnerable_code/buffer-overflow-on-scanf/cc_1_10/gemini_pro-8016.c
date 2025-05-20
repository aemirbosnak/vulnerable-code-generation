//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color codes
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

// Define the color names
char *color_names[] = {
    "Black",
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "Magenta",
    "Cyan",
    "White"
};

// Convert a color code to a color name
char *color_code_to_name(int color_code) {
    if (color_code < 0 || color_code > 7) {
        return "Invalid color code";
    }
    return color_names[color_code];
}

// Convert a color name to a color code
int color_name_to_code(char *color_name) {
    for (int i = 0; i < 8; i++) {
        if (strcmp(color_name, color_names[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Print a list of all the color codes and names
void print_color_codes() {
    printf("Color Codes:\n");
    for (int i = 0; i < 8; i++) {
        printf("  %d: %s\n", i, color_names[i]);
    }
}

// Get a color code from the user
int get_color_code() {
    int color_code;
    printf("Enter a color code (0-7): ");
    scanf("%d", &color_code);
    return color_code;
}

// Get a color name from the user
char *get_color_name() {
    char *color_name = malloc(20);
    printf("Enter a color name: ");
    scanf("%s", color_name);
    return color_name;
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Color Code Converter!\n");

    // Get a color code from the user
    int color_code = get_color_code();

    // Convert the color code to a color name
    char *color_name = color_code_to_name(color_code);

    // Print the color name
    printf("The color name is: %s\n", color_name);

    // Get a color name from the user
    char *color_name2 = get_color_name();

    // Convert the color name to a color code
    int color_code2 = color_name_to_code(color_name2);

    // Print the color code
    printf("The color code is: %d\n", color_code2);

    // Print a list of all the color codes and names
    print_color_codes();

    return 0;
}