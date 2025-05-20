#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    FILE *fp = fopen("audio.dat", "rb");
    unsigned char buffer[1024];

    while (!feof(fp))
    {
        size_t read_size = fread(buffer, 1, 1024, fp);
        for (i = 0; i < read_size; i++)
        {
            buffer[i] = buffer[i] * 2;
        }
        fwrite(buffer, 1, read_size, stdout);
    }

    fclose(fp);
    return 0;
}
