//FormAI DATASET v1.0 Category: Binary Converter ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DecToBin(unsigned int);
void BinToDec();

int main()
{
    int choice;
    printf("Menu:\n1. Decimal to Binary\n2. Binary to Decimal\nEnter choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1:
        {
            unsigned int dec;
            printf("\nEnter Decimal number: ");
            scanf("%u", &dec);
            DecToBin(dec);
            break;
        }
        case 2:
        {
            BinToDec();
            break;
        }
        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}

void DecToBin(unsigned int dec)
{
    int arr[32], i=0;
    while(dec>0)
    {
        arr[i++] = dec%2;
        dec = dec/2;
    }
    printf("\nBinary Equivalent: ");
    for(int j=i-1;j>=0;j--)
        printf("%d",arr[j]);
    printf("\n");
}

void BinToDec()
{
    char bin[33];
    printf("\nEnter Binary number: ");
    scanf("%s", bin);
    unsigned int dec = 0, base = 1;
    int len = strlen(bin);
    for(int i=len-1;i>=0;i--)
    {
        if(bin[i] == '1')
            dec += base;
        base *= 2;
    }
    printf("\nDecimal Equivalent: %u\n",dec);
}