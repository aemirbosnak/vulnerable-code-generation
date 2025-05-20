//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "This is a sample string to be compressed";
    int len = strlen(str);
    int i, j, count = 0, flag = 0, prev = 0, compress_len = 0;
    char compress_str[len];

    for (i = 0; i < len; i++)
    {
        count = 0;
        for (j = i; j < len && str[j] == str[i]; j++)
        {
            count++;
        }

        if (count > 1)
        {
            flag = 1;
            compress_str[compress_len++] = str[i];
            compress_str[compress_len++] = count - 1 + 'a';
        }
        else
        {
            compress_str[compress_len++] = str[i];
        }

        prev = count;
    }

    if (flag)
    {
        printf("Compressed string: ");
        for (i = 0; i < compress_len; i++)
        {
            printf("%c", compress_str[i]);
        }

        printf("\n");
    }
    else
    {
        printf("The string does not need compression.\n");
    }

    return 0;
}