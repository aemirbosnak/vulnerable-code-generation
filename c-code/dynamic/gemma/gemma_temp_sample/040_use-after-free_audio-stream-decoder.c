#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer = malloc(1024);
    FILE *fp = fopen("audio.wav", "rb");
    size_t read_size = fread(buffer, 1, 1024, fp);
    fclose(fp);

    unsigned int i = 0;
    for (i = 0; i < read_size; i++)
    {
        printf("%c", buffer[i]);
    }

    free(buffer);
    return 0;
}
