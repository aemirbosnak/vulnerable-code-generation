//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 256

typedef struct Color
{
    int r;
    int g;
    int b;
} Color;

Color convert_color(char color_code)
{
    Color color;

    switch (color_code)
    {
        case 'r':
            color.r = MAX_COLORS;
            color.g = 0;
            color.b = 0;
            break;
        case 'g':
            color.r = 0;
            color.g = MAX_COLORS;
            color.b = 0;
            break;
        case 'b':
            color.r = 0;
            color.g = 0;
            color.b = MAX_COLORS;
            break;
        case 'c':
            color.r = MAX_COLORS / 2;
            color.g = MAX_COLORS / 2;
            color.b = MAX_COLORS / 2;
            break;
        default:
            color.r = 0;
            color.g = 0;
            color.b = 0;
            break;
    }

    return color;
}

int main()
{
    char color_code;

    printf("Enter a color code: ");
    scanf("%c", &color_code);

    Color color = convert_color(color_code);

    printf("Red: %d\n", color.r);
    printf("Green: %d\n", color.g);
    printf("Blue: %d\n", color.b);

    return 0;
}