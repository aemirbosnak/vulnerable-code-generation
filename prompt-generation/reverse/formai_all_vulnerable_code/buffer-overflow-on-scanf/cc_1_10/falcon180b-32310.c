//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert hexadecimal to decimal
int hexToDec(char hex[], int len)
{
    // Base case
    if (len == 0)
    {
        return 0;
    }

    // Recursive case
    int decimal = 0;
    int power = len - 1;
    char c = hex[len - 1];
    if (c >= '0' && c <= '9')
    {
        decimal += c - '0';
    }
    else if (c >= 'A' && c <= 'F')
    {
        decimal += c - 'A' + 10;
    }
    else if (c >= 'a' && c <= 'f')
    {
        decimal += c - 'a' + 10;
    }
    else
    {
        return -1; // Invalid character
    }

    return decimal + hexToDec(hex, len - 1) * 16;
}

// Function to convert decimal to hexadecimal
void decToHex(int dec, char hex[])
{
    int len = 0;
    if (dec == 0)
    {
        hex[len++] = '0';
    }
    else
    {
        while (dec > 0)
        {
            int rem = dec % 16;
            if (rem < 10)
            {
                hex[len++] = rem + '0';
            }
            else
            {
                hex[len++] = rem - 10 + 'A';
            }
            dec /= 16;
        }
    }
    hex[len] = '\0';
}

// Main function
int main()
{
    char hex[100], dec[100];
    int len, decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    len = strlen(hex);

    // Convert hexadecimal to decimal
    decimal = hexToDec(hex, len);
    if (decimal == -1)
    {
        printf("Invalid hexadecimal number\n");
        return 1;
    }

    // Convert decimal to hexadecimal
    decToHex(decimal, dec);
    printf("Decimal equivalent: %s\n", dec);

    return 0;
}