//FormAI DATASET v1.0 Category: Color Code Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This program converts a hex color code to its RGB equivalent or vice versa. 
*/

// function prototypes
void hexToRGB(char hexCode[], int* r, int* g, int* b);
void RGBToHex(int r, int g, int b, char hexCode[]);

int main()
{
    char hexCode[7]; // hex color code (e.g. "FF00FF")
    int r, g, b; // RGB values
    
    int choice; // user's choice (1 or 2)
    printf("Choose an option:\n");
    printf("1. Convert HEX to RGB\n");
    printf("2. Convert RGB to HEX\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter a HEX color code (e.g. FF00FF): ");
        scanf("%s", hexCode);
        hexToRGB(hexCode, &r, &g, &b);
        printf("RGB equivalent: (%d, %d, %d)\n", r, g, b);
    }
    else if (choice == 2)
    {
        printf("Enter RGB values (e.g. 255 0 255): ");
        scanf("%d %d %d", &r, &g, &b);
        RGBToHex(r, g, b, hexCode);
        printf("Hex color code: %s\n", hexCode);
    }
    else
    {
        printf("Invalid choice!\n");
        exit(1);
    }

    return 0;
}

// function to convert hex color code to RGB values
void hexToRGB(char hexCode[], int* r, int* g, int* b)
{
    int i, j;
    int hexValue;
    char* hexDigits = "0123456789ABCDEF";

    // initialize RGB values to zero
    *r = 0;
    *g = 0;
    *b = 0;

    // convert hex color code to RGB values
    for (i = 0; i < 6; i++)
    {
        hexValue = 0;
        for (j = 0; j < 16; j++)
        {
            if (hexCode[i] == hexDigits[j])
            {
                hexValue = j;
                break;
            }
        }

        if (i % 2 == 0)
        {
            *r = *r * 16 + hexValue;
        }
        else if ((i - 1) % 2 == 0)
        {
            *g = *g * 16 + hexValue;
        }
        else
        {
            *b = *b * 16 + hexValue;
        }
    }
}

// function to convert RGB values to hex color code
void RGBToHex(int r, int g, int b, char hexCode[])
{
    int i, j;
    int remainder;
    char temp[3];

    // convert R value to hex
    i = 0;
    while (r > 0)
    {
        remainder = r % 16;
        temp[i] = "0123456789ABCDEF"[remainder];
        r /= 16;
        i++;
    }

    while (i < 2)
    {
        temp[i] = '0';
        i++;
    }
    temp[i] = '\0';

    // reverse hex digits
    for (i = strlen(temp) - 1, j = 0; i >= 0; i--, j++)
    {
        hexCode[j] = temp[i];
    }

    // convert G value to hex
    i = 2;
    while (g > 0)
    {
        remainder = g % 16;
        temp[i] = "0123456789ABCDEF"[remainder];
        g /= 16;
        i++;
    }

    while (i < 4)
    {
        temp[i] = '0';
        i++;
    }
    temp[i] = '\0';

    // reverse hex digits
    for (i = strlen(temp) - 1, j = 2; i >= 0; i--, j++)
    {
        hexCode[j] = temp[i];
    }

    // convert B value to hex
    i = 4;
    while (b > 0)
    {
        remainder = b % 16;
        temp[i] = "0123456789ABCDEF"[remainder];
        b /= 16;
        i++;
    }

    while (i < 6)
    {
        temp[i] = '0';
        i++;
    }
    temp[i] = '\0';

    // reverse hex digits
    for (i = strlen(temp) - 1, j = 4; i >= 0; i--, j++)
    {
        hexCode[j] = temp[i];
    }

    hexCode[6] = '\0'; // add null terminator
}