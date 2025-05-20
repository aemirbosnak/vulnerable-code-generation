//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>

// function to convert binary to decimal
int binaryToDecimal(int binaryNumber)
{
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0)
    {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

// function to convert decimal to binary
int decimalToBinary(int decimalNumber)
{
    int binaryNumber = 0, i = 1, remainder;
    while (decimalNumber != 0)
    {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

int main()
{
    int choice, number, binaryNumber, decimalNumber;
    printf("Select an option: \n1. Binary to Decimal Conversion\n2. Decimal to Binary Conversion\n");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Enter a binary number: ");
            scanf("%d", &number);
            if (number < 0)
            {
                printf("Error: Invalid input!");
            }
            else
            {
                decimalNumber = binaryToDecimal(number);
                printf("Decimal Number is: %d", decimalNumber);
            }
            break;
        case 2:
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            if (number < 0)
            {
                printf("Error: Invalid input!");
            }
            else
            {
                binaryNumber = decimalToBinary(number);
                printf("Binary Number is: %d", binaryNumber);
            }
            break;
        default:
            printf("Error: Invalid input!");
            break;
    }
    return 0;
}