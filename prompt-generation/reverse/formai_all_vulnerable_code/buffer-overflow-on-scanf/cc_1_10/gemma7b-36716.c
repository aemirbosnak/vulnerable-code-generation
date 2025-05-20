//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 16

typedef struct Color {
    int red;
    int green;
    int blue;
} Color;

int main() {
    Color color;
    char input[20];

    printf("Enter color code (e.g. rgb 255,255,255): ");
    scanf("%s", input);

    // Convert input to uppercase
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is valid
    if (!validateColorCode(input, &color)) {
        printf("Invalid color code.\n");
        return 1;
    }

    // Print color code
    printf("Color code: Red: %d, Green: %d, Blue: %d\n", color.red, color.green, color.blue);

    return 0;
}

int validateColorCode(char *input, Color *color) {
    // Check if input is in the format rgb x,x,x
    if (strcmp(input, "rgb ") != 0) {
        return 0;
    }

    // Extract color values
    char *redStr = strtok(input, ",");
    char *greenStr = strtok(redStr, ",");
    char *blueStr = strtok(greenStr, ",");

    // Convert color values to integers
    color->red = atoi(redStr);
    color->green = atoi(greenStr);
    color->blue = atoi(blueStr);

    // Check if color values are valid
    if (color->red < 0 || color->red > MAX_COLORS) {
        return 0;
    }
    if (color->green < 0 || color->green > MAX_COLORS) {
        return 0;
    }
    if (color->blue < 0 || color->blue > MAX_COLORS) {
        return 0;
    }

    return 1;
}