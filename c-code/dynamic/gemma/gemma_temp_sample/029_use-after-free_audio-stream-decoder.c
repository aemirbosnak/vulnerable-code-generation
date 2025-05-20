#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char *buffer;
    long size;

    fp = fopen("audio.bin", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    buffer = malloc(size);

    rewind(fp);
    fread(buffer, 1, size, fp);

    printf("%s", buffer);

    free(buffer);
    fclose(fp);

    return 0;
}
