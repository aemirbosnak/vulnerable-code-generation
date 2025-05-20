#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file = fopen("audio.wav", "rb");
    unsigned char* data = (unsigned char*)malloc(1024);
    unsigned int size = fread(data, 1, 1024, file);
    unsigned int offset = 1024;
    while (size > 0)
    {
        unsigned int read_size = fread(data, 1, offset, file);
        printf("%s", data);
        size -= read_size;
        offset += read_size;
    }
    fclose(file);
    free(data);
    return 0;
}
