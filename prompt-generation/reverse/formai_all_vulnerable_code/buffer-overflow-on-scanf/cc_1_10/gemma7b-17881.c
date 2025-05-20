//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shocked
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100];
    int i, j, num, len, flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    len = strlen(input);

    for (i = 0; i < len; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            flag = 1;
            num = input[i] - 'a' + 10;
            output[j] = num + 48;
            j++;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            flag = 1;
            num = input[i] - 'A' + 10;
            output[j] = num + 48;
            j++;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            flag = 1;
            num = input[i] - '0';
            output[j] = num + 48;
            j++;
        }
    }

    if (flag == 0)
    {
        printf("Invalid input\n");
    }
    else
    {
        output[j] = '\0';
        printf("Hexadecimal equivalent: %s\n", output);
    }

    return 0;
}