//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int red, green, blue, hue, saturation, value, i;
    char c;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter the color code you want to convert (R,G,B,H,S,V): ");
    scanf("%c", &c);

    switch (c)
    {
        case 'R':
            printf("Enter the red value (0-255): ");
            scanf("%d", &red);
            green = (red - 32) * 1.11111;
            blue = (red - 32) * 1.11111;
            hue = 0;
            saturation = 100;
            value = red;
            break;
        case 'G':
            printf("Enter the green value (0-255): ");
            scanf("%d", &green);
            red = (green - 32) * 1.11111 + 32;
            blue = (green - 32) * 1.11111 + 32;
            hue = 0;
            saturation = 100;
            value = green;
            break;
        case 'B':
            printf("Enter the blue value (0-255): ");
            scanf("%d", &blue);
            red = (blue - 32) * 1.11111 + 32;
            green = (blue - 32) * 1.11111 + 32;
            hue = 0;
            saturation = 100;
            value = blue;
            break;
        case 'H':
            printf("Enter the hue value (0-360): ");
            scanf("%d", &hue);
            red = (hue * 1.11111) + 32;
            green = (hue * 1.11111) + 32;
            blue = (hue * 1.11111) + 32;
            saturation = 100;
            value = 255;
            break;
        case 'S':
            printf("Enter the saturation value (0-100): ");
            scanf("%d", &saturation);
            red = 255;
            green = 255;
            blue = 255;
            hue = 0;
            value = 255 - saturation * 2.55;
            break;
        case 'V':
            printf("Enter the value value (0-255): ");
            scanf("%d", &value);
            red = value;
            green = value;
            blue = value;
            hue = 0;
            saturation = 100;
            break;
    }

    printf("Your converted color code is:\n");
    printf("R: %d\n", red);
    printf("G: %d\n", green);
    printf("B: %d\n", blue);
    printf("H: %d\n", hue);
    printf("S: %d\n", saturation);
    printf("V: %d\n", value);

    return 0;
}