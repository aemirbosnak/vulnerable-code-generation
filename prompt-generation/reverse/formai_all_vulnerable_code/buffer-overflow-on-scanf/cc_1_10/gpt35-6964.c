//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Function to convert a decimal number to hexadecimal */
void decToHex(unsigned int decimal)
{
    int remainder, quotient;
    char hex[100];
    int i = 0;
    
    quotient = decimal;
    
    /* Convert decimal to hexadecimal */
    while (quotient != 0)
    {
        remainder = quotient % 16;
        
        if (remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 55 + remainder;
        
        quotient = quotient / 16;
    }
    
    /* Print hexadecimal number */
    printf("\nHexadecimal number: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}


/* Function to convert a hexadecimal number to decimal */
void hexToDec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int decimal = 0;
    
    /* Convert hexadecimal to decimal */
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
    
    /* Print decimal number */
    printf("\nDecimal number: %d", decimal);
}


int main()
{
    char input[100];
    int choice;
    
    printf("Do you want to convert decimal number to hexadecimal or hexadecimal number to decimal? Enter 1 for decimal to hexadecimal conversion and 2 for hexadecimal to decimal conversion: ");
    scanf("%d", &choice);
    fflush(stdin);
    
    /* Convert decimal to hexadecimal */
    if (choice == 1)
    {
        unsigned int decimal;
        printf("\nEnter the decimal number: ");
        scanf("%u", &decimal);
        decToHex(decimal);
    }
    /* Convert hexadecimal to decimal */
    else if (choice == 2)
    {
        printf("\nEnter the hexadecimal number: ");
        gets(input);
        hexToDec(input);
    }
    else
        printf("\nInvalid choice!");
    
    return 0;
}