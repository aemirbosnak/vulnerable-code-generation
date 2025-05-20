//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

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
    {"Gray", 128, 128, 128, 255},
    {"Olive", 128, 255, 0, 255}
};

void convert_color(Color *color, char *color_name)
{
    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(color_name, colors[i].name) == 0)
        {
            color->r = colors[i].r;
            color->g = colors[i].g;
            color->b = colors[i].b;
            color->a = colors[i].a;
            break;
        }
    }
}

int main()
{
    Color color;
    char color_name[20];

    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    convert_color(&color, color_name);

    printf("Red: %d\n", color.r);
    printf("Green: %d\n", color.g);
    printf("Blue: %d\n", color.b);
    printf("Alpha: %d\n", color.a);

    return 0;
}