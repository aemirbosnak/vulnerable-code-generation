//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHex(int num);
int power(int base, int exponent);

int main()
{
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("The hexadecimal conversion of decimal %d is: ", num);
    printHex(num);

    return 0;
}

void printHex(int num)
{
    int hex[20], i = 0, j;
    
    // Converting decimal to hexadecimal
    while (num != 0)
    {
        hex[i] = num % 16;
        num /= 16;
        i++;
    }

    // Printing hexadecimal number
    for (j = i - 1; j >= 0; j--)
    {
        if (hex[j] < 10)
        {
            printf("%d", hex[j]);
        }
        else
        {
            printf("%c", (char)(hex[j] + 55));
        }
    }
}

int power(int base, int exponent)
{
    int result = 1;
    while (exponent != 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}