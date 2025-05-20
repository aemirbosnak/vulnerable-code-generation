//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char input[1024];
    int i, j, k, num, flag = 0, count = 0;
    printf("Shocked C Hexadecimal Converter!\n");
    printf("-----------------------\n");
    printf("Enter a hexadecimal number: ");

    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            num = input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            num = input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = input[i] - '0';
        }
        else
        {
            flag = 1;
            break;
        }

        count++;
        k = num << (count - 1) * 4;
        printf("%x ", k);
    }

    if (flag)
    {
        printf("\nError: Invalid input.\n");
    }
    else
    {
        printf("\nConverted hexadecimal number: ");
        for (i = 0; i < count; i++)
        {
            printf("%x ", k);
        }
    }

    printf("\nShocked and amazed?\n");
    printf("-----------------------\n");
    return;
}