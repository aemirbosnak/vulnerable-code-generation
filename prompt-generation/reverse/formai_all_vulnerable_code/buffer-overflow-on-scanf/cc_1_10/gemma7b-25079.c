//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r, g, b, a;
} Color;

Color colors[MAX_COLORS] = {
    {"Red", 255, 0, 0, 255},
    {"Green", 0, 255, 0, 255},
    {"Blue", 0, 0, 255, 255},
    {"Yellow", 255, 255, 0, 255},
    {"Cyan", 0, 255, 255, 255},
    {"Magenta", 255, 0, 255, 255},
    {"Orange", 255, 165, 0, 255},
    {"Purple", 128, 0, 128, 255},
    {"Sky", 135, 206, 235, 255},
    {"Maroon", 160, 40, 40, 255}
};

void convert_color(char *color_name)
{
    int i = 0;
    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, color_name) == 0)
        {
            printf("RGB: (%d, %d, %d), A: (%d)\n", colors[i].r, colors[i].g, colors[i].b, colors[i].a);
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