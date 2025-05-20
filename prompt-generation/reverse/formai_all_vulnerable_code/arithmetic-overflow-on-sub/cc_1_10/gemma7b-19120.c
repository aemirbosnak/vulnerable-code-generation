//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int red, green, blue, hue, sat, val;
    char symbol;

    printf("Enter the symbol of the color you want to convert: ");
    scanf("%c", &symbol);

    switch (symbol)
    {
        case 'r':
            printf("Enter the red value: ");
            scanf("%d", &red);

            green = (red / 3) - 10;
            blue = (red * 2) - green;
            hue = 0;
            sat = 255;
            val = red;
            break;

        case 'g':
            printf("Enter the green value: ");
            scanf("%d", &green);

            red = (green + 10) * 3;
            blue = 255 - red - green;
            hue = 120;
            sat = 255;
            val = green;
            break;

        case 'b':
            printf("Enter the blue value: ");
            scanf("%d", &blue);

            red = (255 - blue) / 2;
            green = (255 - red - blue) / 3;
            hue = 240;
            sat = 255;
            val = blue;
            break;

        default:
            printf("Invalid symbol.\n");
            break;
    }

    printf("Hue: %d\n", hue);
    printf("Saturation: %d\n", sat);
    printf("Value: %d\n", val);

    return 0;
}