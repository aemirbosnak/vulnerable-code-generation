//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: protected
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
    {"Olive", 128, 128, 0, 255}
};

int main()
{
    int i, color_index;
    char color_name[20];

    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            color_index = i;
            break;
        }
    }

    if (color_index == -1)
    {
        printf("Error: Color not found.\n");
    }
    else
    {
        printf("The color index is: %d\n", color_index);
        printf("The color RGB values are: (%d, %d, %d)\n", colors[color_index].r, colors[color_index].g, colors[color_index].b);
    }

    return 0;
}