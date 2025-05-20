//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char name[20];
    int r, g, b, a;
} Color;

void color_converter(Color *color)
{
    printf("Color name: %s\n", color->name);
    printf("Red: %d\n", color->r);
    printf("Green: %d\n", color->g);
    printf("Blue: %d\n", color->b);
    printf("Alpha: %d\n", color->a);
}

int main()
{
    Color colors[MAX_COLORS];

    // Initialize the colors array
    for (int i = 0; i < MAX_COLORS; i++)
    {
        colors[i].name[0] = '\0';
        colors[i].r = 0;
        colors[i].g = 0;
        colors[i].b = 0;
        colors[i].a = 0;
    }

    // Get the color name, red, green, blue, and alpha from the user
    printf("Enter the color name: ");
    scanf("%s", colors[0].name);

    printf("Enter the red value: ");
    scanf("%d", &colors[0].r);

    printf("Enter the green value: ");
    scanf("%d", &colors[0].g);

    printf("Enter the blue value: ");
    scanf("%d", &colors[0].b);

    printf("Enter the alpha value: ");
    scanf("%d", &colors[0].a);

    // Convert the color to a string
    color_converter(&colors[0]);

    return 0;
}