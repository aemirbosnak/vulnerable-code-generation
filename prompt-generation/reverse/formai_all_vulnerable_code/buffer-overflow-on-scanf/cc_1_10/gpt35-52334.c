//FormAI DATASET v1.0 Category: Binary Converter ; Style: careful
#include <stdio.h>

int decimalToBinary(int decimal)
{
    int remainder, binary = 0, base = 1;
    
    while(decimal > 0)
    {
        remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }
    
    return binary;
}

int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1, remainder;
    
    while(binary > 0)
    {
        remainder = binary % 10;
        decimal += remainder * base;
        base *= 2;
        binary /= 10;
    }
    
    return decimal;
}

int main()
{
    int decimal, binary, option;
    
    printf("Enter 1 to convert decimal to binary or enter 2 to convert binary to decimal: ");
    scanf("%d", &option);
    
    if(option == 1)
    {
        printf("Enter decimal value: ");
        scanf("%d", &decimal);
        binary = decimalToBinary(decimal);
        printf("Binary value is: %d\n", binary);
    }
    else if(option == 2)
    {
        printf("Enter binary value: ");
        scanf("%d", &binary);
        decimal = binaryToDecimal(binary);
        printf("Decimal value is: %d\n", decimal);
    }
    else
    {
        printf("Invalid option!\n");
    }
    
    return 0;
}