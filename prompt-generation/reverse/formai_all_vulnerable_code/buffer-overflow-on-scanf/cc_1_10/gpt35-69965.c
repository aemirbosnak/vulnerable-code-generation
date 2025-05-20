//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

int convertDecimalToBinary(int decimalNumber)
{
    int binaryNumber = 0, i = 0, remainder;

    while (decimalNumber != 0)
    {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * pow(10, i);
        i++;
    }

    return binaryNumber;
}

int convertBinaryToDecimal(int binaryNumber)
{
    int decimalNumber = 0, i = 0, remainder;

    while (binaryNumber != 0)
    {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        i++;
    }

    return decimalNumber;
}

int main()
{
    int conversionChoice, numberToConvert;

    printf("Type 1 to convert decimal to binary, or 2 to convert binary to decimal: ");
    scanf("%d", &conversionChoice);

    if (conversionChoice == 1)
    {
        printf("Type the decimal number to convert: ");
        scanf("%d", &numberToConvert);

        printf("The binary equivalent of %d is %d", numberToConvert, convertDecimalToBinary(numberToConvert));
    }
    else if (conversionChoice == 2)
    {
        printf("Type the binary number to convert: ");
        scanf("%d", &numberToConvert);

        printf("The decimal equivalent of %d is %d", numberToConvert, convertBinaryToDecimal(numberToConvert));
    }
    else
    {
        printf("Invalid choice!");
    }

    return 0;
}