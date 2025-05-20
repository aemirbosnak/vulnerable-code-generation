//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a unique C program which converts decimal numbers to hexadecimal notation */

int main()
{
    int decimalNumber;
    char hexaDecimalNumber[20];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    if (decimalNumber >= 0) // checks if decimalNumber is a positive number
    {
        int quotient, remainder, i = 0;
        quotient = decimalNumber;

        while (quotient != 0)
        {
            remainder = quotient % 16;
            if (remainder < 10)
            {
                hexaDecimalNumber[i] = remainder + 48; // adding 48 because ASCII code for '0' is 48
                i++;
            }
            else
            {
                hexaDecimalNumber[i] = remainder + 55; // adding 55 because ASCII code for 'A' is 65
                i++;
            }

            quotient = quotient / 16; // calculating the quotient
        }

        printf("The hexadecimal representation of %d is: ", decimalNumber);

        for (int j = i - 1; j >= 0; j--) // printing the hexadecimal number
        {
            printf("%c", hexaDecimalNumber[j]);
        }
    }
    else
    {
        printf("Invalid input: Please enter a positive decimal number.");
    }

    return 0;
}