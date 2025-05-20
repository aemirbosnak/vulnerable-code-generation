#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = NULL;
    int size = 0;

    FILE *file = fopen("audio.wav", "r");
    if (file == NULL)
    {
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    size = fread(buffer, 1, 1024, file);

    // Out-of-bounds read
    buffer[size] = 0xdeadbeef;

    fclose(file);

    return 0;
}
