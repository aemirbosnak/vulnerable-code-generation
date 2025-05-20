//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LENGTH 100
#define MAX_DEC_LENGTH 33

void hexToDec(char* hex, int hexLen, char* dec, int* decLen)
{
    int i = 0, j = 0;
    while (i < hexLen)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec[j++] = hex[i++];
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec[j++] = hex[i++] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            dec[j++] = hex[i++] - 'a' + 10;
        }
        else
        {
            printf("Error: Invalid hexadecimal character '%c' at position %d\n", hex[i], i);
            exit(1);
        }
    }
    dec[j] = '\0';
    *decLen = j;
}

void decToHex(char* dec, int decLen, char* hex, int* hexLen)
{
    int i = 0, j = 0;
    while (i < decLen)
    {
        if (dec[i] >= '0' && dec[i] <= '9')
        {
            sprintf(&hex[j], "%c", dec[i]);
            j += 1;
        }
        else
        {
            printf("Error: Invalid decimal character '%c' at position %d\n", dec[i], i);
            exit(1);
        }
        i++;
    }
    hex[j] = '\0';
    *hexLen = j;
}

int main()
{
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];
    int hexLen, decLen;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hexLen = strlen(hex);

    if (hexLen == 0)
    {
        printf("Error: Empty input\n");
        exit(1);
    }

    decLen = hexLen * 4;
    decToHex(hex, hexLen, dec, &decLen);

    printf("Hexadecimal: %s\n", hex);
    printf("Decimal: %s\n", dec);

    return 0;
}