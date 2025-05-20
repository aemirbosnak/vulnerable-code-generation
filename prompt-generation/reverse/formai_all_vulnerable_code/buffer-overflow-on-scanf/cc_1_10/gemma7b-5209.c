//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
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
    {"Orange", 255, 165, 0},
    {"Pink", 255, 192, 203},
    {"Gray", 128, 128, 128},
    {"Black", 0, 0, 0}
};

int main()
{
    char input[20];
    int i, color_index;

    printf("Enter the name of a color: ");
    scanf("%s", input);

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, input) == 0)
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
        printf("The RGB values are: R: %d, G: %d, B: %d\n", colors[color_index].r, colors[color_index].g, colors[color_index].b);
    }

    return 0;
}