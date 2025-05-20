//FormAI DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char num[100];
    char bin_num[100];
    int decimal_num = 0;
    int i, j, len;

    printf("Enter a decimal number to convert to binary: ");
    scanf("%s", num);

    len = strlen(num);

    for(i = 0; i < len; i++)
    {
        if(isdigit(num[i]))
        {
            decimal_num = (decimal_num * 10) + (num[i] - '0');
        }
        else
        {
            printf("Invalid Input");
            return 1;
        }
    }

    i = 0;
    while(decimal_num != 0)
    {
        int remainder = decimal_num % 2;
        bin_num[i++] = remainder + '0';
        decimal_num /= 2;
    }
    bin_num[i] = '\0';

    len = strlen(bin_num);
    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        char temp = bin_num[i];
        bin_num[i] = bin_num[j];
        bin_num[j] = temp;
    }

    printf("Binary Number: %s\n", bin_num);

    return 0;
}