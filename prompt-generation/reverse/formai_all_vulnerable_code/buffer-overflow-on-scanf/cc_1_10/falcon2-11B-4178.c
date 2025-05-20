//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DEC_HEX_SIZE 100
#define MAX_HEX_DEC_SIZE 100

void decimalToHexadecimal(char *dec, char *hex)
{
    // convert decimal to hexadecimal
    int i, j, rem, temp;
    for (i = 0; dec[i]!= '\0'; i++)
    {
        rem = dec[i] - '0';
        if (rem < 10)
        {
            temp = rem + '0';
        }
        else
        {
            temp = rem - 10 + 'A';
        }
        hex[i] = temp;
    }
    hex[i] = '\0';
}

void hexadecimalToDecimal(char *hex, int *dec)
{
    int i, j, rem, temp;
    for (i = 0; hex[i]!= '\0'; i++)
    {
        rem = hex[i] - '0';
        if (rem < 10)
        {
            temp = rem + '0';
        }
        else
        {
            temp = rem - 10 + 'A';
        }
        dec[i] = temp;
    }
}

int main()
{
    char dec[MAX_DEC_HEX_SIZE], hex[MAX_HEX_DEC_SIZE];
    int dec_val, hex_val;

    printf("Enter a decimal number: ");
    scanf("%s", dec);

    decimalToHexadecimal(dec, hex);
    printf("Decimal %s converted to hexadecimal is %s.\n", dec, hex);

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    hexadecimalToDecimal(hex, &dec_val);
    printf("Hexadecimal %s converted to decimal is %d.\n", hex, dec_val);

    return 0;
}