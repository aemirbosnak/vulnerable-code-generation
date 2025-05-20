//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LENGTH 1000

char hexadecimal[MAX_LENGTH];
char binary[MAX_LENGTH];
char decimal[MAX_LENGTH];
int length, i, j, k;

void hexadecimalToBinary(char hex[])
{
    int decimalValue;
    for(i=0; hex[i]!='\0'; i++)
    {
        if(isdigit(hex[i]))
        {
            decimalValue = hex[i] - '0';
        }
        else if(isupper(hex[i]))
        {
            decimalValue = hex[i] - 'A' + 10;
        }
        else if(islower(hex[i]))
        {
            decimalValue = hex[i] - 'a' + 10;
        }
        else
        {
            printf("\nError: Invalid hexadecimal character found.\n");
            exit(0);
        }
        binary[i] = decimalValue & 0x00000001;
        decimalValue >>= 1;
    }
    binary[i] = '\0';
}

void binaryToDecimal(char binary[])
{
    int decimalValue = 0;
    int power = 0;
    for(i=strlen(binary)-1; i>=0; i--)
    {
        if(binary[i] == '1')
        {
            decimalValue += pow(2, power);
        }
        power++;
    }
    sprintf(decimal, "%d", decimalValue);
}

int main()
{
    printf("\nEnter a hexadecimal number: ");
    scanf("%s", hexadecimal);
    length = strlen(hexadecimal);
    if(length > MAX_LENGTH)
    {
        printf("\nError: Input string too long.\n");
        exit(0);
    }
    for(i=0; i<length; i++)
    {
        if(!isxdigit(hexadecimal[i]))
        {
            printf("\nError: Invalid hexadecimal character found.\n");
            exit(0);
        }
    }
    hexadecimalToBinary(hexadecimal);
    binaryToDecimal(binary);
    printf("\nBinary equivalent: %s", binary);
    printf("\nDecimal equivalent: %s", decimal);
    return 0;
}