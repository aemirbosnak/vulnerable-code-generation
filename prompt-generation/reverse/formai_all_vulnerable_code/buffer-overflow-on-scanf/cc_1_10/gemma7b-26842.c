//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE 255

typedef struct Color
{
    int red;
    int green;
    int blue;
    int alpha;
} Color;

Color convert_color_code(char *code)
{
    Color color;

    // Validate the color code
    if (!code || strlen(code) < 3)
    {
        return color;
    }

    // Convert the color code to integers
    color.red = atoi(code);
    color.green = atoi(code + 2);
    color.blue = atoi(code + 4);
    color.alpha = atoi(code + 6);

    return color;
}

int main()
{
    char color_code[MAX_COLOR_CODE];

    // Get the color code from the user
    printf("Enter a color code: ");
    scanf("%s", color_code);

    // Convert the color code to a Color struct
    Color color = convert_color_code(color_code);

    // Print the converted color code
    printf("Red: %d\n", color.red);
    printf("Green: %d\n", color.green);
    printf("Blue: %d\n", color.blue);
    printf("Alpha: %d\n", color.alpha);

    return 0;
}