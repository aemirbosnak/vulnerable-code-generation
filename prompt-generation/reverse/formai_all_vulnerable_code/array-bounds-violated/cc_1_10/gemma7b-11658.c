//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];
    char output[20];
    int i, j, k, num, flag = 0;

    printf("Welcome to the Crazy Hexadecimal Converter!\n");
    printf("Please enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            num = input[i] - 'a' + 10;
            output[k] = num + 0x30;
            k++;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            num = input[i] - 'A' + 10;
            output[k] = num + 0x30;
            k++;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            flag = 1;
            num = input[i] - '0';
            output[k] = num + 0x30;
            k++;
        }
    }

    if (flag == 0)
    {
        printf("Invalid input.\n");
    }
    else
    {
        output[k] = '\0';
        printf("The hexadecimal number is: %s\n", output);
    }

    return 0;
}