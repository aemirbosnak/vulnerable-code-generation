//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <string.h>

int toDecimal(char hex[])
{
    int len = strlen(hex);
    int decimal = 0;
    int base = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base = base * 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base = base * 16;
        }
    }

    return decimal;
}

void toBinary(int decimal)
{
    int binary[32];
    int i = 0;

    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n");
}

int main()
{
    char hex[20];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    int decimal = toDecimal(hex);

    printf("Decimal equivalent: %d\n", decimal);

    printf("Binary equivalent: ");
    toBinary(decimal);

    return 0;
}