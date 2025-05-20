//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToHexadecimal(long long decimalNumber)
{
    char hexadecimalNumber[100];
    int i = 0;
    
    while(decimalNumber != 0)
    {
        int remainder = decimalNumber%16;
        if(remainder < 10)
            hexadecimalNumber[i++] = 48 + remainder;
        else
            hexadecimalNumber[i++] = 55 + remainder;
        decimalNumber /= 16;
    }
    
    printf("Hexadecimal Number: ");
    for(int j=i-1; j>=0; j--) 
        printf("%c", hexadecimalNumber[j]);
}

int hexadecimalToDecimal(char hexadecimalNumber[])
{
    int decimalNumber = 0;
    int length = strlen(hexadecimalNumber);
    int base = 1;
    
    for(int i=length-1; i>=0; i--)
    {
        if(hexadecimalNumber[i] >= '0' && hexadecimalNumber[i] <= '9')
        {
            decimalNumber += (hexadecimalNumber[i] - 48) * base;
            base *= 16;
        }
        else if(hexadecimalNumber[i] >= 'a' && hexadecimalNumber[i] <= 'f')
        {
            decimalNumber += (hexadecimalNumber[i] - 87) * base;
            base *= 16;
        }
        else if(hexadecimalNumber[i] >= 'A' && hexadecimalNumber[i] <= 'F')
        {
            decimalNumber += (hexadecimalNumber[i] - 55) * base;
            base *= 16;
        }
    }
    
    return decimalNumber;
}

int main()
{
    int choice;
    printf("Enter 1 to convert Decimal to Hexadecimal\n");
    printf("Enter 2 to convert Hexadecimal to Decimal\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    if(choice == 1)
    {
        long long decimalNumber;
        printf("Enter Decimal Number: ");
        scanf("%lld", &decimalNumber);
        decimalToHexadecimal(decimalNumber);
    }
    else if(choice == 2)
    {
        char hexadecimalNumber[100];
        printf("Enter Hexadecimal Number: ");
        scanf("%s", &hexadecimalNumber);
        int decimalNumber = hexadecimalToDecimal(hexadecimalNumber);
        printf("Decimal Number: %d", decimalNumber);
    }
    else
    {
        printf("Invalid Choice!");
    }
    
    return 0;
}