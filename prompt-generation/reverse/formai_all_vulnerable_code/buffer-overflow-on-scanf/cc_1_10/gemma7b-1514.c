//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r, g, b, a;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0, 255},
    {"Green", 0, 255, 0, 255},
    {"Blue", 0, 0, 255, 255},
    {"Yellow", 255, 255, 0, 255},
    {"Orange", 255, 165, 0, 255},
    {"Purple", 128, 0, 128, 255},
    {"Pink", 255, 192, 203, 255},
    {"Sky", 135, 206, 235, 255},
    {"Olive", 128, 128, 0, 255},
    {"Brown", 160, 120, 0, 255}
};

int main()
{
    char color_name[20];
    int r, g, b, a;

    printf("Welcome to the Enchanted Color Converter!\n");
    printf("Please enter the name of a color: ");
    scanf("%s", color_name);

    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            r = colors[i].r;
            g = colors[i].g;
            b = colors[i].b;
            a = colors[i].a;
            break;
        }
    }

    if (r == -1)
    {
        printf("Error: Color not found.\n");
    }
    else
    {
        printf("The color %s is equivalent to:\n", color_name);
        printf("R: %d, G: %d, B: %d, A: %d\n", r, g, b, a);
    }

    return 0;
}