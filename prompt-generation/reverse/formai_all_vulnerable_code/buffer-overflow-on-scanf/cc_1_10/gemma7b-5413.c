//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int red, green, blue, alpha;
} Color;

Color colors[MAX_COLORS] =
{
    {"Red", 255, 0, 0, 255},
    {"Green", 0, 255, 0, 255},
    {"Blue", 0, 0, 255, 255},
    {"Yellow", 255, 255, 0, 255},
    {"Orange", 255, 165, 0, 255},
    {"Purple", 128, 0, 128, 255},
    {"Pink", 255, 192, 203, 255},
    {"Gray", 128, 128, 128, 255},
    {"Cyan", 0, 255, 255, 255},
    {"Black", 0, 0, 0, 255}
};

int main()
{
    int i, color_index, red, green, blue, alpha;
    char color_name[20];

    printf("Enter the name of the color: ");
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
        return 1;
    }

    printf("Enter the red value (0-255): ");
    scanf("%d", &red);
    colors[color_index].red = red;

    printf("Enter the green value (0-255): ");
    scanf("%d", &green);
    colors[color_index].green = green;

    printf("Enter the blue value (0-255): ");
    scanf("%d", &blue);
    colors[color_index].blue = blue;

    printf("Enter the alpha value (0-255): ");
    scanf("%d", &alpha);
    colors[color_index].alpha = alpha;

    printf("Color updated.\n");

    return 0;
}