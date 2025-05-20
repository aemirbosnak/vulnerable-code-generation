//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r, g, b, a;
} Color;

Color colors[MAX_COLORS];

void convertToRGB(char *color)
{
    int i = 0;
    char *p = color;
    while (*p)
    {
        switch (*p)
        {
            case 'r':
                colors[i].r = atoi(p + 1);
                break;
            case 'g':
                colors[i].g = atoi(p + 1);
                break;
            case 'b':
                colors[i].b = atoi(p + 1);
                break;
            case 'a':
                colors[i].a = atoi(p + 1);
                break;
            default:
                break;
        }
        p++;
        i++;
    }
}

int main()
{
    char color_str[] = "rgb(255, 255, 0), rgba(255, 255, 0, 0.5)";

    convertToRGB(color_str);

    for (int i = 0; i < MAX_COLORS; i++)
    {
        printf("Color: %s, RGB: (%d, %d, %d), Alpha: %d\n", colors[i].name, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
    }

    return 0;
}