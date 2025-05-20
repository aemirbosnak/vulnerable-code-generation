//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: expert-level
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
    {"Black", 0, 0, 0, 0},
    {"White", 255, 255, 255, 255},
    {"Gray", 128, 128, 128, 255},
    {"Orange", 255, 165, 0, 255}
};

int main()
{
    char input[20];
    int i;

    printf("Enter the name of a color: ");
    scanf("%s", input);

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, input) == 0)
        {
            printf("Red: %d, Green: %d, Blue: %d, Alpha: %d\n", colors[i].r, colors[i].g, colors[i].b, colors[i].a);
            break;
        }
    }

    if (i == MAX_COLORS)
    {
        printf("Error: Color not found.\n");
    }

    return 0;
}