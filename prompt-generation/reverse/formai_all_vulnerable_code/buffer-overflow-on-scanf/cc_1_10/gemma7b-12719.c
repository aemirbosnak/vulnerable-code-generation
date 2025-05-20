//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

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
    {"Purple", 165, 0, 255, 255},
    {"Pink", 255, 192, 203, 255},
    {"Sky", 135, 206, 235, 255},
    {"Mint", 180, 230, 180, 255},
    {"Gray", 128, 128, 128, 255}
};

int main()
{
    int i, j, k;
    char input[20];
    Color current_color;

    printf("Enter the name of the color: ");
    scanf("%s", input);

    for (i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(colors[i].name, input) == 0)
        {
            current_color = colors[i];
            break;
        }
    }

    if (current_color.name == NULL)
    {
        printf("Error: color not found.\n");
        return 1;
    }

    printf("Red: %d\n", current_color.red);
    printf("Green: %d\n", current_color.green);
    printf("Blue: %d\n", current_color.blue);
    printf("Alpha: %d\n", current_color.alpha);

    return 0;
}