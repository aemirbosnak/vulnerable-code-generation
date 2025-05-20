//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c_color;
    int r, g, b, a;

    printf("Enter the color code (e.g. rgb or rgba): ");
    scanf("%s", &c_color);

    switch (c_color)
    {
        case 'r':
            printf("Enter the red value (0-255): ");
            scanf("%d", &r);
            g = 0;
            b = 0;
            a = 255;
            break;
        case 'g':
            printf("Enter the green value (0-255): ");
            scanf("%d", &g);
            r = 0;
            b = 0;
            a = 255;
            break;
        case 'b':
            printf("Enter the blue value (0-255): ");
            scanf("%d", &b);
            r = 0;
            g = 0;
            a = 255;
            break;
        case 'a':
            printf("Enter the alpha value (0-255): ");
            scanf("%d", &a);
            r = 0;
            g = 0;
            b = 0;
            break;
        default:
            printf("Invalid color code.\n");
            return 1;
    }

    printf("The color code is: rgba(%d, %d, %d, %d)\n", r, g, b, a);

    return 0;
}