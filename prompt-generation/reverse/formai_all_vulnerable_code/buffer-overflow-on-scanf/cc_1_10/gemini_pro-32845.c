//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct {
    char *name;
    int r;
    int g;
    int b;
} ColorCode;

// Define an array of color codes
ColorCode colorCodes[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"cyan", 0, 255, 255},
    {"magenta", 255, 0, 255},
    {"orange", 255, 165, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"silver", 192, 192, 192},
    {"gold", 255, 215, 0},
    {"bronze", 205, 127, 50}
};

// Get the number of color codes
int numColorCodes = sizeof(colorCodes) / sizeof(ColorCode);

// Convert a color name to a color code
ColorCode *getColorCode(char *name) {
    for (int i = 0; i < numColorCodes; i++) {
        if (strcmp(name, colorCodes[i].name) == 0) {
            return &colorCodes[i];
        }
    }
    return NULL;
}

// Convert a color code to a color name
char *getColorName(ColorCode *colorCode) {
    for (int i = 0; i < numColorCodes; i++) {
        if (colorCode->r == colorCodes[i].r && colorCode->g == colorCodes[i].g && colorCode->b == colorCodes[i].b) {
            return colorCodes[i].name;
        }
    }
    return NULL;
}

// Print a color code
void printColorCode(ColorCode *colorCode) {
    printf("Name: %s\n", colorCode->name);
    printf("R: %d\n", colorCode->r);
    printf("G: %d\n", colorCode->g);
    printf("B: %d\n", colorCode->b);
}

// Get a color code from the user
ColorCode *getColorCodeFromUser() {
    char name[256];
    printf("Enter the color name: ");
    scanf("%s", name);
    return getColorCode(name);
}

// Convert a color code to a hex string
char *colorCodeToHex(ColorCode *colorCode) {
    char *hexString = malloc(7);
    sprintf(hexString, "#%02x%02x%02x", colorCode->r, colorCode->g, colorCode->b);
    return hexString;
}

// Convert a hex string to a color code
ColorCode *hexToColorCode(char *hexString) {
    ColorCode *colorCode = malloc(sizeof(ColorCode));
    sscanf(hexString, "#%02x%02x%02x", &colorCode->r, &colorCode->g, &colorCode->b);
    return colorCode;
}

// Main function
int main() {
    // Get a color code from the user
    ColorCode *colorCode = getColorCodeFromUser();

    // Print the color code
    printColorCode(colorCode);

    // Convert the color code to a hex string
    char *hexString = colorCodeToHex(colorCode);

    // Print the hex string
    printf("Hex string: %s\n", hexString);

    // Convert the hex string back to a color code
    ColorCode *newColorCode = hexToColorCode(hexString);

    // Print the new color code
    printColorCode(newColorCode);

    return 0;
}