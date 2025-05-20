#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int i, j, k, l, data, offset;

    fp = fopen("audio.dat", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    offset = 0;
    while ((data = fgetc(fp)) != EOF)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 20; j++)
            {
                l = offset + i * 10 + j * 20;
                if (l < 0 || l > 1024)
                {
                    printf("Out of bounds memory access at address %d\n", l);
                    exit(1);
                }

                // Decode data and play it
                printf("%d ", data);
            }
        }

        offset++;
    }

    fclose(fp);

    return 0;
}
