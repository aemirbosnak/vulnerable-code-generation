//FormAI DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Convert a single hexadecimal character to its corresponding decimal value
int hexToDec(char hex)
{
    if (isdigit(hex))
    {
        return hex - '0';
    }
    else
    {
        return toupper(hex) - 'A' + 10;
    }
}

// Convert a hexadecimal color code to its corresponding RGB values
void hexToRGB(char hex[])
{
    int red, green, blue;
    
    // Convert the first two characters to the red value
    red = hexToDec(hex[0]) * 16 + hexToDec(hex[1]);
    
    // Convert the next two characters to the green value
    green = hexToDec(hex[2]) * 16 + hexToDec(hex[3]);
    
    // Convert the last two characters to the blue value
    blue = hexToDec(hex[4]) * 16 + hexToDec(hex[5]);
    
    printf("RGB values: (%d, %d, %d)\n", red, green, blue);
}

// Convert a single decimal value to its corresponding hexadecimal character
char decToHex(int dec)
{
    if (dec < 10)
    {
        return dec + '0';
    }
    else
    {
        return dec - 10 + 'A';
    }
}

// Convert RGB values to their corresponding hexadecimal color code
void RGBToHex(int red, int green, int blue)
{
    char hex[7];
    
    // Convert the red value to two hexadecimal characters
    hex[0] = decToHex(red / 16);
    hex[1] = decToHex(red % 16);
    
    // Convert the green value to two hexadecimal characters
    hex[2] = decToHex(green / 16);
    hex[3] = decToHex(green % 16);
    
    // Convert the blue value to two hexadecimal characters
    hex[4] = decToHex(blue / 16);
    hex[5] = decToHex(blue % 16);
    
    // Add the null terminator
    hex[6] = '\0';
    
    printf("Hexadecimal color code: #%s\n", hex);
}

int main()
{
    int choice;
    
    printf("Color Code Converter\n");
    printf("1. Convert Hexadecimal to RGB\n");
    printf("2. Convert RGB to Hexadecimal\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    
    switch (choice)
    {
        case 1:
        {
            char hex[7];
            printf("Enter a hexadecimal color code: ");
            scanf("%s", hex);
            hexToRGB(hex);
            break;
        }
        case 2:
        {
            int red, green, blue;
            printf("Enter RGB values (0-255):\n");
            printf("Red: ");
            scanf("%d", &red);
            printf("Green: ");
            scanf("%d", &green);
            printf("Blue: ");
            scanf("%d", &blue);
            RGBToHex(red, green, blue);
            break;
        }
        default:
        {
            printf("Invalid option!\n");
            break;
        }
    }
    
    return 0;
}