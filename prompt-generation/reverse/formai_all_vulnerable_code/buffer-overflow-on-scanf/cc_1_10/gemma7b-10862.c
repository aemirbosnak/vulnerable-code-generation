//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1024] = "";
    char output[1024] = "";
    int i = 0;
    int j = 0;
    int k = 0;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            output[j++] = input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            output[j++] = input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            flag = 1;
            output[j++] = input[i] - '0';
        }
    }

    if (flag == 0)
    {
        printf("Invalid input.\n");
    }
    else
    {
        printf("Hexadecimal equivalent: ");
        for (k = 0; output[k] != '\0'; k++)
        {
            printf("%x ", output[k]);
        }
        printf("\n");
    }

    return 0;
}