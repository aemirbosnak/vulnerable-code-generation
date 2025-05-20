//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100

int main()
{
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_HEX_LENGTH];
    int i, j, dec_val = 0;

    // Get input from user
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert hexadecimal to decimal
    for (i = strlen(hex) - 1, j = 0; i >= 0; i--, j++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec_val += hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec_val += hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec_val += hex[i] - 'a' + 10;
        }
        else
        {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }

        dec[j] = dec_val % 10 + '0';
        dec_val /= 10;
    }

    // Print the result
    printf("Decimal equivalent: ");
    for (i = strlen(dec) - 1; i >= 0; i--)
    {
        printf("%c", dec[i]);
    }

    return 0;
}