//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

#define ENCRYPT 1
#define DECRYPT 0

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s [encrypt|decrypt] [key] [input file] [output file]\n", argv[0]);
        return 1;
    }

    int mode = !strcmp(argv[1], "encrypt") ? ENCRYPT : DECRYPT;

    byte key[16];
    if (strlen(argv[2]) != 16)
    {
        printf("Error: Key must be 16 characters long.\n");
        return 1;
    }
    memcpy(key, argv[2], 16);

    FILE *input = fopen(argv[3], "rb");
    if (input == NULL)
    {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[4], "wb");
    if (output == NULL)
    {
        printf("Error: Unable to open output file.\n");
        return 1;
    }

    byte buffer[1024];
    int num_read;

    while ((num_read = fread(buffer, 1, sizeof(buffer), input)) > 0)
    {
        if (mode == ENCRYPT)
        {
            for (int i = 0; i < num_read; i++)
            {
                buffer[i] ^= key[i % 16];
            }
        }
        else if (mode == DECRYPT)
        {
            for (int i = 0; i < num_read; i++)
            {
                buffer[i] ^= key[(i + 15) % 16];
            }
        }

        fwrite(buffer, 1, num_read, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}