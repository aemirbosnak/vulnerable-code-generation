//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num[10], binary[100], octal[100], hexadecimal[100];
    int i, j, num_len, base, converted_num, remainder, power = 0;

    printf("Enter a number: ");
    scanf("%s", num);

    num_len = strlen(num);

    // Convert the number to binary
    for (i = num_len - 1; i >= 0; i--)
    {
        converted_num = num[i] - 48;
        remainder = converted_num % 2;
        binary[power] = remainder + 48;
        power++;
    }

    // Print the binary number
    printf("Binary: ");
    for (j = power - 1; j >= 0; j--)
    {
        printf("%c ", binary[j]);
    }

    // Convert the number to octal
    power = 0;
    for (i = num_len - 1; i >= 0; i--)
    {
        converted_num = num[i] - 48;
        remainder = converted_num % 8;
        octal[power] = remainder + 48;
        power++;
    }

    // Print the octal number
    printf("\nOctal: ");
    for (j = power - 1; j >= 0; j--)
    {
        printf("%c ", octal[j]);
    }

    // Convert the number to hexadecimal
    power = 0;
    for (i = num_len - 1; i >= 0; i--)
    {
        converted_num = num[i] - 48;
        remainder = converted_num % 16;
        hexadecimal[power] = remainder + 48;
        power++;
    }

    // Print the hexadecimal number
    printf("\nHexadecimal: ");
    for (j = power - 1; j >= 0; j--)
    {
        printf("%c ", hexadecimal[j]);
    }

    return 0;
}