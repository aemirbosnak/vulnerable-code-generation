//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Ada Lovelace
// Ada Lovelace's Hexadecimal Converter

// The following program converts a decimal number to its hexadecimal equivalent.

// The program uses the following algorithm:

// 1. Divide the decimal number by 16.
// 2. The remainder of the division is the least significant digit of the hexadecimal number.
// 3. Repeat steps 1 and 2 until the quotient is 0.
// 4. The hexadecimal number is the sequence of digits obtained from the remainders, starting with the least significant digit.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int decimal_number;
    int quotient;
    int remainder;
    char hexadecimal_number[100];
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    quotient = decimal_number / 16;
    remainder = decimal_number % 16;

    while (quotient != 0)
    {
        hexadecimal_number[i] = remainder + '0';
        i++;
        quotient = quotient / 16;
        remainder = quotient % 16;
    }

    hexadecimal_number[i] = quotient + '0';
    i++;

    printf("The hexadecimal equivalent is: ");

    for (i = i - 1; i >= 0; i--)
    {
        printf("%c", hexadecimal_number[i]);
    }

    printf("\n");

    return 0;
}