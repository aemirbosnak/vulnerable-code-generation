//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 20

typedef struct ColorCode
{
    char red;
    char green;
    char blue;
    char alpha;
} ColorCode;

int main()
{
    ColorCode color_code;

    printf("Enter the RGB and alpha values (separated by commas): ");
    scanf("%c,%c,%c,%c", &color_code.red, &color_code.green, &color_code.blue, &color_code.alpha);

    // Validate the input
    if (color_code.red < 0 || color_code.red > 255)
    {
        printf("Error: Red value out of range.\n");
        return 1;
    }
    if (color_code.green < 0 || color_code.green > 255)
    {
        printf("Error: Green value out of range.\n");
        return 1;
    }
    if (color_code.blue < 0 || color_code.blue > 255)
    {
        printf("Error: Blue value out of range.\n");
        return 1;
    }
    if (color_code.alpha < 0 || color_code.alpha > 255)
    {
        printf("Error: Alpha value out of range.\n");
        return 1;
    }

    // Convert the color code to a string
    char color_code_string[MAX_COLOR_CODE_LENGTH];
    snprintf(color_code_string, MAX_COLOR_CODE_LENGTH, "#%02x%02x%02x%02x", color_code.red, color_code.green, color_code.blue, color_code.alpha);

    // Print the converted color code
    printf("The converted color code is: %s\n", color_code_string);

    return 0;
}