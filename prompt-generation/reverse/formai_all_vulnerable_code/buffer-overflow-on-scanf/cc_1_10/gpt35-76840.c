//FormAI DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryToDecimal(char *binStr)
{
    int decimal = 0;
    int length = strlen(binStr);
    int power = 1;

    for(int i = length-1; i >= 0; i--)
    {
        if(binStr[i] == '1')
            decimal += power;
        power *= 2;
    }

    return decimal;
}

void decimalToBinary(int decimal)
{
    int binaryArr[100];
    int i = 0;

    while(decimal > 0)
    {
        binaryArr[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("Binary: ");
    for(int j = i-1; j >= 0; j--)
        printf("%d", binaryArr[j]);
    printf("\n");
}

int main()
{
    char binStr[100];
    int decimal;

    printf("Enter a binary number: ");
    scanf("%s", binStr);

    decimal = binaryToDecimal(binStr);
    printf("Decimal: %d\n", decimal);

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}