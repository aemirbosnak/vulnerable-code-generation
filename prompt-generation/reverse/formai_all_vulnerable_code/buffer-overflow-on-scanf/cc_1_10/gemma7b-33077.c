//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    {"White", 255, 255, 255, 255},
    {"Gray", 128, 128, 128, 255},
    {"Olive", 128, 255, 0, 255}
};

int main()
{
    char input[20];
    int i;

    printf("Enter a color name: ");
    scanf("%s", input);

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, input) == 0)
        {
            printf("Red: %d\n", colors[i].red);
            printf("Green: %d\n", colors[i].green);
            printf("Blue: %d\n", colors[i].blue);
            printf("Alpha: %d\n", colors[i].alpha);
            break;
        }
    }

    if (i == MAX_COLORS)
    {
        printf("Error: color not found.\n");
    }

    return 0;
}