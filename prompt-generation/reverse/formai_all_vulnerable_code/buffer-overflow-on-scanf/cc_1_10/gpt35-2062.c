//FormAI DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a given string representing a color to its RGB code
int convertToRGB(char *color) {
    int r, g, b;
    // Check if the color code is in hexadecimal or RGB format
    if (color[0] == '#' && strlen(color) == 7) {
        // If the color code is in hexadecimal format, extract the red, green, and blue values
        r = strtol(&color[1], NULL, 16) >> 16;
        g = strtol(&color[1], NULL, 16) >> 8 & 0xFF;
        b = strtol(&color[1], NULL, 16) & 0xFF;
    }
    else if (color[0] == 'r' && color[1] == 'g' && color[2] == 'b' && strlen(color) >= 9) {
        // If the color code is in RGB format, extract the red, green, and blue values
        char *end = NULL;
        r = strtol(&color[4], &end, 10);
        if (*end != ',') return -1; // Invalid format
        g = strtol(&end[1], &end, 10);
        if (*end != ',') return -1; // Invalid format
        b = strtol(&end[1], NULL, 10);
    }
    else {
        // Invalid format
        return -1;
    }
    // Check if the values are valid RGB values
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        // Invalid values
        return -1;
    }
    // Convert the red, green, and blue values to a single integer representing the RGB code
    return (r << 16) | (g << 8) | b;
}

int main()
{
    char color[10];
    // Get the color code from the user
    printf("Enter the color code (in hexadecimal or RGB format, e.g. #FF0000 or rgb(255,0,0)): ");
    scanf("%s", &color);
    // Convert the color code to its RGB value
    int rgb = convertToRGB(color);
    if (rgb == -1) {
        // Invalid format or values
        printf("Invalid color code.\n");
    } else {
        // Print the RGB code
        printf("RGB code: %d\n", rgb);
    }
    return 0;
}