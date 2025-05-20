//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LEN 8

char decimal_to_hex_digit(int decimal_digit)
{
    if (decimal_digit < 10)
    {
        return (char)(decimal_digit + '0');
    }
    else
    {
        return (char)(decimal_digit - 10 + 'A');
    }
}

void print_hex(int decimal_num)
{
    char hex[MAX_HEX_LEN] = {'\0'};
    int i = 0;

    while (decimal_num != 0 && i < MAX_HEX_LEN)
    {
        int remainder = decimal_num % 16;
        hex[i++] = decimal_to_hex_digit(remainder);
        decimal_num /= 16;
    }

    if (i == 0)
    {
        hex[i++] = '0';
    }

    printf("Hexadecimal Equivalent is : ");

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hex[j]);
    }
}

int main()
{
    int decimal_num;

    printf("Enter decimal number: ");
    scanf("%d", &decimal_num);

    if (decimal_num < 0)
    {
        printf("Negative decimal number is not allowed!\n");
        exit(0);
    }

    print_hex(decimal_num);

    return 0;
}