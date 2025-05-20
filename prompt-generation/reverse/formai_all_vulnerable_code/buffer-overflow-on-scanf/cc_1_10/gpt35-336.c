//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <string.h>

// function to convert hexadecimal to decimal
int hexToDec(char hex[])
{
    int len = strlen(hex);
    int base = 1;
    int dec = 0;
    
    for(int i=len-1; i>=0; i--)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            dec += (hex[i] - '0') * base;
            base *= 16;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            dec += (hex[i] - 'A' + 10) * base;
            base *= 16;
        }
    }
    return dec;
}

// function to convert decimal to hexadecimal
void decToHex(int dec)
{
    int i = 0;
    char hex[100];
    while(dec!=0)
    {
        int rem = dec % 16;
        
        if(rem>=0 && rem<=9)
        {
            hex[i] = rem + '0';
        }
        else
        {
            hex[i] = rem + 55;
        }
        
        dec /= 16;
        i++;
    }
    printf("Hexadecimal Equivalent : ");
    for(int j=i-1; j>=0; j--)
    {
        printf("%c", hex[j]);
    }
}

int main()
{
    char hex[100];
    printf("Enter a hexadecimal number : ");
    scanf("%s", hex);
    
    int dec = hexToDec(hex);
    printf("Decimal Equivalent : %d\n", dec);
    
    decToHex(dec);
    
    return 0;
}