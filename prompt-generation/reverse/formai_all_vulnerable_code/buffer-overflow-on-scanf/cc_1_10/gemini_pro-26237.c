//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} ColorCode;

// Define an array of color codes
ColorCode colorCodes[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 128, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"pink", 255, 192, 203}
};

// Define the number of color codes
#define NUM_COLOR_CODES (sizeof(colorCodes) / sizeof(ColorCode))

// Function to convert a color name to a color code
ColorCode *convertColorNameToCode(char *colorName) {
    // Loop through the array of color codes
    for (int i = 0; i < NUM_COLOR_CODES; i++) {
        // If the color name matches the color code name, return the color code
        if (strcmp(colorName, colorCodes[i].name) == 0) {
            return &colorCodes[i];
        }
    }

    // If the color name was not found, return NULL
    return NULL;
}

// Function to convert a color code to a color name
char *convertColorCodeToName(ColorCode *colorCode) {
    // Loop through the array of color codes
    for (int i = 0; i < NUM_COLOR_CODES; i++) {
        // If the color code matches the color code, return the color name
        if (colorCode->red == colorCodes[i].red && colorCode->green == colorCodes[i].green && colorCode->blue == colorCodes[i].blue) {
            return colorCodes[i].name;
        }
    }

    // If the color code was not found, return NULL
    return NULL;
}

// Main function
int main() {
    // Get the color name from the user
    char colorName[256];
    printf("Enter a color name: ");
    scanf("%s", colorName);

    // Convert the color name to a color code
    ColorCode *colorCode = convertColorNameToCode(colorName);

    // If the color code was not found, print an error message
    if (colorCode == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    // Print the color code
    printf("Color code: %d, %d, %d\n", colorCode->red, colorCode->green, colorCode->blue);

    // Convert the color code to a color name
    char *colorName2 = convertColorCodeToName(colorCode);

    // Print the color name
    printf("Color name: %s\n", colorName2);

    return 0;
}