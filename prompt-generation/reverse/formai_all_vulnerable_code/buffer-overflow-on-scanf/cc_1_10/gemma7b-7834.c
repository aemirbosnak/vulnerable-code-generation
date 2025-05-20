//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r;
    int g;
    int b;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255}
};

int main()
{
    int i, color_index, r, g, b;

    printf("Enter the color index: ");
    scanf("%d", &color_index);

    if (color_index < 0 || color_index >= MAX_COLORS)
    {
        printf("Invalid color index.\n");
        return 1;
    }

    printf("Enter the red value: ");
    scanf("%d", &r);

    printf("Enter the green value: ");
    scanf("%d", &g);

    printf("Enter the blue value: ");
    scanf("%d", &b);

    colors[color_index].r = r;
    colors[color_index].g = g;
    colors[color_index].b = b;

    printf("Color updated.\n");

    return 0;
}