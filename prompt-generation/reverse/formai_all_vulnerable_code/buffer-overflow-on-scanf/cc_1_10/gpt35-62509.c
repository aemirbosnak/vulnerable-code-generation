//FormAI DATASET v1.0 Category: Binary Converter ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

// Function to convert decimal to binary
long long decimalToBinary(int decimalNumber)
{
    int remainder;
    long long binaryNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        remainder = decimalNumber % 2;
        decimalNumber /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }

    return binaryNumber;
}

// Function to convert binary to decimal
int binaryToDecimal(long long binaryNumber)
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

int main()
{
    int choice, decimalNumber;
    long long binaryNumber;

    do
    {
        printf("Binary Converter Menu\n");
        printf("1. Convert decimal to binary\n");
        printf("2. Convert binary to decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNumber);
                binaryNumber = decimalToBinary(decimalNumber);
                printf("Binary number: %lld\n", binaryNumber);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNumber);
                decimalNumber = binaryToDecimal(binaryNumber);
                printf("Decimal number: %d\n", decimalNumber);
                break;

            case 3:
                printf("Exiting the program\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}