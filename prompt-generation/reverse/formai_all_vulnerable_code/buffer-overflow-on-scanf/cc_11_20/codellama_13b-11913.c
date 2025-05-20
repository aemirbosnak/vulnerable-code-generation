//Code Llama-13B DATASET v1.0 Category: Color Code Converter ; Style: enthusiastic
/*
 * Unique C Color Code Converter
 * By: [Your Name]
 */

#include <stdio.h>

// Define the color code structure
typedef struct {
    int r;
    int g;
    int b;
} ColorCode;

// Define the color names
const char *colorNames[] = {
    "RED",
    "GREEN",
    "BLUE",
    "YELLOW",
    "MAGENTA",
    "CYAN",
    "WHITE",
    "BLACK"
};

// Define the color code to name mapping
const char *colorCodeToName(ColorCode color) {
    if (color.r == 255 && color.g == 0 && color.b == 0) {
        return "RED";
    } else if (color.r == 0 && color.g == 255 && color.b == 0) {
        return "GREEN";
    } else if (color.r == 0 && color.g == 0 && color.b == 255) {
        return "BLUE";
    } else if (color.r == 255 && color.g == 255 && color.b == 0) {
        return "YELLOW";
    } else if (color.r == 255 && color.g == 0 && color.b == 255) {
        return "MAGENTA";
    } else if (color.r == 0 && color.g == 255 && color.b == 255) {
        return "CYAN";
    } else if (color.r == 255 && color.g == 255 && color.b == 255) {
        return "WHITE";
    } else {
        return "BLACK";
    }
}

int main() {
    // Initialize the color code
    ColorCode color = {0, 0, 0};

    // Ask for the color code
    printf("Enter the color code (e.g. 255 0 0): ");
    scanf("%d %d %d", &color.r, &color.g, &color.b);

    // Convert the color code to name
    const char *name = colorCodeToName(color);

    // Print the color name
    printf("The color name is: %s\n", name);

    return 0;
}