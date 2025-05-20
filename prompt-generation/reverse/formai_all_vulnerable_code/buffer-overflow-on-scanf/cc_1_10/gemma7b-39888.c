//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int red;
    int green;
    int blue;
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

void convert_color(char *color_name)
{
    int i;
    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(color_name, colors[i].name) == 0)
        {
            printf("Red: %d, Green: %d, Blue: %d\n", colors[i].red, colors[i].green, colors[i].blue);
            return;
        }
    }

    printf("Error: Color name not found.\n");
}

int main()
{
    char color_name[20];

    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    convert_color(color_name);

    return 0;
}