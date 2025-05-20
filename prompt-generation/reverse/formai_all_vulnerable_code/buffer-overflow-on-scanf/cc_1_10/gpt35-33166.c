//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>

// Function to convert RGB color code to HEX color code
void RGBtoHEX(float R, float G, float B)
{
    int r = (int)(R * 255);
    int g = (int)(G * 255);
    int b = (int)(B * 255);

    // Convert each RGB color code to HEX color code
    char hex[7];
    sprintf(hex, "#%02x%02x%02x", r, g, b);

    // Print the converted HEX color code
    printf("The HEX color code is: %s\n", hex);
}

// Function to convert HEX color code to RGB color code
void HEXtoRGB(char hex[])
{
    // Get the HEX color code for each RGB color code
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);

    // Convert each HEX color code to RGB color code
    float R = r / 255.0;
    float G = g / 255.0;
    float B = b / 255.0;

    // Print the converted RGB color code
    printf("The RGB color code is: (%.2f, %.2f, %.2f)\n", R, G, B);
}

int main()
{
    char choice;
    float R, G, B;
    char hex[7];

    // Prompt the user for the type of color code to be converted
    printf("Enter C for converting from RGB to HEX, or H for converting from HEX to RGB: ");
    scanf("%c", &choice);

    if (choice == 'C')
    {
        // Prompt the user for the RGB color code
        printf("Enter the RGB color code (separated by spaces): ");
        scanf("%f %f %f", &R, &G, &B);

        // Convert the RGB color code to HEX color code and print it
        RGBtoHEX(R, G, B);
    }
    else if (choice == 'H')
    {
        // Prompt the user for the HEX color code
        printf("Enter the HEX color code: ");
        scanf("%s", hex);

        // Convert the HEX color code to RGB color code and print it
        HEXtoRGB(hex);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}