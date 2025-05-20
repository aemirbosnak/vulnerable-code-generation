//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 10

typedef struct Color
{
    char r;
    char g;
    char b;
} Color;

Color getColorFromUser()
{
    Color color;

    printf("Enter the red value (0-255): ");
    scanf("%d", &color.r);

    printf("Enter the green value (0-255): ");
    scanf("%d", &color.g);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &color.b);

    return color;
}

void printColor(Color color)
{
    printf("Color: (R, G, B) = (%d, %d, %d)\n", color.r, color.g, color.b);
}

int main()
{
    Color color1, color2;

    // Get the first color from the user
    color1 = getColorFromUser();

    // Get the second color from the user
    color2 = getColorFromUser();

    // Print the colors
    printColor(color1);
    printColor(color2);

    // Compare the colors
    if (color1.r == color2.r && color1.g == color2.g && color1.b == color2.b)
    {
        printf("The colors are the same.\n");
    }
    else
    {
        printf("The colors are not the same.\n");
    }

    return 0;
}