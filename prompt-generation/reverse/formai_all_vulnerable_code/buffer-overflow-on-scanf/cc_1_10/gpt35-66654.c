//FormAI DATASET v1.0 Category: Binary Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToBinary(int decimalNumber)
{
    int binaryNumber[1000];
    int index = 0;
    while (decimalNumber > 0) 
    {
        binaryNumber[index] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        index++;
    }
    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binaryNumber[i]);
    }
}

int binaryToDecimal(char binaryNumber[])
{
    int decimalNumber = 0;
    int power = 1;
    int length = strlen(binaryNumber);
    for (int i = length - 1; i >= 0; i--)
    {
        if (binaryNumber[i] == '1')
        {
            decimalNumber += power;
        }
        power = power * 2;
    }
    return decimalNumber;
}

int main()
{
    int choice;
    printf("Welcome to Binary Converter Program!\n");
    while (1)
    {
        printf("\nEnter 1 to convert decimal to binary\n");
        printf("Enter 2 to convert binary to decimal\n");
        printf("Enter 3 to exit the program\n");
        printf("\nYour Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                int decimalNumber;
                printf("\nEnter decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary Conversion: ");
                decimalToBinary(decimalNumber);
                printf("\n");
                break;
            }
            case 2:
            {
                char binaryNumber[1000];
                printf("\nEnter binary number: ");
                scanf("%s", binaryNumber);
                int decimalNumber = binaryToDecimal(binaryNumber);
                printf("Decimal Conversion: %d\n", decimalNumber);
                break;
            }
            case 3:
            {
                printf("\nThank you for using Binary Converter Program! Bye!\n");
                exit(0);
            }
            default:
            {
                printf("\nInvalid Choice!\n");
                break;
            }
        }
    }
    return 0;
}