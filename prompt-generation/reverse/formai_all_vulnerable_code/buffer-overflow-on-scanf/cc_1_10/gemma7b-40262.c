//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10
#define MAX_COLOR_NAME_LENGTH 20

typedef struct Color
{
    char name[MAX_COLOR_NAME_LENGTH];
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
    {"Orange", 255, 165, 0, 255},
    {"Purple", 128, 0, 128, 255},
    {"Pink", 255, 192, 203, 255},
    {"Grey", 128, 128, 128, 255}
};

int main()
{
    char input_color_name[MAX_COLOR_NAME_LENGTH];
    int target_color_index;
    int r, g, b, a;

    printf("Enter the name of the color you want to convert: ");
    scanf("%s", input_color_name);

    target_color_index = find_color_index(input_color_name);

    if (target_color_index == -1)
    {
        printf("Error: Color not found.\n");
        return 1;
    }

    r = colors[target_color_index].r;
    g = colors[target_color_index].g;
    b = colors[target_color_index].b;
    a = colors[target_color_index].a;

    printf("The RGB and A values for the color %s are:\n", colors[target_color_index].name);
    printf("R: %d\n", r);
    printf("G: %d\n", g);
    printf("B: %d\n", b);
    printf("A: %d\n", a);

    return 0;
}

int find_color_index(char *color_name)
{
    int i;

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(color_name, colors[i].name) == 0)
        {
            return i;
        }
    }

    return -1;
}