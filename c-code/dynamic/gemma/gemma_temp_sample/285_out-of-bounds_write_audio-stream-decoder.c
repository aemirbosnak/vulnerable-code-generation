#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    FILE *file = fopen("audio.wav", "r");

    // Read the file and write it to the buffer, out of bounds
    fread(buffer, 1, 1024 * 2, file);
    buffer[1024] = 'A';

    fclose(file);
    free(buffer);

    return 0;
}
