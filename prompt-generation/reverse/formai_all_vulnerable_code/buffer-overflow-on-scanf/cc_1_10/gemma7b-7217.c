//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0, 255},
    {"Green", 0, 255, 0, 255},
    {"Blue", 0, 0, 255, 255},
    {"Yellow", 255, 255, 0, 255},
    {"Cyan", 0, 255, 255, 255},
    {"Magenta", 255, 0, 255, 255},
    {"Black", 0, 0, 0, 255},
    {"White", 255, 255, 255, 255},
    {"Gray", 128, 128, 128, 255},
    {"Olive", 128, 128, 0, 255}
};

void convert_color(Color *color)
{
    // Convert color values to RGB values
    color->red = (color->red * 255) / 100;
    color->green = (color->green * 255) / 100;
    color->blue = (color->blue * 255) / 100;
}

int main()
{
    Color color;

    // Get the color name from the user
    printf("Enter the color name: ");
    scanf("%s", color.name);

    // Find the color in the list
    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(color.name, colors[i].name) == 0)
        {
            color = colors[i];
            break;
        }
    }

    // Convert the color to RGB values
    convert_color(&color);

    // Print the RGB values
    printf("RGB values: %d, %d, %d\n", color.red, color.green, color.blue);

    return 0;
}