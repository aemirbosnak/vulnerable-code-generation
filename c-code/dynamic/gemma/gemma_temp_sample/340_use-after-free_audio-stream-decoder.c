#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("audio.bin", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int size = 0;
    long pos = 0;
    char *buffer = NULL;

    while (!feof(fp))
    {
        size = fread(buffer, 1, 1024, fp);
        if (size > 0)
        {
            buffer = realloc(buffer, size * 2);
            pos += size;
            fwrite(buffer, 1, size, stdout);
        }
    }

    fclose(fp);
    free(buffer);

    return 0;
}
