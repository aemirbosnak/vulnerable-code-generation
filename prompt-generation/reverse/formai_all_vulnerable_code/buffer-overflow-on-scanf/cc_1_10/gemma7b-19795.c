//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, l, n, m, flag = 0, compression_ratio = 0;

    printf("Enter a string: ");
    scanf("%s", buffer);

    n = strlen(buffer);
    m = n / 2;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (buffer[i] == buffer[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            for (k = l; k < n; k++)
            {
                if (buffer[k] == buffer[i])
                {
                    buffer[k] = '\0';
                    n--;
                    break;
                }
            }

            compression_ratio++;
        }

        flag = 0;
    }

    printf("Compressed string: %s", buffer);
    printf("\nCompression ratio: %d%%", compression_ratio);

    return 0;
}