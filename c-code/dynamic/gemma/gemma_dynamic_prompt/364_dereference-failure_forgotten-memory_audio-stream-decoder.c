#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp = fopen("audio.bin", "rb");
    if (fp == NULL)
    {
        return 1;
    }

    char* data = NULL;
    size_t size = 0;

    while (!feof(fp))
    {
        data = realloc(data, size + 1);
        size++;

        unsigned char byte = fgetc(fp);
        data[size - 1] = byte;
    }

    fclose(fp);

    printf("%s", data);

    return 0;
}
