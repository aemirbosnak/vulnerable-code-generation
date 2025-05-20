//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_HEX_LENGTH 32

int main()
{
    char hex[MAX_HEX_LENGTH];
    int decimal;
    int i;
    int j;
    int k;
    int hex_length;
    int decimal_length;
    int is_negative;

    // get hex input from user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // check if hex input is valid
    for (i = 0; i < strlen(hex); i++)
    {
        if (!isxdigit(hex[i]))
        {
            printf("Invalid hexadecimal input.\n");
            return 1;
        }
    }

    // check if hex input is negative
    is_negative = 0;
    if (hex[0] == '-')
    {
        is_negative = 1;
        i = 1;
    }
    else
    {
        i = 0;
    }

    // get decimal input from user
    printf("Enter a decimal number (leave blank if not applicable): ");
    scanf("%s", hex);

    // check if decimal input is valid
    if (strlen(hex) > 0 &&!isdigit(hex[0]))
    {
        printf("Invalid decimal input.\n");
        return 1;
    }

    // convert hex to decimal
    decimal = 0;
    j = strlen(hex) - 1;
    while (j >= i)
    {
        if (is_negative)
        {
            decimal += (int)pow(16, strlen(hex) - j - 1) * (hex[j] - '0');
        }
        else
        {
            decimal += (int)pow(16, strlen(hex) - j - 1) * (hex[j] - '0' - 7);
        }
        j--;
    }

    // convert decimal to hex
    hex_length = 0;
    k = decimal;
    while (k > 0)
    {
        if (k % 16 < 10)
        {
            hex[hex_length++] = k % 16 + '0';
        }
        else
        {
            hex[hex_length++] = (char)(k % 16 + 'A' - 10);
        }
        k /= 16;
    }
    hex[hex_length] = '\0';

    // print results
    if (is_negative)
    {
        printf("Decimal: -%d\n", decimal);
    }
    else
    {
        printf("Decimal: %d\n", decimal);
    }
    printf("Hexadecimal: %s\n", hex);

    return 0;
}