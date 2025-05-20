#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("audio.wav", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    unsigned char *buffer = malloc(1024);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        return 1;
    }

    size_t read_size = fread(buffer, 1, 1024, fp);
    if (read_size != 1024)
    {
        perror("Error reading file");
        return 1;
    }

    free(buffer);
    fclose(fp);

    return 0;
}
