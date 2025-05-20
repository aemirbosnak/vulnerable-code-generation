//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    char hexadecimal[1000];
    int decimal = 0;
    int length = 0;
    int i;
    bool is_hexadecimal = true;
    printf("Enter a hexadecimal number: ");
    fgets(hexadecimal, 1000, stdin);
    length = strlen(hexadecimal);
    for (i = 0; i < length; i++)
    {
        if (!is_hexadecimal)
        {
            printf("Invalid input.\n");
            return 1;
        }
        switch (hexadecimal[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                break;
            default:
                is_hexadecimal = false;
                break;
        }
        if (!is_hexadecimal)
        {
            printf("Invalid input.\n");
            return 1;
        }
    }
    for (i = 0; i < length; i++)
    {
        if (isdigit(hexadecimal[i]))
        {
            decimal = decimal * 16 + hexadecimal[i] - '0';
        }
        else
        {
            decimal = decimal * 16 + hexadecimal[i] - 'A' + 10;
        }
    }
    printf("Decimal equivalent: %d\n", decimal);
    return 0;
}