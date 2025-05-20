//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int red, green, blue;
    printf("Enter the decimal RGB values: ");
    scanf("%d %d %d", &red, &green, &blue);

    // Convert decimal RGB values to hexadecimal values
    int hex_red = red / 16;
    int hex_red_rem = red % 16;

    int hex_green = green / 16;
    int hex_green_rem = green % 16;

    int hex_blue = blue / 16;
    int hex_blue_rem = blue % 16;

    // Convert hexadecimal values to color code
    char color_red, color_green, color_blue;

    // Convert hexadecimal red value to color code
    if (hex_red < 10)
        color_red = hex_red + '0';
    else
        color_red = hex_red + 55;

    if (hex_red_rem < 10)
        color_red = color_red * 10 + hex_red_rem + '0';
    else
        color_red = color_red * 10 + hex_red_rem + 55;

    // Convert hexadecimal green value to color code
    if (hex_green < 10)
        color_green = hex_green + '0';
    else
        color_green = hex_green + 55;

    if (hex_green_rem < 10)
        color_green = color_green * 10 + hex_green_rem + '0';
    else
        color_green = color_green * 10 + hex_green_rem + 55;

    // Convert hexadecimal blue value to color code
    if (hex_blue < 10)
        color_blue = hex_blue + '0';
    else
        color_blue = hex_blue + 55;

    if (hex_blue_rem < 10)
        color_blue = color_blue * 10 + hex_blue_rem + '0';
    else
        color_blue = color_blue * 10 + hex_blue_rem + 55;

    printf("RGB values: %d, %d, %d\n", red, green, blue);
    printf("Color code: #%c%c%c\n", color_red, color_green, color_blue);

    return 0;
}