//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1024];
    int i, j, k, l, n, num, hex_num;
    unsigned int val;
    char hex_char;

    printf("Enter a hexadecimal number: ");
    scanf("%s", str);

    n = strlen(str);

    for (i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'f')
        {
            hex_num = str[i] - 'a' + 10;
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            hex_num = str[i] - 'A' + 10;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            hex_num = str[i] - '0';
        }
        else
        {
            printf("Error: Invalid input.\n");
            exit(1);
        }

        val = val * 16 + hex_num;
    }

    printf("Hexadecimal equivalent: ");
    for (i = 0; i < l; i++)
    {
        hex_char = val & 0xf;
        val >>= 4;
        printf("%x ", hex_char);
    }

    printf("\n");

    return 0;
}