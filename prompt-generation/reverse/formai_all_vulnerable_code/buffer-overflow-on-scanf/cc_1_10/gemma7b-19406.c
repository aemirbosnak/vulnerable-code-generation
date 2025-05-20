//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1024] = "";
    char output[1024] = "";
    int i = 0;
    int j = 0;
    int flag = 0;
    int num = 0;
    int offset = 0;
    char mask = 0x0F;

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

        offset = (i - j) * 2;
        output[offset] = (num & mask) | 0x30;
        j++;
    }

    if (flag == 0)
    {
        printf("Hexadecimal conversion: ");
        printf("%s", output);
    }
    else
    {
        printf("Error: invalid input");
    }

    return 0;
}