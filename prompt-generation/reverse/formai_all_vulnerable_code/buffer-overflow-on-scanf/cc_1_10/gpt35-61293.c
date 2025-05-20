//FormAI DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hexToDecimal(char hex[]);
void hexToRGB(char hex[], int *red, int *green, int *blue);
int validateHex(char hex[]);

int main()
{
    char hex[7];
    printf("Enter a hexadecimal color code (with or without #): ");
    scanf("%s", hex);

    if (validateHex(hex))
    {
        int red, green, blue;
        hexToRGB(hex, &red, &green, &blue);
        printf("RGB Equivalent: (%d,%d,%d)\n", red, green, blue);
    }
    else
    {
        printf("Invalid hexadecimal color code.\n");
    }

    return 0;
}

// Converts a single hex digit char to decimal
int hexDigitToDecimal(char digit)
{
    if (isdigit(digit))
    {
        return digit - '0';
    }
    else if (toupper(digit) >= 'A' && toupper(digit) <= 'F')
    {
        return toupper(digit) - 'A' + 10;
    }
    else
    {
        return -1;  // Invalid digit
    }
}

// Converts a hex string to decimal value
int hexToDecimal(char hex[])
{
    int result = 0;
    int digit;

    for (int i = 0; i < strlen(hex); i++)
    {
        digit = hexDigitToDecimal(hex[i]);
        if (digit < 0)
        {
            return -1;  // Invalid hex string
        }
        result = result * 16 + digit;
    }

    return result;
}

// Converts a hex string to its corresponding RGB values
void hexToRGB(char hex[], int *red, int *green, int *blue)
{
    if (hex[0] == '#')
    {
        hex++; // Skip over #
    }

    int hexValue = hexToDecimal(hex);

    *red = (hexValue >> 16) & 0xFF;
    *green = (hexValue >> 8) & 0xFF;
    *blue = hexValue & 0xFF;
}

// Validates a hex string
int validateHex(char hex[])
{
    if (strlen(hex) == 6 || strlen(hex) == 7)
    {
        // Check for #
        if (hex[0] == '#')
        {
            hex++; // Skip over #
        }

        // Check that all remaining chars are valid hex digits
        for (int i = 0; i < strlen(hex); i++)
        {
            if (!isxdigit(hex[i]))
            {
                return 0;  // Invalid hex string
            }
        }

        return 1;  // Valid hex string
    }
    else
    {
        return 0;  // Invalid hex string
    }
}