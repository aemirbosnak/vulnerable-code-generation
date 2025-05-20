//FormAI DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int decimalNumber)
{
    int binaryNumber[32], i = 0;
    while (decimalNumber > 0)
    {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNumber[j]);
}

// function to convert binary to decimal
void binaryToDecimal(long long binaryNumber)
{
    int decimalNumber = 0, i = 0, remainder;
    while (binaryNumber != 0)
    {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    printf("%d", decimalNumber);
}

int main()
{
    int choice, decimalNumber;
    long long binaryNumber;
    printf("Binary Converter\n");
    printf("----------------\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter decimal number: ");
        scanf("%d", &decimalNumber);
        printf("Binary conversion of %d is: ", decimalNumber);
        decimalToBinary(decimalNumber);
        break;
    case 2:
        printf("Enter binary number: ");
        scanf("%lld", &binaryNumber);
        printf("Decimal conversion of %lld is: ", binaryNumber);
        binaryToDecimal(binaryNumber);
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }

    return 0;
}