//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
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

// Create an array of color codes
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

// Get the number of color codes in the array
int numColorCodes = sizeof(colorCodes) / sizeof(ColorCode);

// Get the color code for a given name
ColorCode *getColorCode(char *name) {
    for (int i = 0; i < numColorCodes; i++) {
        if (strcmp(name, colorCodes[i].name) == 0) {
            return &colorCodes[i];
        }
    }
    return NULL;
}

// Print the color code for a given name
void printColorCode(char *name) {
    ColorCode *colorCode = getColorCode(name);
    if (colorCode != NULL) {
        printf("The color code for %s is (%d, %d, %d)\n", name, colorCode->red, colorCode->green, colorCode->blue);
    } else {
        printf("Invalid color name: %s\n", name);
    }
}

int main() {
    // Get the color name from the user
    char colorName[256];
    printf("Enter the color name: ");
    scanf("%s", colorName);

    // Print the color code for the given name
    printColorCode(colorName);

    return 0;
}