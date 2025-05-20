//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[256];
    char output[256];
    int i, j, k, l, n, count = 0, flag = 0, is_negative = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    n = strlen(input);

    for (i = 0; i < n; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            output[count] = input[i] - 'a' + 10;
            count++;
        }
        else if (input[i] >= 'A' && input[i] <= 'F')
        {
            output[count] = input[i] - 'A' + 10;
            count++;
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            output[count] = input[i] - '0';
            count++;
        }
    }

    if (count == 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (input[0] == '-')
    {
        is_negative = 1;
        output[0] = '0';
    }

    l = count - 1;

    for (i = 0; i < l; i++)
    {
        j = output[i] / 16;
        k = output[i] % 16;
        output[i] = '0' + k;
        if (j)
        {
            output[i - 1] = '0' + j;
        }
    }

    printf("Hexadecimal equivalent: ");

    for (i = 0; i < count; i++)
    {
        printf("%c ", output[i]);
    }

    printf("\n");

    if (is_negative)
    {
        printf("Negative number: ");
        printf("%c ", output[0]);
        for (i = 1; i < count; i++)
        {
            printf("%c ", output[i]);
        }

        printf("\n");
    }

    return 0;
}