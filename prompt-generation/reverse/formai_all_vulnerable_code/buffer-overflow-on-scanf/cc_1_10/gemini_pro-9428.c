//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal number to its decimal equivalent
int hex_to_dec(char *hex)
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec += (hex[i] - '0') * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec += (hex[i] - 'A' + 10) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec += (hex[i] - 'a' + 10) * base;
            base *= 16;
        }
    }

    return dec;
}

// Function to convert a decimal number to its hexadecimal equivalent
char *dec_to_hex(int dec)
{
    char *hex = (char *)malloc(sizeof(char) * 100);
    int i = 0;

    while (dec != 0)
    {
        int temp = dec % 16;
        if (temp < 10)
        {
            hex[i++] = temp + '0';
        }
        else
        {
            hex[i++] = temp - 10 + 'A';
        }
        dec /= 16;
    }

    hex[i] = '\0';

    // Reverse the string
    char *start = hex;
    char *end = hex + strlen(hex) - 1;
    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return hex;
}

int main()
{
    // Get the input from the user
    char hex[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert the hexadecimal number to its decimal equivalent
    int dec = hex_to_dec(hex);

    // Print the decimal equivalent
    printf("The decimal equivalent of %s is %d\n", hex, dec);

    // Convert the decimal number to its hexadecimal equivalent
    char *new_hex = dec_to_hex(dec);

    // Print the hexadecimal equivalent
    printf("The hexadecimal equivalent of %d is %s\n", dec, new_hex);

    return 0;
}