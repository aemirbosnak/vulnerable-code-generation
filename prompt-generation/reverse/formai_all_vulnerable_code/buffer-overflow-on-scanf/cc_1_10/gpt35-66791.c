//FormAI DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int decimalNum)
{
    int binaryNum[32];

    int i = 0;
    while (decimalNum > 0)
    {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }

    printf("Binary number is: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// function to convert binary to decimal
void binaryToDecimal(long long binaryNum)
{
    int decimalNum = 0;
    int base = 1;
    while (binaryNum > 0)
    {
        int lastDigit = binaryNum % 10;
        binaryNum = binaryNum / 10;
        decimalNum += lastDigit * base;
        base = base * 2;
    }

    printf("Decimal number is: %d", decimalNum);
}

int main()
{
    int choice, decimalNum;
    long long binaryNum;

    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter decimal number: ");
        scanf("%d", &decimalNum);

        decimalToBinary(decimalNum);
    }
    else if (choice == 2)
    {
        printf("Enter binary number: ");
        scanf("%lld", &binaryNum);

        binaryToDecimal(binaryNum);
    }
    else
    {
        printf("Invalid choice!");
    }

    return 0;
}