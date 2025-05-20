//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char colorCode[8];
    int red, green, blue;
    float hue, saturation, value;
    char *colorName;

    // Get color code input from user
    printf("Enter a color code in hexadecimal format (e.g. #FF0000): ");
    scanf("%s", colorCode);

    // Convert hexadecimal color code to RGB values
    sscanf(colorCode, "#%02X%02X%02X", &red, &green, &blue);

    // Convert RGB values to HSV values
    hue = (float)red / 255.0;
    saturation = (float)green / 255.0;
    value = (float)blue / 255.0;

    // Convert HSV values to color name
    if (value == 1.0)
    {
        if (saturation == 0.0)
        {
            colorName = "Black";
        }
        else
        {
            colorName = "White";
        }
    }
    else if (saturation == 0.0)
    {
        colorName = "Gray";
    }
    else if (hue < 0.5)
    {
        colorName = "Red";
    }
    else if (hue < 1.0)
    {
        colorName = "Yellow";
    }
    else if (hue < 1.5)
    {
        colorName = "Green";
    }
    else if (hue < 2.0)
    {
        colorName = "Cyan";
    }
    else if (hue < 2.5)
    {
        colorName = "Blue";
    }
    else if (hue < 3.0)
    {
        colorName = "Magenta";
    }
    else
    {
        colorName = "Red";
    }

    // Print color name and RGB values
    printf("Color name: %s\n", colorName);
    printf("RGB values: %d, %d, %d\n", red, green, blue);

    return 0;
}