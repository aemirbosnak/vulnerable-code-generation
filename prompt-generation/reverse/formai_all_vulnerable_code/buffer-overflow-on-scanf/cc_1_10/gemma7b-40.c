//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    int r, g, b, a;
} Color;

Color convert_color(char color_code)
{
    Color color;

    switch (color_code)
    {
        case 'r':
            color.r = 255;
            color.g = 0;
            color.b = 0;
            color.a = 255;
            break;
        case 'g':
            color.r = 0;
            color.g = 255;
            color.b = 0;
            color.a = 255;
            break;
        case 'b':
            color.r = 0;
            color.g = 0;
            color.b = 255;
            color.a = 255;
            break;
        case 'a':
            color.r = 0;
            color.g = 0;
            color.b = 0;
            color.a = 0;
            break;
        default:
            printf("Invalid color code.\n");
            exit(1);
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
    printf("Alpha: %d\n", color.a);

    return 0;
}