//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10

int main()
{
    char input[MAX_DIGITS];
    int i, num, base, converted_num, remainder;

    printf("Enter a binary number: ");
    scanf("%s", input);

    // Validate input
    if (input[0] == '0' && input[1] == '\0')
    {
        printf("Invalid input. Please enter a non-zero number.\n");
        return 1;
    }

    // Get the number of digits in the input
    num = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        num++;
    }

    // Convert the input to an integer
    converted_num = 0;
    for (i = num - 1; i >= 0; i--)
    {
        remainder = input[i] - '0';
        converted_num += remainder * pow(2, num - 1 - i);
    }

    // Convert the integer to a decimal number
    base = 10;
    int decimal_num = converted_num;
    int decimal_digits = 0;
    while (decimal_num / base)
    {
        int digit = decimal_num % base;
        decimal_num /= base;
        decimal_digits++;
        printf("%d ", digit);
    }

    printf("\nThe decimal equivalent of the binary number is: ");
    for (i = decimal_digits - 1; i >= 0; i--)
    {
        printf("%d ", decimal_num % base);
        decimal_num /= base;
    }

    return 0;
}