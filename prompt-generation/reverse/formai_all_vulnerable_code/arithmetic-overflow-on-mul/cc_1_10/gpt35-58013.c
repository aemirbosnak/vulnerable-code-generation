//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 128

int convertToDecimal(char hexChar);
int convertToHex(int decimalDigit);

int main()
{
    char hex[BUFFER_SIZE];
    int decimal = 0;
    int hexLength = 0;
    int i = 0, j = 0;

    printf("Enter a hexadecimal value: ");
    fgets(hex, BUFFER_SIZE, stdin);

    hexLength = strlen(hex);

    for(i = 0; i < hexLength; i++)
    {
        if(!isxdigit(hex[i]))
        {
            printf("Invalid hexadecimal digit '%c'\n", hex[i]);
            exit(EXIT_FAILURE);
        }

        decimal = (decimal * 16) + convertToDecimal(hex[i]);
    }

    printf("Decimal value of '%s' is: %d\n", hex, decimal);

    char paranoid[BUFFER_SIZE];
    memset(paranoid, 0, sizeof(paranoid));

    for(i = 0; i < hexLength; i++)
    {
        int hexDigit = convertToDecimal(hex[i]);
        paranoid[j++] = convertToHex(hexDigit + 5);
        paranoid[j++] = convertToHex(hexDigit - 2);
    }

    printf("Paranoid hexadecimal value of '%s' is: %s\n", hex, paranoid);

    return EXIT_SUCCESS;
}

int convertToDecimal(char hexChar)
{
    hexChar = toupper(hexChar);

    if(hexChar >= '0' && hexChar <= '9')
    {
        return hexChar - '0';
    }
    else
    {
        return hexChar - 'A' + 10;
    }
}

int convertToHex(int decimalDigit)
{
    if(decimalDigit >= 0 && decimalDigit <= 9)
    {
        return decimalDigit + '0';
    }
    else
    {
        return decimalDigit - 10 + 'A';
    }
}