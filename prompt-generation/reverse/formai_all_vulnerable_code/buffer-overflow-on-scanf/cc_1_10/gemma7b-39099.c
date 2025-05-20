//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char input;
    int red, green, blue, hue, saturation, value;

    printf("Enter the color code (R, G, B, H, S, V): ");
    scanf("%c", &input);

    switch (input)
    {
        case 'R':
            printf("Enter the red value (0-255): ");
            scanf("%d", &red);
            green = 0;
            blue = 0;
            hue = 0;
            saturation = 0;
            value = red;
            break;
        case 'G':
            printf("Enter the green value (0-255): ");
            scanf("%d", &green);
            red = 0;
            blue = 0;
            hue = 0;
            saturation = 0;
            value = green;
            break;
        case 'B':
            printf("Enter the blue value (0-255): ");
            scanf("%d", &blue);
            red = 0;
            green = 0;
            hue = 0;
            saturation = 0;
            value = blue;
            break;
        case 'H':
            printf("Enter the hue value (0-360): ");
            scanf("%d", &hue);
            red = 0;
            green = 0;
            blue = 0;
            saturation = 0;
            value = 0;
            break;
        case 'S':
            printf("Enter the saturation value (0-100): ");
            scanf("%d", &saturation);
            red = 0;
            green = 0;
            blue = 0;
            hue = 0;
            value = 0;
            break;
        case 'V':
            printf("Enter the value value (0-255): ");
            scanf("%d", &value);
            red = 0;
            green = 0;
            blue = 0;
            hue = 0;
            saturation = 0;
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    printf("Color code conversion:\n");
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);
    printf("Hue: %d\n", hue);
    printf("Saturation: %d\n", saturation);
    printf("Value: %d\n", value);
}