//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_SIZE 32

void hex_to_dec(char* hex, int* dec)
{
    int len = strlen(hex);
    int i = 0;
    int j = 0;
    int num = 0;
    int power = 0;

    // Skip leading zeros
    while (i < len && hex[i] == '0')
    {
        i++;
    }

    // Check for overflow
    if (i == len || hex[i] == 'x' || hex[i] == 'X')
    {
        printf("Error: Invalid hexadecimal number\n");
        exit(1);
    }

    // Check for negative number
    if (hex[i] == '-')
    {
        i++;
        power = -1;
    }
    else
    {
        power = 1;
    }

    // Convert hex to decimal
    while (i < len)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            num = num * 16 + hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            num = num * 16 + hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            num = num * 16 + hex[i] - 'a' + 10;
        }
        else
        {
            printf("Error: Invalid hexadecimal number\n");
            exit(1);
        }

        i++;
    }

    // Apply sign
    *dec = num * power;
}

void dec_to_hex(int dec, char* hex)
{
    char* ptr = hex;
    int i = 0;
    int j = 0;

    // Check for negative number
    if (dec < 0)
    {
        *ptr++ = '-';
        dec = -dec;
    }

    // Convert decimal to hex
    while (dec > 0)
    {
        int rem = dec % 16;

        if (rem < 10)
        {
            *ptr++ = rem + '0';
        }
        else
        {
            *ptr++ = rem + 'A' - 10;
        }

        dec /= 16;
    }

    // Add leading zeros
    while (i < MAX_HEX_SIZE - j)
    {
        *ptr++ = '0';
        i++;
    }

    *ptr = '\0';

    // Reverse the string
    for (i = 0, j = strlen(hex) - 1; i < j; i++, j--)
    {
        char temp = hex[i];
        hex[i] = hex[j];
        hex[j] = temp;
    }
}

int main()
{
    char hex[MAX_HEX_SIZE];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hex_to_dec(hex, &dec);

    printf("Decimal equivalent: %d\n", dec);

    printf("Enter a decimal number: ");
    scanf("%d", &dec);

    dec_to_hex(dec, hex);

    printf("Hexadecimal equivalent: %s\n", hex);

    return 0;
}