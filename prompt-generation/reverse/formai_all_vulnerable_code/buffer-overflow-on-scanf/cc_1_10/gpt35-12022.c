//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <string.h>

void convertDecimalToHexadecimal(int decimalNumber);
int convertHexadecimalToDecimal(char *hexadecimalNumber);

int main()
{
    int decimalNumber;
    char hexadecimalNumber[50];

    // Convert decimal to hexadecimal
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    printf("The hexadecimal of %d is: ", decimalNumber);
    convertDecimalToHexadecimal(decimalNumber);

    // Convert hexadecimal to decimal
    printf("\nEnter a hexadecimal number: ");
    scanf("%s", hexadecimalNumber);
    printf("The decimal of %s is: %d\n", hexadecimalNumber, convertHexadecimalToDecimal(hexadecimalNumber));

    return 0;
}

// Function to convert decimal to hexadecimal
void convertDecimalToHexadecimal(int decimalNumber)
{
    char hexadecimalNumber[50];
    int remainder, quotient, i = 0;

    while (decimalNumber != 0)
    {
        remainder = decimalNumber % 16;
        if (remainder < 10)
            hexadecimalNumber[i++] = '0' + remainder;
        else
            hexadecimalNumber[i++] = 'A' + (remainder - 10);
        decimalNumber /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexadecimalNumber[j]);
    }
}

// Function to convert hexadecimal to decimal
int convertHexadecimalToDecimal(char *hexadecimalNumber)
{
    int decimalNumber = 0, currentNumber, length;
    length = strlen(hexadecimalNumber);

    for (int i = 0; i < length; i++)
    {
        if (hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9')
            currentNumber = hexadecimalNumber[i] - '0';
        else if (hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F')
            currentNumber = hexadecimalNumber[i] - 'A' + 10;

        decimalNumber += currentNumber * pow(16, length - i - 1);
    }

    return decimalNumber;
}