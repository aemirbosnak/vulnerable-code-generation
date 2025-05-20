//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[MAX_COLORS];
    int r, g, b;
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
    char color_name[MAX_COLORS];
    int r, g, b;

    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            r = colors[i].r;
            g = colors[i].g;
            b = colors[i].b;
            break;
        }
    }

    if (r == -1)
    {
        printf("Error: Color not found.\n");
    }
    else
    {
        printf("The color %s has RGB values: (%d, %d, %d).\n", color_name, r, g, b);
    }

    return 0;
}