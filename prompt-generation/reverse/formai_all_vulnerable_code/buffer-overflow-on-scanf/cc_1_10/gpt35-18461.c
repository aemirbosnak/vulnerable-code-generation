//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNum)
{
    int remainder, quotient;
    char hexadecimalNum[100];
    int i = 0;

    quotient = decimalNum;

    while (quotient != 0)
    {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimalNum[i++] = 48 + remainder;
        else
            hexadecimalNum[i++] = 55 + remainder;

        quotient /= 16;
    }

    printf("Hexadecimal Number: ");

    for (int j = i; j >= 0; j--)
    {
        printf("%c", hexadecimalNum[j]);
    }
}

// Function to convert hexadecimal to decimal
void hexadecimalToDecimal(char hexNum[])
{
    int len = strlen(hexNum);
    int base = 1;
    int decimalNum = 0;

    for (int i = len - 1; i >= 0; i--)
    {
        if (hexNum[i] >= '0' && hexNum[i] <= '9')
        {
            decimalNum += (hexNum[i] - 48) * base;
            base *= 16;
        }
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F')
        {
            decimalNum += (hexNum[i] - 55) * base;
            base *= 16;
        }
    }

    printf("Decimal Number: %d", decimalNum);
}

int main()
{
    int decimalNum;
    char hexNum[100];

    printf("Enter decimal number: ");
    scanf("%d", &decimalNum);

    decimalToHexadecimal(decimalNum);

    printf("\nEnter hexadecimal number: ");
    scanf("%s", hexNum);

    hexadecimalToDecimal(hexNum);

    return 0;
}