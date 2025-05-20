//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    char str[MAX_SIZE];
    int i, len, compress_size, original_size, count = 0;
    char prefix[MAX_SIZE];

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);
    original_size = len;

    for (i = 0; i < len; i++)
    {
        char current_char = str[i];
        int flag = 0;

        for (int j = 0; j < count; j++)
        {
            if (current_char == prefix[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            prefix[count] = current_char;
            count++;
        }
    }

    compress_size = count;
    printf("\nOriginal size: %d", original_size);
    printf("\nCompressed size: %d", compress_size);
    printf("\nCompressed string: ");

    for (i = 0; i < compress_size; i++)
    {
        printf("%c", prefix[i]);
    }

    return 0;
}