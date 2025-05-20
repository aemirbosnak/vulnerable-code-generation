//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char r_color, j_color;
    int rgb_r, rgb_g, rgb_b;

    printf("Enter the Romeo color (R/G/B): ");
    scanf("%c", &r_color);

    printf("Enter the Juliet color (R/G/B): ");
    scanf("%c", &j_color);

    switch (r_color)
    {
        case 'R':
            rgb_r = 255;
            rgb_g = 0;
            rgb_b = 0;
            break;
        case 'G':
            rgb_r = 0;
            rgb_g = 255;
            rgb_b = 0;
            break;
        case 'B':
            rgb_r = 0;
            rgb_g = 0;
            rgb_b = 255;
            break;
        default:
            printf("Invalid color input.\n");
            return 1;
    }

    switch (j_color)
    {
        case 'R':
            rgb_r = 255;
            rgb_g = 0;
            rgb_b = 0;
            break;
        case 'G':
            rgb_r = 0;
            rgb_g = 255;
            rgb_b = 0;
            break;
        case 'B':
            rgb_r = 0;
            rgb_g = 0;
            rgb_b = 255;
            break;
        default:
            printf("Invalid color input.\n");
            return 1;
    }

    printf("The Romeo and Juliet colors are:\n");
    printf("RGB: (%d, %d, %d)\n", rgb_r, rgb_g, rgb_b);

    return 0;
}