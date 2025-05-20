//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include<stdio.h>
#include<string.h>

// Function to convert hexadecimal to decimal
int hexToDecimal(char *hexStr)
{
    int decimal = 0;
    int i = 0;
    int mul = 1;
    while (hexStr[i]!= '\0')
    {
        if (hexStr[i] >= '0' && hexStr[i] <= '9')
        {
            decimal = decimal + (hexStr[i] - '0') * mul;
        }
        else if (hexStr[i] >= 'A' && hexStr[i] <= 'F')
        {
            decimal = decimal + (hexStr[i] - 'A' + 10) * mul;
        }
        else if (hexStr[i] >= 'a' && hexStr[i] <= 'f')
        {
            decimal = decimal + (hexStr[i] - 'a' + 10) * mul;
        }
        mul = mul * 16;
        i++;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
char *decToHex(int decimal)
{
    char hexStr[8];
    int i;
    for (i = 7; i >= 0; i--)
    {
        decimal = decimal % 16;
        if (decimal < 10)
        {
            hexStr[i] = decimal + '0';
        }
        else
        {
            hexStr[i] = decimal - 10 + 'A';
        }
    }
    return hexStr;
}

int main()
{
    char hexStr[8], decStr[8];
    printf("Enter the hexadecimal number: ");
    scanf("%s", hexStr);
    printf("Hexadecimal number: %s\n", hexStr);

    int decimal = hexToDecimal(hexStr);
    printf("Decimal equivalent: %d\n", decimal);
    printf("Hexadecimal number: %s\n", decToHex(decimal));

    return 0;
}