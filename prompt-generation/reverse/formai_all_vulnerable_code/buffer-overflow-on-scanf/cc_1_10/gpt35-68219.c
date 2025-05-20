//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_to_dec(char hex[]);
void dec_to_hex(int dec);

int main()
{
    char hex[100];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert hex to decimal
    dec = hex_to_dec(hex);

    printf("Decimal representation: %d\n", dec);

    // Convert decimal to hex
    printf("Hexadecimal representation: ");
    dec_to_hex(dec);

    return 0;
}

// Function to convert hex to decimal
int hex_to_dec(char hex[])
{
    int len = strlen(hex);
    int base = 1, dec_val = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec_val += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec_val += (hex[i] - 55) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec_val += (hex[i] - 87) * base;
            base = base * 16;
        }
    }

    return dec_val;
}

// Function to convert decimal to hex
void dec_to_hex(int dec)
{
    int rem, i = 0;
    char hex[100];

    while (dec != 0)
    {
        rem = dec % 16;
        if (rem < 10)
            hex[i] = rem + 48;
        else
            hex[i] = rem + 55;
        i++;
        dec /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);

    printf("\n");
}