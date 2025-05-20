//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: relaxed
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

// Initialize the color code array
ColorCode colorCodes[] = {
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
int numColorCodes = sizeof(colorCodes) / sizeof(ColorCode);

// Get the color code by name
ColorCode *getColorCodeByName(char *name) {
    for (int i = 0; i < numColorCodes; i++) {
        if (strcmp(name, colorCodes[i].name) == 0) {
            return &colorCodes[i];
        }
    }

    return NULL;
}

// Get the color code by RGB values
ColorCode *getColorCodeByRGB(int red, int green, int blue) {
    for (int i = 0; i < numColorCodes; i++) {
        if (colorCodes[i].red == red && colorCodes[i].green == green && colorCodes[i].blue == blue) {
            return &colorCodes[i];
        }
    }

    return NULL;
}

// Print the color code information
void printColorCode(ColorCode *colorCode) {
    printf("Color: %s\n", colorCode->name);
    printf("Red: %d\n", colorCode->red);
    printf("Green: %d\n", colorCode->green);
    printf("Blue: %d\n\n", colorCode->blue);
}

// Main function
int main() {
    // Get the color name from the user
    char colorName[20];
    printf("Enter the color name: ");
    scanf("%s", colorName);

    // Get the color code by name
    ColorCode *colorCode = getColorCodeByName(colorName);

    // Check if the color code was found
    if (colorCode == NULL) {
        printf("Invalid color name\n");
        return 1;
    }

    // Print the color code information
    printColorCode(colorCode);

    return 0;
}