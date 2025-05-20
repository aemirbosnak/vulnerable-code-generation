//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *input;
    char *output;
    int i, j, k;
    int len, len2;
    int val;

    if (argc != 2)
    {
        printf("Usage: %s <hexadecimal number>\n", argv[0]);
        return 1;
    }

    input = argv[1];
    len = strlen(input);

    output = (char *)malloc(len * 2 + 1);
    if (output == NULL)
    {
        printf("Error: Out of memory\n");
        return 1;
    }

    for (i = 0, j = 0; i < len; i++)
    {
        char c = input[i];

        if (c >= '0' && c <= '9')
        {
            val = c - '0';
        }
        else if (c >= 'a' && c <= 'f')
        {
            val = c - 'a' + 10;
        }
        else if (c >= 'A' && c <= 'F')
        {
            val = c - 'A' + 10;
        }
        else
        {
            printf("Error: Invalid hexadecimal number\n");
            return 1;
        }

        output[j++] = (val >> 4) + '0';
        output[j++] = (val & 0x0f) + '0';
    }

    output[j] = '\0';

    len2 = strlen(output);

    for (k = 0; k < len2 / 2; k++)
    {
        char temp = output[k];
        output[k] = output[len2 - k - 1];
        output[len2 - k - 1] = temp;
    }

    printf("Decimal number: %s\n", output);

    free(output);

    return 0;
}