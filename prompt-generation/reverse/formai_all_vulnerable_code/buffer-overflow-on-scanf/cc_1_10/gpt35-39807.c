//FormAI DATASET v1.0 Category: String manipulation ; Style: interoperable
#include <stdio.h>
#include <string.h>

void reverse(char str[], int len)
{
    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void hexadecimal(int number)
{
    char str[100];
    int rem, i = 0;
    while (number != 0)
    {
        rem = number % 16;
        if (rem < 10)
            str[i++] = 48 + rem;
        else
            str[i++] = 55 + rem;
        number /= 16;
    }
    str[i] = '\0';
    reverse(str, i);
    printf("\nHexadecimal equivalent: %s", str);
}

void octal(int number)
{
    char str[100];
    int rem, i = 0;
    while (number != 0)
    {
        rem = number % 8;
        str[i++] = 48 + rem;
        number /= 8;
    }
    str[i] = '\0';
    reverse(str, i);
    printf("\nOctal equivalent: %s", str);
}

void decimal(char str[])
{
    int len = strlen(str), i, decimal = 0, base = 1;
    for (i = len - 1; i >= 0; i--)
    {
        decimal += (str[i] - 48) * base;
        base *= 10;
    }
    printf("\nDecimal equivalent: %d", decimal);
    hexadecimal(decimal);
    octal(decimal);
}

int main()
{
    char str[100];
    printf("Enter a number in binary: ");
    scanf("%s", str);
    printf("Binary input: %s", str);

    decimal(str);
    return 0;
}