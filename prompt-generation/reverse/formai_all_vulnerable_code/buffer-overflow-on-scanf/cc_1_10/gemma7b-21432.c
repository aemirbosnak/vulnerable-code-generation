//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r;
    int g;
    int b;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Orange", 255, 165, 0},
    {"Purple", 128, 0, 128},
    {"Pink", 255, 192, 203},
    {"Sky", 135, 206, 235},
    {"Brown", 160, 120, 0},
    {"Gray", 128, 128, 128}
};

int main()
{
    int i;
    printf("Enter the color name: ");
    char color_name[20];
    scanf("%s", color_name);

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            printf("R: %d, G: %d, B: %d\n", colors[i].r, colors[i].g, colors[i].b);
            break;
        }
    }

    if (i == MAX_COLORS)
    {
        printf("Error: Color not found.\n");
    }

    return 0;
}