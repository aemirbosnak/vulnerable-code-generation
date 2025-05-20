//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int red, green, blue, cyan, magenta, hue, saturation, value;
    char input_color[20];

    printf("Enter the name of a color: ");
    scanf("%s", input_color);

    // Convert the input color to RGB values
    switch (input_color[0])
    {
        case 'r':
            red = 255;
            green = 0;
            blue = 0;
            break;
        case 'g':
            red = 0;
            green = 255;
            blue = 0;
            break;
        case 'b':
            red = 0;
            green = 0;
            blue = 255;
            break;
        case 'c':
            red = 128;
            green = 128;
            blue = 128;
            break;
        case 'm':
            red = 128;
            green = 0;
            blue = 128;
            break;
        default:
            printf("Invalid color name.\n");
            return 1;
    }

    // Convert the RGB values to hue, saturation, and value
    hue = hue_from_rgb(red, green, blue);
    saturation = saturation_from_rgb(red, green, blue);
    value = value_from_rgb(red, green, blue);

    // Print the converted values
    printf("Hue: %d\n", hue);
    printf("Saturation: %d\n", saturation);
    printf("Value: %d\n", value);

    return 0;
}

int hue_from_rgb(int r, int g, int b)
{
    int max_color = fmax(r, fmax(g, b));
    int min_color = fmin(r, fmin(g, b));

    if (max_color - min_color < 1)
    {
        return 0;
    }

    return (120 * (min_color - r) / (max_color - min_color)) + 1;
}

int saturation_from_rgb(int r, int g, int b)
{
    int max_color = fmax(r, fmax(g, b));
    int min_color = fmin(r, fmin(g, b));

    if (max_color - min_color < 1)
    {
        return 0;
    }

    return (255 * (max_color - min_color) / max_color) * 100;
}

int value_from_rgb(int r, int g, int b)
{
    return (r + g + b) / 3;
}