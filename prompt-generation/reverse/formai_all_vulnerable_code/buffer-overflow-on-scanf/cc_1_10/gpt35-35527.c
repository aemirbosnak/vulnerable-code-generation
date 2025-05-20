//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void decimalToHexadecimal(int decimalNum)
{
    char hexaDeciNum[100];
    int i=0, temp=0;
    while(decimalNum>0)
    {
        temp = decimalNum%16;
        //if digit is between 0 to 9
        if(temp<10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        //if digit is between A to F
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        decimalNum /= 16;
    }
    //printing hexadecimal number in reverse order
    printf("The equivalent hexadecimal number is : ");
    for(int j=i-1; j>=0; j--)
    {
        printf("%c", hexaDeciNum[j]);
    }
}

int hexadecimalToDecimal(char hex[])
{
    int len=strlen(hex);
    int base=1, deciNum=0;
    for(int i=len-1; i>=0; i--)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            deciNum += (hex[i] - 48)*base;

            base *= 16;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            deciNum += (hex[i] - 55)*base;

            base *= 16;
        }
    }
    return deciNum;
}

int main()
{
    int choice=0, decimalNum=0;
    char hexaDeciNum[100];

    printf("Please select an option:\n1. Decimal to Hexadecimal Conversion\n2. Hexadecimal to Decimal Conversion\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &decimalNum);
            decimalToHexadecimal(decimalNum);
            break;
        case 2:
            printf("Enter a hexadecimal number: ");
            scanf("%s", &hexaDeciNum);
            printf("The equivalent decimal number is : %d",hexadecimalToDecimal(hexaDeciNum));
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}