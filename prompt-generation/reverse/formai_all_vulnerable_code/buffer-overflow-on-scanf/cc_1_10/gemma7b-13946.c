//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void convertToHex(int num)
{
    int quotient, remainder, i = 0, hex_array[10];

    quotient = num / 16;
    remainder = num % 16;
    hex_array[i++] = quotient;
    hex_array[i++] = remainder;

    for (i = 0; hex_array[i] != 0; i++)
    {
        switch (hex_array[i])
        {
            case 0:
                printf("0");
                break;
            case 1:
                printf("1");
                break;
            case 2:
                printf("2");
                break;
            case 3:
                printf("3");
                break;
            case 4:
                printf("4");
                break;
            case 5:
                printf("5");
                break;
            case 6:
                printf("6");
                break;
            case 7:
                printf("7");
                break;
            case 8:
                printf("8");
                break;
            case 9:
                printf("9");
                break;
            default:
                printf("Error");
                break;
        }
        printf("%c ", ' ');
    }

    printf("\n");
}

int main()
{
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    convertToHex(num);

    return 0;
}