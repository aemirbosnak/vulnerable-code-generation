//FormAI DATASET v1.0 Category: Binary Converter ; Style: mathematical
#include <stdio.h>

int binaryToDecimal(int binaryNumber)
{
    int decimalNumber = 0, base = 1, remainder;
    while (binaryNumber > 0)
    {
        remainder = binaryNumber % 10;
        decimalNumber += remainder * base;
        binaryNumber /= 10;
        base *= 2;
    }
    return decimalNumber;
}

int decimalToBinary(int decimalNumber)
{
    int binaryNumber = 0, remainder, base = 1;
    while (decimalNumber > 0)
    {
        remainder = decimalNumber % 2;
        binaryNumber += remainder * base;
        decimalNumber /= 2;
        base *= 10;
    }
    return binaryNumber;
}

int main()
{
    int option = 0;
    printf("Welcome to the Mathematical Binary Converter Program!\n\n");
    while (option != 3)
    {
        printf("Please select an option from the menu:\n\n");
        printf("1. Convert Binary to Decimal\n");
        printf("2. Convert Decimal to Binary\n");
        printf("3. Exit\n\n");
        printf("Option: ");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
            {
                int binaryNumber;
                printf("\nEnter the binary number you want to convert to decimal (in 0s and 1s): ");
                scanf("%d", &binaryNumber);
                printf("\nThe decimal representation of the binary number %d is %d.\n\n", binaryNumber, binaryToDecimal(binaryNumber));
                break;
            }
            case 2:
            {
                int decimalNumber;
                printf("\nEnter the decimal number you want to convert to binary: ");
                scanf("%d", &decimalNumber);
                printf("\nThe binary representation of the decimal number %d is %d.\n\n", decimalNumber, decimalToBinary(decimalNumber));
                break;
            }
            case 3:
            {
                printf("\nThank you for using the Mathematical Binary Converter Program!\n");
                break;
            }
            default:
            {
                printf("\nInvalid option selected.\n\n");
                break;
            }
        }
    }
    return 0;
}