//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    int i, num, count = 0, flag = 0;
    printf("Enter a hexadecimal number: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'f')
        {
            num = str[i] - 'a' + 10;
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            num = str[i] - 'A' + 10;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            num = str[i] - '0';
        }
        else
        {
            flag = 1;
            break;
        }

        count++;
        num = num * pow(16, count - 1);
        printf("%d ", num);
    }

    if (flag)
    {
        printf("Error: Invalid input.\n");
    }
    else
    {
        printf("\nThe hexadecimal number is: ");
        for (i = 0; str[i] != '\0'; i++)
        {
            printf("%c ", str[i]);
        }
        printf("\n");
    }

    return 0;
}