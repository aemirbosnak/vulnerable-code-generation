//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    char hex[100], ch;
    int i, j, len, decimal;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    len = strlen(hex);

    if(len == 0)
    {
        printf("Invalid input. Please enter a valid hexadecimal number.\n");
        return 0;
    }

    for(i = 0; i < len; i++)
    {
        ch = hex[i];

        if(!isxdigit(ch))
        {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    decimal = 0;

    for(i = len-1, j = 0; i >= 0; i--, j++)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += hex[i] - '0';
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += hex[i] - 'A' + 10;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += hex[i] - 'a' + 10;
        }
        else
        {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }

        decimal *= 16;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}