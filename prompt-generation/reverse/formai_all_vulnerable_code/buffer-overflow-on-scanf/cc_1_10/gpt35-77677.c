//FormAI DATASET v1.0 Category: Binary Converter ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int binaryToDecimal(char binaryNumber[])
{
    int length = strlen(binaryNumber);
    int decimalNumber = 0;
    int base = 1;
    for(int i = length - 1; i >= 0; i--)
    {
        if(binaryNumber[i] == '1')
        {
            decimalNumber += base;
        }
        base = base * 2;
    }
    return decimalNumber;
}

void decimalToBinary(int decimalNumber)
{
    int binaryNumber[32];
    int i = 0;
    while(decimalNumber > 0)
    {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        i++;
    }
    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d",binaryNumber[j]);
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Binary Converter\n");
    printf("Select an option:\n");
    printf("1. Convert Binary to Decimal\n");
    printf("2. Convert Decimal to Binary\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        char binaryNumber[32];
        printf("Enter a binary number: ");
        scanf("%s",binaryNumber);
        int decimalNumber = binaryToDecimal(binaryNumber);
        printf("Decimal number: %d\n",decimalNumber);
    }

    else if(choice == 2)
    {
        int decimalNumber;
        printf("Enter a decimal number: ");
        scanf("%d",&decimalNumber);
        printf("Binary number: ");
        decimalToBinary(decimalNumber);
    }

    else
    {
        printf("Invalid choice\n");
    }
    
    return 0;
}