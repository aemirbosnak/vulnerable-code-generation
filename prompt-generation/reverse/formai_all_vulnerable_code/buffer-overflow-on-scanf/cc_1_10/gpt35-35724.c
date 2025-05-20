//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>

/**
 * This program takes a hexadecimal number as input and converts
 * it to decimal.
 */
int main()
{
    char hex[17];
    long long decimal, place;
    int i = 0, val, len;

    /* Input hexadecimal number from user */
    printf("Enter any hexadecimal number: ");
    scanf("%s", hex);

    /* Find the length of total number of hex digits */
    len = strlen(hex);

    /* Start from rightmost hex digit */
    len--;
    decimal = 0;
    place = 1;

    /* Iterate over each hex digit */
    for(i=0; hex[i]!='\0'; i++)
    {
        /* Find the decimal representation of hex[i] */
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }

        /* Add val to decimal and move to next hex digit */
        decimal += val * place;
        place *= 16;
    }

    /* Print the decimal representation of hexadecimal number */
    printf("The decimal equivalent is: %lld", decimal);

    return 0;
}