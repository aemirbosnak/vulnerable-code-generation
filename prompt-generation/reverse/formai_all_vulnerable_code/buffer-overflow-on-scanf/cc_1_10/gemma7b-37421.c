//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[10];
    int i, num, oct, dec, hex;
    printf("Enter a number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        num = input[i] - '0';
        oct = num / 8;
        dec = num % 8;
        hex = num / 16;
        switch (num % 16)
        {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", num % 16);
                break;
        }

        if (hex)
        {
            printf("0x");
        }

        if (oct)
        {
            printf("0");
        }

        printf(",");
    }

    printf("\n");

    return 0;
}