//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100] = "";
    char output[100] = "";
    int i = 0;
    int j = 0;
    int k = 0;
    int num = 0;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            num = num * 16 + input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            num = num * 16 + input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = num * 16 + input[i] - '0';
        }
        else
        {
            flag = 1;
            break;
        }

        output[j++] = num / 16 + 'a';
        output[j++] = num % 16 + 'a';
    }

    if (flag)
    {
        printf("Error: Invalid input.\n");
    }
    else
    {
        printf("Hexadecimal conversion: ");
        for (k = 0; output[k] != '\0'; k++)
        {
            printf("%c ", output[k]);
        }
        printf("\n");
    }

    return 0;
}