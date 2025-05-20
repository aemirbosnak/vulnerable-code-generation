//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 16

typedef struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color convert_color(char *color_name)
{
    Color color;

    // Create a map of color names to their RGB values
    static char *color_names[] = {"black", "white", "red", "green", "blue", "yellow", "cyan", "magenta", "gray", "orange", "aqua", "violet", "olive", "azure", "lime", "teal"};
    static Color color_values[] = {{0, 0, 0, 255},
    {255, 255, 255, 255},
    {255, 0, 0, 255},
    {0, 255, 0, 255},
    {0, 0, 255, 255},
    {255, 255, 0, 255},
    {0, 255, 255, 255},
    {255, 0, 255, 255},
    {128, 128, 128, 255},
    {255, 165, 0, 255},
    {0, 255, 255, 255},
    {128, 0, 0, 255},
    {0, 128, 255, 255},
    {0, 255, 128, 255},
    {128, 255, 128, 255}};

    // Iterate over the color names and see if the input color name matches any of them
    for (int i = 0; i < MAX_COLORS; i++)
    {
        if (strcmp(color_name, color_names[i]) == 0)
        {
            // If the color name is found, copy the corresponding RGB values into the color structure
            color = color_values[i];
            break;
        }
    }

    // If the color name is not found, return an error
    if (color.red == -1)
    {
        printf("Error: Invalid color name.\n");
        exit(1);
    }

    return color;
}

int main()
{
    // Get the color name from the user
    char color_name[255];
    printf("Enter the name of a color: ");
    scanf("%s", color_name);

    // Convert the color name to a Color structure
    Color color = convert_color(color_name);

    // Print the RGB values of the color
    printf("Red: %d\n", color.red);
    printf("Green: %d\n", color.green);
    printf("Blue: %d\n", color.blue);
    printf("Alpha: %d\n", color.alpha);

    return 0;
}