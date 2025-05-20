//FormAI DATASET v1.0 Category: Color Code Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float red, green, blue, cyan, magenta, yellow, black;

    printf("Welcome to the Color Code Converter!\n");
    printf("-----------------------------\n\n");

    printf("What would you like to convert?\n");
    printf("1. RGB to CMYK\n");
    printf("2. CMYK to RGB\n");
    scanf("%d", &choice);

    if(choice == 1) // RGB to CMYK
    {
        printf("Enter the values of the red, green, and blue channels (0-255)\n");
        scanf("%f %f %f", &red, &green, &blue);

        // Convert RGB values to percentages
        float percentRed = red / 255;
        float percentGreen = green / 255;
        float percentBlue = blue / 255;

        // Determine the maximum value of the RGB channels
        float max = percentRed;
        if(percentGreen > max)
        {
            max = percentGreen;
        }
        if(percentBlue > max)
        {
            max = percentBlue;
        }

        // Calculate CMYK values
        cyan = (max - percentRed) / max;
        magenta = (max - percentGreen) / max;
        yellow = (max - percentBlue) / max;
        black = 1 - max;

        printf("\nCMYK values: %.2f %.2f %.2f %.2f", cyan, magenta, yellow, black);
    }
    else if(choice == 2) // CMYK to RGB
    {
        printf("Enter the values of the cyan, magenta, yellow, and black channels (0-1)\n");
        scanf("%f %f %f %f", &cyan, &magenta, &yellow, &black);

        // Convert CMYK values to percentages
        float percentCyan = cyan * (1 - black) + black;
        float percentMagenta = magenta * (1 - black) + black;
        float percentYellow = yellow * (1 - black) + black;

        // Calculate RGB values
        red = (1 - percentCyan) * 255;
        green = (1 - percentMagenta) * 255;
        blue = (1 - percentYellow) * 255;

        printf("\nRGB values: %.0f %.0f %.0f", red, green, blue);
    }
    else
    {
        printf("Invalid choice. Please try again.");
    }

    return 0;
}