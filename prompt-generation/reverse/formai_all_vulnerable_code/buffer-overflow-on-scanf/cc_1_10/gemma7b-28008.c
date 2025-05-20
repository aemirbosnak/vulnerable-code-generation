//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_CODE 255

typedef struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color convert_color_code(int code)
{
    Color color;

    if (code >= MAX_COLOR_CODE)
    {
        color.red = MAX_COLOR_CODE;
        color.green = MAX_COLOR_CODE;
        color.blue = MAX_COLOR_CODE;
        color.alpha = MAX_COLOR_CODE;
    }
    else
    {
        color.red = code / 256;
        color.green = (code % 256) / 256;
        color.blue = (code % 256) % 256;
        color.alpha = 255;
    }

    return color;
}

int main()
{
    int code;

    printf("Enter a color code: ");
    scanf("%d", &code);

    Color color = convert_color_code(code);

    printf("Red: %d\n", color.red);
    printf("Green: %d\n", color.green);
    printf("Blue: %d\n", color.blue);
    printf("Alpha: %d\n", color.alpha);

    return 0;
}