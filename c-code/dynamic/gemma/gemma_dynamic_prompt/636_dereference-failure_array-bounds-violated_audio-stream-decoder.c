#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, size = 1024;
    char *buffer = (char *)malloc(size);

    // Read data from stream
    FILE *fp = fopen("stream.bin", "rb");
    fread(buffer, size, 1, fp);

    // Decode audio data
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < 3; j++)
        {
            // Array bounds violation
            buffer[i] = buffer[i] + buffer[j];
        }
    }

    // Play audio data
    printf("%s", buffer);
    free(buffer);
    fclose(fp);

    return 0;
}
