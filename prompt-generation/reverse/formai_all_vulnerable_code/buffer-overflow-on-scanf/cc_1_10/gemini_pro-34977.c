//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20

// Define the color names and their corresponding RGB values
typedef struct {
    char* name;
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color colors[] = {
    { "AliceBlue", 240, 248, 255 },
    { "AntiqueWhite", 250, 235, 215 },
    { "Aqua", 0, 255, 255 },
    { "Aquamarine", 127, 255, 212 },
    { "Azure", 240, 255, 255 },
    // ...
    // Add more colors here
    // ...
    { "White", 255, 255, 255 },
    { "Yellow", 255, 255, 0 },
    { "YellowGreen", 154, 205, 50 }
};

const int NUM_COLORS = sizeof(colors) / sizeof(Color);

// Function to convert a color name to its corresponding RGB values
void convert_color_name_to_rgb(char* color_name, unsigned char* r, unsigned char* g, unsigned char* b) {
    // Check if the color name is valid
    int found = 0;
    for (int i = 0; i < NUM_COLORS; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            *r = colors[i].r;
            *g = colors[i].g;
            *b = colors[i].b;
            found = 1;
            break;
        }
    }

    // If the color name is not valid, set the RGB values to black
    if (!found) {
        *r = 0;
        *g = 0;
        *b = 0;
    }
}

// Function to convert RGB values to a color name
char* convert_rgb_to_color_name(unsigned char r, unsigned char g, unsigned char b) {
    // Check if the RGB values are valid
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        return NULL;
    }

    // Find the closest color name to the given RGB values
    int min_distance = 256 * 256 * 3; // Initialize the minimum distance to a large value
    int closest_color_index = -1;
    for (int i = 0; i < NUM_COLORS; i++) {
        int dr = r - colors[i].r;
        int dg = g - colors[i].g;
        int db = b - colors[i].b;
        int distance = dr * dr + dg * dg + db * db;
        if (distance < min_distance) {
            min_distance = distance;
            closest_color_index = i;
        }
    }

    // Return the color name of the closest color
    return colors[closest_color_index].name;
}

int main() {
    // Get the color name from the user
    char color_name[MAX_COLOR_NAME_LENGTH];
    printf("Enter a color name: ");
    scanf("%s", color_name);

    // Convert the color name to RGB values
    unsigned char r, g, b;
    convert_color_name_to_rgb(color_name, &r, &g, &b);

    // Print the RGB values
    printf("The RGB values of %s are: %d, %d, %d\n", color_name, r, g, b);

    // Convert the RGB values back to a color name
    char* color_name_from_rgb = convert_rgb_to_color_name(r, g, b);

    // Print the color name
    printf("The color name of the RGB values %d, %d, %d is: %s\n", r, g, b, color_name_from_rgb);

    return 0;
}