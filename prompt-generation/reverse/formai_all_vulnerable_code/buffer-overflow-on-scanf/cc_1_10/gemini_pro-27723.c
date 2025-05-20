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
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255},
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Magenta", 255, 0, 255},
    {"Cyan", 0, 255, 255},
    {"Orange", 255, 165, 0},
    {"Pink", 255, 192, 203},
    {"Purple", 128, 0, 128},
    {"Brown", 165, 42, 42},
    {"Gray", 128, 128, 128},
    {"Silver", 192, 192, 192},
    {"Gold", 255, 215, 0},
};

// Define the number of color codes
#define NUM_COLOR_CODES (sizeof(colorCodes) / sizeof(ColorCode))

// Function to convert a color name to a color code
ColorCode *getColorCode(char *name) {
    for (int i = 0; i < NUM_COLOR_CODES; i++) {
        if (strcmp(name, colorCodes[i].name) == 0) {
            return &colorCodes[i];
        }
    }

    return NULL;
}

// Function to convert a color code to a color name
char *getColorName(ColorCode *colorCode) {
    for (int i = 0; i < NUM_COLOR_CODES; i++) {
        if (colorCodes[i].red == colorCode->red &&
            colorCodes[i].green == colorCode->green &&
            colorCodes[i].blue == colorCode->blue) {
            return colorCodes[i].name;
        }
    }

    return NULL;
}

// Function to print the color codes
void printColorCodes() {
    for (int i = 0; i < NUM_COLOR_CODES; i++) {
        printf("%s: %d, %d, %d\n", colorCodes[i].name, colorCodes[i].red, colorCodes[i].green, colorCodes[i].blue);
    }
}

// Main function
int main() {
    // Get the color name from the user
    char colorName[256];
    printf("Enter a color name: ");
    scanf("%s", colorName);

    // Convert the color name to a color code
    ColorCode *colorCode = getColorCode(colorName);

    // If the color code is valid, print the color code
    if (colorCode != NULL) {
        printf("The color code for %s is: %d, %d, %d\n", colorName, colorCode->red, colorCode->green, colorCode->blue);
    } else {
        printf("Invalid color name\n");
    }

    // Print the color codes
    printColorCodes();

    return 0;
}