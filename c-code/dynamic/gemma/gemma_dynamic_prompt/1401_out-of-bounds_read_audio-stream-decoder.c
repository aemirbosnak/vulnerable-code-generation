#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("/path/to/audio.wav", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    unsigned char *buffer = malloc(1024);
    if (buffer == NULL)
    {
        perror("Error allocating memory");
        fclose(fp);
        return 1;
    }

    // Out-of-bounds read vulnerability
    size_t read_size = fread(buffer, 1, 1024 * 2, fp);

    fclose(fp);
    free(buffer);

    return 0;
}
