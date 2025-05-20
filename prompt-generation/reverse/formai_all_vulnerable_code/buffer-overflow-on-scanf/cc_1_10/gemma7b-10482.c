//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: irregular
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
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Orange", 255, 165, 0},
    {"Pink", 255, 192, 203},
    {"Lavender", 238, 238, 238},
    {"Sky Blue", 135, 206, 235},
    {"Maroon", 160, 40, 40},
    {"Olive", 128, 128, 0}
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
            printf("Red: %d\n", colors[i].red);
            printf("Green: %d\n", colors[i].green);
            printf("Blue: %d\n", colors[i].blue);
            break;
        }
    }

    if (i == MAX_COLORS)
    {
        printf("Error: Color not found.\n");
    }

    return 0;
}