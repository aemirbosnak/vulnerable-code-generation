//FormAI DATASET v1.0 Category: Binary Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// function to convert decimal to binary
long decimalToBinary(int decimalNum)
{
    long binaryNum = 0;
    int remainder, factor = 1;

    while(decimalNum > 0)
    {
        remainder = decimalNum % 2;
        binaryNum += remainder * factor;
        decimalNum = decimalNum / 2;
        factor *= 10;
    }

    return binaryNum;
}

// function to convert binary to decimal
int binaryToDecimal(long binaryNum)
{
    int decimalNum = 0, factor = 1, remainder;

    while(binaryNum > 0)
    {
        remainder = binaryNum % 10;
        decimalNum += remainder * factor;
        factor *= 2;
        binaryNum /= 10;
    }

    return decimalNum;
}

int main()
{
    int choice, decimalNum;
    long binaryNum;

    printf("Welcome to my binary converter!\n");

    do
    {
        printf("\nWhich conversion do you wish to perform?\n");
        printf("1. Decimal to binary\n2. Binary to decimal\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: // decimal to binary
                printf("\nEnter the decimal number you wish to convert: ");
                scanf("%d", &decimalNum);

                binaryNum = decimalToBinary(decimalNum);
                printf("The binary equivalent of %d is %ld\n", decimalNum, binaryNum);
                break;

            case 2: // binary to decimal
                printf("\nEnter the binary number you wish to convert: ");
                scanf("%ld", &binaryNum);

                decimalNum = binaryToDecimal(binaryNum);
                printf("The decimal equivalent of %ld is %d\n", binaryNum, decimalNum);
                break;

            case 3: // exit
                printf("\nExiting program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}