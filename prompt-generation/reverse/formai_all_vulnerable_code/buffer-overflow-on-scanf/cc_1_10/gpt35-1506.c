//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>

int hexToDecimal(char hex[]);
void decimalToHex(int decimal);

int main()
{
    char hex[10];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = hexToDecimal(hex);
    printf("Decimal number: %d\n", decimal);

    decimalToHex(decimal);

    return 0;
}

int hexToDecimal(char hex[])
{
    int decimal = 0;
    int base = 1;
    int i;
    for (i = strlen(hex) - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

void decimalToHex(int decimal)
{
    int hex[1000];
    int i = 0;
    while (decimal != 0)
    {
        hex[i] = decimal % 16;
        decimal /= 16;
        i++;
    }
    printf("Hexadecimal number: ");
    int j;
    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] <= 9)
        {
            printf("%d", hex[j]);
        }
        else
        {
            printf("%c", hex[j] + 55);
        }
    }
    printf("\n");
}