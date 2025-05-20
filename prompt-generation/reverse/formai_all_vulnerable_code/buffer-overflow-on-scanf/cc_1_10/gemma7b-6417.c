//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0, 255},
    {"Green", 0, 255, 0, 255},
    {"Blue", 0, 0, 255, 255},
    {"Yellow", 255, 255, 0, 255},
    {"Cyan", 0, 255, 255, 255},
    {"Magenta", 255, 0, 255, 255},
    {"Black", 0, 0, 0, 0},
    {"White", 255, 255, 255, 255}
};

int main()
{
    int color_index;
    char color_name[20];

    printf("Enter the name of the color: ");
    scanf("%s", color_name);

    color_index = search_color(color_name);

    if (color_index == -1)
    {
        printf("Error: Color not found.\n");
    }
    else
    {
        printf("Color index: %d\n", color_index);
        printf("Red: %d\n", colors[color_index].red);
        printf("Green: %d\n", colors[color_index].green);
        printf("Blue: %d\n", colors[color_index].blue);
        printf("Alpha: %d\n", colors[color_index].alpha);
    }

    return 0;
}

int search_color(char *color_name)
{
    int i;

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            return i;
        }
    }

    return -1;
}