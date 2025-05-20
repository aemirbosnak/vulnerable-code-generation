//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char byte;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <device filename> <output filename>\n", argv[0]);
        exit(1);
    }

    FILE *device = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");

    if (device == NULL)
    {
        printf("Unable to open device file.\n");
        exit(1);
    }

    if (output == NULL)
    {
        printf("Unable to create output file.\n");
        exit(1);
    }

    int block_num = 0;
    byte block[BLOCK_SIZE];
    while (fread(block, sizeof(byte), BLOCK_SIZE, device) == BLOCK_SIZE)
    {
        block_num++;

        // Check for a JPEG header
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            char filename[10];
            sprintf(filename, "%03i.jpg", block_num);
            FILE *jpg = fopen(filename, "wb");
            if (jpg == NULL)
            {
                printf("Unable to create JPEG file.\n");
                exit(1);
            }

            fwrite(block, sizeof(byte), BLOCK_SIZE, jpg);
            while (fread(block, sizeof(byte), BLOCK_SIZE, device) == BLOCK_SIZE)
            {
                fwrite(block, sizeof(byte), BLOCK_SIZE, jpg);
                if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
                {
                    fclose(jpg);
                    break;
                }
            }
        }
    }

    fclose(device);
    fclose(output);

    return 0;
}