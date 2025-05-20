//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100] = "";
    char output[100] = "";
    int i = 0;
    int j = 0;
    int number = 0;
    int flag = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            number = number * 16 + input[i] - 'a' + 10;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            number = number * 16 + input[i] - 'A' + 10;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            number = number * 16 + input[i] - '0';
        }
        else
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        for (j = 0; number > 0; j++)
        {
            int digit = number % 16;
            output[j] = '0' + digit;
            if (digit < 10)
            {
                output[j] = output[j] - '0' + 'a';
            }
            number /= 16;
        }

        printf("Hexadecimal equivalent: ");
        for (i = j - 1; i >= 0; i--)
        {
            printf("%c ", output[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Invalid input.\n");
    }

    return 0;
}