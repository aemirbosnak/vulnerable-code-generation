//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char c_color_code[20];
    printf("Enter a color code (e.g. rgb or hsl): ");
    scanf("%s", c_color_code);

    int r, g, b, h, s;
    switch (c_color_code[0])
    {
        case 'r':
            printf("Enter the red value (0-255): ");
            scanf("%d", &r);
            g = b = h = s = 0;
            break;
        case 'g':
            printf("Enter the green value (0-255): ");
            scanf("%d", &g);
            r = b = h = s = 0;
            break;
        case 'b':
            printf("Enter the blue value (0-255): ");
            scanf("%d", &b);
            r = g = h = s = 0;
            break;
        case 'h':
            printf("Enter the hue value (0-360): ");
            scanf("%d", &h);
            printf("Enter the saturation value (0-100): ");
            scanf("%d", &s);
            r = g = b = 0;
            break;
    }

    int converted_color_code[3];
    converted_color_code[0] = r;
    converted_color_code[1] = g;
    converted_color_code[2] = b;

    printf("Converted color code: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d,", converted_color_code[i]);
    }
    printf("\n");

    return 0;
}