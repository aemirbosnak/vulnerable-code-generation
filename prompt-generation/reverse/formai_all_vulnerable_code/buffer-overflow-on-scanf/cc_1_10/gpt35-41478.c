//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>

// function to convert a decimal number to binary
int decimalToBinary(int decimal)
{
    int binary = 0, base = 1;
    
    while(decimal > 0)
    {
        binary += (decimal % 2) * base;
        decimal /= 2;
        base *= 10;
    }
    
    return binary;
}

// function to convert a binary number to decimal
int binaryToDecimal(int binary)
{
    int decimal = 0, base = 1;
    
    while(binary > 0)
    {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    
    return decimal;
}

int main()
{
    int choice, number, result;
    
    printf("Welcome to Binary Converter!\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    printf("Choose your option (1 or 2): ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
            printf("\nEnter a decimal number: ");
            scanf("%d", &number);
            result = decimalToBinary(number);
            printf("\nBinary: %d\n", result);
            break;
            
        case 2:
            printf("\nEnter a binary number: ");
            scanf("%d", &number);
            result = binaryToDecimal(number);
            printf("\nDecimal: %d\n", result);
            break;
            
        default:
            printf("\nInvalid option!\n");
            break;
    }
    
    return 0;
}