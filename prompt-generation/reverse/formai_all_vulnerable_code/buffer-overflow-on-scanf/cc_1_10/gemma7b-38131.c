//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c_color;
    int r, g, b;

    printf("Enter the color code (R, G, B): ");
    scanf("%c", &c_color);

    switch (c_color)
    {
        case 'R':
            r = 255;
            g = 0;
            b = 0;
            break;
        case 'G':
            r = 0;
            g = 255;
            b = 0;
            break;
        case 'B':
            r = 0;
            g = 0;
            b = 255;
            break;
        case 'Y':
            r = 255;
            g = 255;
            b = 0;
            break;
        case 'C':
            r = 255;
            g = 0;
            b = 255;
            break;
        case 'M':
            r = 0;
            g = 255;
            b = 255;
            break;
        default:
            printf("Invalid color code.\n");
            return 1;
    }

    printf("The color code is: (%d, %d, %d)\n", r, g, b);

    return 0;
}