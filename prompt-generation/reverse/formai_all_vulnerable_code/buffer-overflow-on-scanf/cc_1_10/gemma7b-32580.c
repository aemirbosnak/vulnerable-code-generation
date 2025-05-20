//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>

int main()
{
    char input_color[20];
    int red, green, blue, yellow;

    printf("Enter the color name: ");
    scanf("%s", input_color);

    // Convert the color name to RGB values
    switch (input_color[0])
    {
        case 'R':
            red = 255;
            green = 0;
            blue = 0;
            yellow = 0;
            break;
        case 'G':
            red = 0;
            green = 255;
            blue = 0;
            yellow = 0;
            break;
        case 'B':
            red = 0;
            green = 0;
            blue = 255;
            yellow = 0;
            break;
        case 'Y':
            red = 255;
            green = 255;
            blue = 0;
            yellow = 255;
            break;
        default:
            red = 0;
            green = 0;
            blue = 0;
            yellow = 0;
            break;
    }

    // Print the RGB values
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
    printf("Yellow: %d\n", yellow);

    return 0;
}