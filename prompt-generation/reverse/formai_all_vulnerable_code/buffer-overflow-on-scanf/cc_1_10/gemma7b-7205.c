//Gemma-7B DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void color_code_converter(int r, int g, int b)
{
    int rgb_sum = r + g + b;
    int color_index = rgb_sum / 3;

    switch (color_index)
    {
        case 0:
            printf("The color code is: RGB(0,0,0)\n");
            break;
        case 1:
            printf("The color code is: RGB(255,0,0)\n");
            break;
        case 2:
            printf("The color code is: RGB(255,255,0)\n");
            break;
        case 3:
            printf("The color code is: RGB(0,255,0)\n");
            break;
        case 4:
            printf("The color code is: RGB(0,255,255)\n");
            break;
        case 5:
            printf("The color code is: RGB(255,255,255)\n");
            break;
        default:
            printf("Invalid color code.\n");
            break;
    }
}

int main()
{
    int r, g, b;

    printf("Enter the red value (0-255): ");
    scanf("%d", &r);

    printf("Enter the green value (0-255): ");
    scanf("%d", &g);

    printf("Enter the blue value (0-255): ");
    scanf("%d", &b);

    color_code_converter(r, g, b);

    return 0;
}