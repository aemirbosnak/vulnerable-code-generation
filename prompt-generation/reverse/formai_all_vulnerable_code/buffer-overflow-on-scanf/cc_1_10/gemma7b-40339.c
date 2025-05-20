//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int num)
{
    int hex_num = num / 16;
    int remainder = num % 16;
    char hex_digit;

    if (hex_num > 0)
    {
        convertToHex(hex_num);
    }

    switch (remainder)
    {
        case 0:
            hex_digit = '0';
            break;
        case 1:
            hex_digit = '1';
            break;
        case 2:
            hex_digit = '2';
            break;
        case 3:
            hex_digit = '3';
            break;
        case 4:
            hex_digit = '4';
            break;
        case 5:
            hex_digit = '5';
            break;
        case 6:
            hex_digit = '6';
            break;
        case 7:
            hex_digit = '7';
            break;
        case 8:
            hex_digit = '8';
            break;
        case 9:
            hex_digit = '9';
            break;
        default:
            hex_digit = 'a' + remainder - 10;
    }

    printf("%c", hex_digit);
}

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    convertToHex(num);

    printf("\nHexadecimal equivalent: ");
    printf("%x", num);

    return 0;
}