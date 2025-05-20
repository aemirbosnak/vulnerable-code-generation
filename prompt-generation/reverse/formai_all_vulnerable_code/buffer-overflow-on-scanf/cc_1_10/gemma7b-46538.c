//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100] = "";
    char output[100] = "";
    int i = 0;
    int j = 0;
    int num = 0;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            num = input[i] - 'a' + 10;
            output[j++] = num + 16;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            num = input[i] - 'A' + 10;
            output[j++] = num + 16;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            num = input[i] - '0';
            output[j++] = num;
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        output[j] = '\0';
        printf("Hexadecimal equivalent: %s\n", output);
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}