//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

void hexToRGB(char hex[], int *red, int *green, int *blue);
void RGBToHex(int red, int green, int blue, char hex[]);

int main()
{
    int choice;
    char hex[6];
    int red, green, blue;

    printf("Enter a choice: \n");
    printf("1. Convert Hex to RGB\n2. Convert RGB to Hex\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter Hex code (without #): ");
            scanf("%s", hex);
            hexToRGB(hex, &red, &green, &blue);
            printf("RGB color code: %d,%d,%d\n", red, green, blue);
            break;

        case 2:
            printf("Enter RGB color code (separated by commas): ");
            scanf("%d,%d,%d", &red, &green, &blue);
            RGBToHex(red, green, blue, hex);
            printf("Hex code: #%s\n", hex);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

void hexToRGB(char hex[], int *red, int *green, int *blue)
{
    *red = (int)strtol(hex, NULL, 16) >> 16;
    *green = (int)strtol(hex, NULL, 16) >> 8 & 0xFF;
    *blue = (int)strtol(hex, NULL, 16) & 0xFF;
}

void RGBToHex(int red, int green, int blue, char hex[])
{
    sprintf(hex, "%02X%02X%02X", red, green, blue);
}