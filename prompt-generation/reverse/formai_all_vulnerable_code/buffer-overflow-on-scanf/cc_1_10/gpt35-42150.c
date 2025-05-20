//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void decToBin(int decNum);
void binToDec(char binNum[]);

int main()
{
    int choice, dec;
    char bin[20];

    printf("Welcome to the Binary Converter program!\n");
    printf("Choose an option below:\n");
    printf("1. Convert Decimal to Binary\n");
    printf("2. Convert Binary to Decimal\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter a Decimal number: ");
            scanf("%d", &dec);
            decToBin(dec);
            break;

        case 2:
            printf("\nEnter a Binary number: ");
            scanf("%s", bin);
            binToDec(bin);
            break;

        default:
            printf("\nInvalid choice. Program terminated.");
            exit(0);
    }

    return 0;
}

void decToBin(int decNum)
{
    int rem, quot, i = 0;
    int binNum[100];

    quot = decNum;

    while(quot != 0)
    {
        binNum[i] = quot % 2;
        i++;
        quot = quot/2;
    }

    printf("\n%d in Binary is: ", decNum);

    for(int j = i - 1; j >= 0; j--)
    {
        printf("%d", binNum[j]);
    }
}

void binToDec(char binNum[])
{
    int decNum = 0, base = 1;
    int len = strlen(binNum);

    for(int i = len - 1; i >= 0; i--)
    {
        if(binNum[i] == '1')
        {
            decNum += base;
        }
        base *= 2;
    }

    printf("\n%s in Decimal is: %d", binNum, decNum);
}