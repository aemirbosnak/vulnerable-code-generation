//FormAI DATASET v1.0 Category: Binary Converter ; Style: modular
#include <stdio.h>

#define MAX_SIZE 20

void binaryToDecimal(int binaryNum[], int size)
{
    int decimalNum = 0;
    int base = 1;

    for (int i = size-1; i >= 0; i--)
    {
        if (binaryNum[i] == 1)
        {
            decimalNum += base;
        }
        base *= 2;
    }

    printf("The decimal equivalent of the binary number is %d\n", decimalNum);
}

void decimalToBinary(int decimalNum)
{
    int binaryNum[MAX_SIZE];
    int index = 0;

    while (decimalNum > 0)
    {
        binaryNum[index] = decimalNum % 2;
        decimalNum /= 2;
        index++;
    }

    printf("The binary equivalent of the decimal number is ");
    for (int i = index-1; i >= 0; i--)
    {
        printf("%d", binaryNum[i]);
    }
    printf("\n");
}

int main()
{
    int choice, decimalNum;
    int binaryNum[MAX_SIZE];
    int size = 0;

    printf("1. Decimal to Binary conversion\n");
    printf("2. Binary to Decimal conversion\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            decimalToBinary(decimalNum);
            break;

        case 2:
            printf("Enter a binary number: ");
            while (size <= MAX_SIZE)
            {
                scanf("%1d", &binaryNum[size]);

                if (binaryNum[size] == 0 || binaryNum[size] == 1)
                {
                    size++;
                }
                else
                {
                    break;
                }
            }
            binaryToDecimal(binaryNum, size);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}