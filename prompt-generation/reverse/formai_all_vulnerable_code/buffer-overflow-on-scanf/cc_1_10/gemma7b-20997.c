//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    int r;
    int g;
    int b;
} Color;

Color convert_color(int color_code)
{
    Color color;

    switch (color_code)
    {
        case 0:
            color.r = 0;
            color.g = 0;
            color.b = 0;
            break;
        case 1:
            color.r = 255;
            color.g = 0;
            color.b = 0;
            break;
        case 2:
            color.r = 0;
            color.g = 255;
            color.b = 0;
            break;
        case 3:
            color.r = 0;
            color.g = 0;
            color.b = 255;
            break;
        default:
            color.r = 0;
            color.g = 0;
            color.b = 0;
    }

    return color;
}

int main()
{
    int color_code;

    printf("Enter a color code (0-3): ");
    scanf("%d", &color_code);

    Color color = convert_color(color_code);

    printf("Red: %d\n", color.r);
    printf("Green: %d\n", color.g);
    printf("Blue: %d\n", color.b);

    return 0;
}