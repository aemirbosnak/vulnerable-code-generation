//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* HexToBinary(char hex); //Prototype
int BinaryToDecimal(char *binary); //Prototype

void main()
{
    char hexNum[100];
    printf("Enter a hexadecimal number: ");
    gets(hexNum);
    int len = strlen(hexNum), i, decNum = 0;
    for(i = 0; i < len; i++)
    {
        if(hexNum[i] == ' ')
        {
            continue;
        }
        char *binary = HexToBinary(hexNum[i]);
        decNum += BinaryToDecimal(binary);
        free(binary);
    }
    printf("Decimal number of %s is %d", hexNum, decNum);
}

char* HexToBinary(char hex)
{
    char *binary = (char*)malloc(5 * sizeof(char)); //5 bits of binary can represent 16 hex digits
    int i = 0, decimal = 0;
    for(i = 0; i < 5; i++)
    {
        binary[i] = '0';
    }
    if(isdigit(hex))
    {
        decimal = hex - '0';
    }
    else
    {
        switch(hex)
        {
            case 'A':
            case 'a':
                decimal = 10;
                break;
            case 'B':
            case 'b':
                decimal = 11;
                break;
            case 'C':
            case 'c':
                decimal = 12;
                break;
            case 'D':
            case 'd':
                decimal = 13;
                break;
            case 'E':
            case 'e':
                decimal = 14;
                break;
            case 'F':
            case 'f':
                decimal = 15;
                break;
            default:
                printf("Invalid hexadecimal input");
                exit(0);
        }
    }
    i = 0;
    while(decimal > 0)
    {
        binary[4 - i] = decimal % 2 + '0';
        decimal /= 2;
        i++;
    }
    return binary;
}

int BinaryToDecimal(char *binary)
{
    int decimal = 0, i, j = strlen(binary) - 1;
    for(i = 0; i < strlen(binary); i++)
    {
        decimal += (binary[i] - '0') * pow(2, j);
        j--;
    }
    return decimal;
}