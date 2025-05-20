//FormAI DATASET v1.0 Category: Color Code Converter ; Style: peaceful
#include <stdio.h>

void convertToRGB(int hexCode);
void convertToHex(int red, int green, int blue);

int main()
{
    char option;

    printf("Welcome to the C Color Code Converter\n");
    printf("Enter 'h' to convert from RGB to Hexadecimal\n");
    printf("Enter 'r' to convert from Hexadecimal to RGB\n");

    do
    {
        printf("Enter your option: ");
        scanf(" %c", &option);

        if(option == 'h')
        {
            int r, g, b;
            printf("Enter the Red value (0-255): ");
            scanf("%d", &r);
            printf("Enter the Green value (0-255): ");
            scanf("%d", &g);
            printf("Enter the Blue value (0-255): ");
            scanf("%d", &b);

            convertToHex(r, g, b);
        }
        else if(option == 'r')
        {
            int hexValue;
            printf("Enter the Hexadecimal code (without '#'): ");
            scanf("%x", &hexValue);

            convertToRGB(hexValue);
        }
        else
        {
            printf("Invalid option.\n");
        }

        printf("\n");

    } while(option != 'e');

    return 0;
}

void convertToRGB(int hexCode)
{
    int red, green, blue;

    red = (hexCode >> 16) & 0xFF;
    green = (hexCode >> 8) & 0xFF;
    blue = hexCode & 0xFF;

    printf("RGB Code: (%d, %d, %d)\n", red, green, blue);
}

void convertToHex(int red, int green, int blue)
{
    int hexCode = (red << 16) + (green << 8) + blue;

    printf("Hexadecimal Code: #%06X\n", hexCode);
}