//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define MAX_LENGTH 100

void hex_to_decimal(char *hexVal, uint64_t *decimalVal)
{
    int len = strlen(hexVal);
    *decimalVal = 0;
    int base = 1;

    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            *decimalVal += (hexVal[i] - 48)*base;
            base *= 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            *decimalVal += (hexVal[i] - 55)*base;
            base *= 16;
        }
        else if (hexVal[i]>='a' && hexVal[i]<='f')
        {
            *decimalVal += (hexVal[i] - 87)*base;
            base *= 16;
        }
    }
}

void decimal_to_hex(uint64_t decimalVal, char *hexVal)
{
    int index = 0;

    while (decimalVal>0)
    {
        int remainder = decimalVal%16;

        if (remainder<10)
        {
            hexVal[index++] = 48 + remainder;
        }
        else
        {
            hexVal[index++] = 55 + remainder;
        }

        decimalVal /= 16;
    }

    for (int i=index; i>=0; i--)
    {
        printf("%c", hexVal[i]);
    }
}

int main()
{
    uint64_t decimalVal;
    char hexVal[MAX_LENGTH];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hexVal);

    hex_to_decimal(hexVal, &decimalVal);
    printf("Decimal: %llu\n", decimalVal);

    printf("Enter a decimal number: ");
    scanf("%llu", &decimalVal);

    printf("Hexadecimal: ");
    decimal_to_hex(decimalVal, hexVal);

    return 0;
}