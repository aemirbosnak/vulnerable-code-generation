//FormAI DATASET v1.0 Category: Binary Converter ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char binary[])
{
    int decimal = 0, binaryDigit, power = 0;
    int binaryLength = strlen(binary);

    for (int i = binaryLength - 1; i >= 0; i--)
    {
        binaryDigit = binary[i] - '0';
        decimal += binaryDigit * (int) pow(2, power);
        power++;
    }

    return decimal;
}

void decimalToBinary(int decimal)
{
    int binary[32], index = 0;

    while (decimal > 0)
    {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }

    printf("Binary Representation: ");

    for (int i = index - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }

    printf("\n");
}

int main()
{
    int choice, decimalNumber;
    char binaryNumber[32];

    printf("BINARY CONVERTER\n\n");

    do
    {
        printf("1 - Binary to Decimal\n2 - Decimal to Binary\n0 - Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter a binary number: ");
                scanf("%s", binaryNumber);

                if (strlen(binaryNumber) > 32)
                {
                    printf("Invalid Input!\n");
                }
                else
                {
                    printf("Decimal Representation: %d\n", binaryToDecimal(binaryNumber));
                }
                break;

            case 2:
                printf("\nEnter a decimal number: ");
                scanf("%d", &decimalNumber);

                if (decimalNumber < 0)
                {
                    printf("Invalid Input!\n");
                }
                else
                {
                    decimalToBinary(decimalNumber);
                }
                break;

            case 0:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
                break;
        }

        printf("\n");
    } while (choice != 0);

    return 0;
}