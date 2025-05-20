//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a color
typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} Color;

// Array of colors
Color colors[] = {
    { "Red", 255, 0, 0 },
    { "Green", 0, 255, 0 },
    { "Blue", 0, 0, 255 },
    { "Yellow", 255, 255, 0 },
    { "Magenta", 255, 0, 255 },
    { "Cyan", 0, 255, 255 },
    { "White", 255, 255, 255 },
    { "Black", 0, 0, 0 }
};

// Number of colors in the array
int num_colors = sizeof(colors) / sizeof(Color);

// Function to convert a color name to its RGB values
void color_name_to_rgb(char *color_name, int *red, int *green, int *blue) {
    // Iterate over the array of colors
    for (int i = 0; i < num_colors; i++) {
        // If the color name matches the name of a color in the array,
        // return the RGB values of that color
        if (strcmp(color_name, colors[i].name) == 0) {
            *red = colors[i].red;
            *green = colors[i].green;
            *blue = colors[i].blue;
            return;
        }
    }

    // If the color name is not found in the array, return -1 for all RGB values
    *red = -1;
    *green = -1;
    *blue = -1;
}

// Function to convert RGB values to a color name
char *rgb_to_color_name(int red, int green, int blue) {
    // Iterate over the array of colors
    for (int i = 0; i < num_colors; i++) {
        // If the RGB values match the RGB values of a color in the array,
        // return the name of that color
        if (red == colors[i].red && green == colors[i].green && blue == colors[i].blue) {
            return colors[i].name;
        }
    }

    // If the RGB values do not match any color in the array, return NULL
    return NULL;
}

// Main function
int main() {
    // Get the color name from the user
    printf("Enter a color name: ");
    char color_name[20];
    scanf("%s", color_name);

    // Convert the color name to RGB values
    int red, green, blue;
    color_name_to_rgb(color_name, &red, &green, &blue);

    // Print the RGB values
    printf("RGB values: %d, %d, %d\n", red, green, blue);

    // Convert the RGB values to a color name
    char *color_name_from_rgb = rgb_to_color_name(red, green, blue);

    // Print the color name
    printf("Color name: %s\n", color_name_from_rgb);

    return 0;
}