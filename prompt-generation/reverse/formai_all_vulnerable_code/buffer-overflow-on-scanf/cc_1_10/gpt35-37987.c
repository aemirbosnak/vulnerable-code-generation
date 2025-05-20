//FormAI DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal, char *binaryStr)
{
    int bit, i = 0;
    while(decimal > 0)
    {
        bit = decimal % 2;
        binaryStr[i] = bit + '0';
        i++;
        decimal = decimal / 2;
    }
    binaryStr[i] = '\0';

    // Reverse the binary string
    int len = strlen(binaryStr);
    for(i = 0; i < len / 2; i++)
    {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[len - i - 1];
        binaryStr[len - i - 1] = temp;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(char *binaryStr)
{
    int decimal = 0, i, len = strlen(binaryStr);
    for(i = 0; i < len; i++)
    {
        decimal = decimal * 2 + (binaryStr[i] - '0');
    }
    return decimal;
}

int main()
{
    int choice, decimal;
    char binaryStr[50];

    printf("Binary Converter\n");
    printf("================\n\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nEnter a decimal number: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal, binaryStr);
        printf("Binary conversion of %d is %s\n", decimal, binaryStr);
    }
    else if(choice == 2)
    {
        printf("\nEnter a binary number: ");
        scanf("%s", binaryStr);
        decimal = binaryToDecimal(binaryStr);
        printf("Decimal conversion of %s is %d\n", binaryStr, decimal);
    }
    else
    {
        printf("\nInvalid choice!\n");
    }

    return 0;
}