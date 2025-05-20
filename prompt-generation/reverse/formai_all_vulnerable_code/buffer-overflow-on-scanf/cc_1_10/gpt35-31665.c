//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void rgbToHex(int r, int g, int b);
void hexToRgb(char *hex);

int main()
{
    char choice;
    int r, g, b;
    char hex[7];

    printf("Color Code Converter\n");
    printf("Select an option:\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");

    scanf("%c", &choice);

    switch (choice)
    {
        case '1':
            printf("Enter RGB values (separated by a space): ");
            scanf("%d %d %d", &r, &g, &b);
            rgbToHex(r, g, b);
            break;

        case '2':
            printf("Enter a HEX value: ");
            scanf("%s", hex);
            hexToRgb(hex);
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}

// function to convert RGB to HEX
void rgbToHex(int r, int g, int b)
{
    char hex[7];
    sprintf(hex, "#%02X%02X%02X", r, g, b);
    printf("Hexadecimal value is %s\n", hex);
}

// function to convert HEX to RGB
void hexToRgb(char *hex)
{
    if (strlen(hex) != 7)
    {
        printf("Invalid HEX value. HEX value should be in the format #RRGGBB.\n");
        return;
    }

    if (hex[0] != '#')
    {
        printf("Invalid HEX value. HEX value should start with a hash (#) symbol.\n");
        return;
    }

    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("RGB values are (%d, %d, %d)\n", r, g, b);
}