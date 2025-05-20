//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
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
    {"Cyan", 0, 255, 255, 255},
    {"Magenta", 255, 0, 255, 255},
    {"Black", 0, 0, 0, 255},
    {"White", 255, 255, 255, 255},
    {"Orange", 255, 165, 0, 255},
    {"Purple", 128, 0, 128, 255}
};

void convert_color(char *color_name, int *r, int *g, int *b, int *a)
{
    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            *r = colors[i].r;
            *g = colors[i].g;
            *b = colors[i].b;
            *a = colors[i].a;
            return;
        }
    }

    printf("Error: Color name not found.\n");
    *r = *g = *b = *a = -1;
}

int main()
{
    char color_name[20];
    int r, g, b, a;

    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    convert_color(color_name, &r, &g, &b, &a);

    if (r != -1 && g != -1 && b != -1 && a != -1)
    {
        printf("Red: %d, Green: %d, Blue: %d, Alpha: %d\n", r, g, b, a);
    }
    else
    {
        printf("Error converting color.\n");
    }

    return 0;
}