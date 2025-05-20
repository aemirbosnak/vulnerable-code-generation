//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char str[100];
    int i, n, num, hex_num, count = 0, flag = 0;

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
            flag = 1;
            break;
        }

        num = num * 16 + hex_num;
        count++;

        if (count % 4 == 0)
        {
            printf("%x ", num);
        }
    }

    if (flag)
    {
        printf("Error: Invalid input.\n");
    }
    else
    {
        printf("\n");
    }

    return;
}