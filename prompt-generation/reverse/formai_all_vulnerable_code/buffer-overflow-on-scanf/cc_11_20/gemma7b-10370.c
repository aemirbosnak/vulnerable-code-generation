//Gemma-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char output[200];
    int i, j, k, l, n, count = 0;
    printf("Enter hexadecimal number: ");
    scanf("%s", input);

    n = strlen(input);
    for (i = 0; i < n; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'f')
        {
            count++;
        }
    }

    if (count == 0)
    {
        printf("Invalid input. Please enter a valid hexadecimal number.\n");
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            if (input[i] >= 'a' && input[i] <= 'f')
            {
                input[i] -= 32;
            }
        }

        l = 0;
        for (i = 0; i < n; i++)
        {
            if (input[i] >= 'A' && input[i] <= 'F')
            {
                output[l] = input[i] - 'A' + 10;
                l++;
            }
            else
            {
                output[l] = input[i] - '0' + 0;
                l++;
            }
        }

        output[l] = '\0';

        printf("Converted hexadecimal number: %s\n", output);
    }

    return 0;
}