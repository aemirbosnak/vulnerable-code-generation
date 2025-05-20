//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hex_to_dec(char hex[]);
char dec_to_hex(int n);

int main()
{
    printf("Hi there! I'm your friendly neighborhood Hexadecimal Converter.\n");
    printf("Do you have a hexadecimal number you'd like to convert?\n");
    char hex[100];
    scanf("%s", hex);
    int decimal = hex_to_dec(hex);

    if(decimal != -1){
        printf("Decimal: %d\n", decimal);
        printf("Hexadecimal: ");
        int hexArr[100], i=0;
        while(decimal!=0){
            int remainder = decimal % 16;
            hexArr[i++] = dec_to_hex(remainder);
            decimal /= 16;
        }
        for(int j=i-1;j>=0;j--)
            printf("%c", hexArr[j]);
        printf("\n");
    }
    else
        printf("Invalid hexadecimal number.\n");

    return 0;
}

int hex_to_dec(char hex[])
{
    int len = strlen(hex);
    int decimal = 0;
    int base = 1;

    for(int i=len-1; i>=0; i--){
        if(hex[i]>='0' && hex[i]<='9')
            decimal += (hex[i] - 48) * base;
        else if(hex[i]>='a' && hex[i]<='f')
            decimal += (hex[i] - 87) * base;
        else if(hex[i]>='A' && hex[i]<='F')
            decimal += (hex[i] - 55) * base;
        else
            return -1;
        base *= 16;
    }

    return decimal;
}

char dec_to_hex(int n)
{
   if(n>=0 && n<=9)
        return n+48;
    else
        return n+55;
}